/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products. No
* other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. TO THE MAXIMUM
* EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES
* SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS
* SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of
* this software. By using this software, you agree to the additional terms and conditions found by accessing the
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2017 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

#include "usb_monitor_thread.h"
#include "utility.h"
#include "../synergy/sf_ctsu_comm/src/framework/deps/r_serial_control.h"
#include "math.h"

#define SOLENOID_CLOSING_TIME           (10u)
#define MIN_AVERAGE_NW                  (500u)
#define SOLENOID_OPENING_TIME           (10u)
#define NOISE_SAFETY_MARGIN_TO_CLOSE    (6u)
#define NOISE_SAFETY_MARGIN_TO_OPEN     (6u)
#define HAND_DETECTION_TIME             (0u)
#define NO_HAND_DETECTION_TIME          (5u)
#define TIME_DELAY_COLLECT_WNH          (5u)

static ULONG events_got = 0;  /* Events retrieved */
static timer_callback_args_t timer_callback_args;

static void handle_timer(void); /* provide indication of calibration finish and heart beat */
static void vStartAGT(void); /* start AGT timer */

extern MYDATA mydata;

void fsm_startup(void);
void fsm_collect_nwnh_samples(void);
void fsm_opening_solenoid(void);
void fsm_collect_wnh_samples(void);
void fsm_closing_solenoid(void);
void fsm_faucet_opening (void);
void fsm_faucet_opened (void);
void fsm_faucet_closed(void);
void fsm_faucet_closing (void);

void turn_on_17_io(void);
void turn_on_15_io(void);
void turn_on_13_io(void);
void turn_off_17_io(void);
void turn_off_15_io(void);
void turn_off_13_io(void);
void turn_on_solenoid (void);
void turn_off_solenoid(void);

//NOTE: NW - No Water; NH - No hands close by
//      W - water running; H - hand close by
enum RAW_DATA_FSM
{
   STARTUP = 0,
   COLLECT_NWNH_SAMPLES,
   OPENING_SOLENOID,
   COLLECT_WNH_SAMPLES,
   CLOSING_SOLENOID,
   FAUCET_CLOSED,
   FAUCET_OPENING,
   FAUCET_OPENED,
   FAUCET_CLOSING,
}RAW_DATA_FSM;

#define FSM_ARRAY_SIZE  (1024)
enum RAW_DATA_FSM rawFsm;

void checkRawData(void);
void processRawData_FSM(void);
void calculateAverageVariance (void);

enum RAW_DATA_FSM rawFsmArray[FSM_ARRAY_SIZE];

void incrementFsmArray(enum RAW_DATA_FSM state);



/* agt timer callback */
void agt_cb(timer_callback_args_t * p_args)
{
    timer_callback_args = *p_args;
    tx_event_flags_set(&g_s3a7_st_flags, TIMER_EVENT, TX_OR);
}

void turn_on_17_io(void)
  {
       g_ioport.p_api->pinWrite(IOPORT_PORT_01_PIN_07, IOPORT_LEVEL_HIGH);
  }

void turn_on_15_io(void)
  {
       g_ioport.p_api->pinWrite(IOPORT_PORT_01_PIN_05, IOPORT_LEVEL_HIGH);
  }

void turn_on_13_io(void)
  {
       g_ioport.p_api->pinWrite(IOPORT_PORT_01_PIN_03, IOPORT_LEVEL_HIGH);
  }

void turn_off_17_io(void)
  {
       g_ioport.p_api->pinWrite(IOPORT_PORT_01_PIN_07, IOPORT_LEVEL_LOW);
  }

void turn_off_15_io(void)
  {
       g_ioport.p_api->pinWrite(IOPORT_PORT_01_PIN_05, IOPORT_LEVEL_LOW);
  }

void turn_off_13_io(void)
  {
       g_ioport.p_api->pinWrite(IOPORT_PORT_01_PIN_03, IOPORT_LEVEL_LOW);
  }

void turn_on_solenoid (void)
{
    turn_on_17_io();
    turn_on_15_io();
    turn_on_13_io();
}

void turn_off_solenoid (void)
{
    turn_off_17_io();
    turn_off_15_io();
    turn_off_13_io();
}

/* turn on red led */
 static void turn_on_red_led()
  {
       g_ioport.p_api->pinWrite(IOPORT_PORT_09_PIN_00, IOPORT_LEVEL_HIGH);   /* red LED1 */
  }
  /* turn on yellow led */
static void turn_on_yellow_led()
  {
      g_ioport.p_api->pinWrite(IOPORT_PORT_09_PIN_01, IOPORT_LEVEL_HIGH);   /* yellow LED2 */
  }

/* turn on the green led */
 static void turn_on_green_led(void)
  {
      g_ioport.p_api->pinWrite(IOPORT_PORT_09_PIN_02, IOPORT_LEVEL_HIGH);   /* green LED3 */
  }

 /* turn off red led */
 static void turn_off_red_led()
  {
       g_ioport.p_api->pinWrite(IOPORT_PORT_09_PIN_00, IOPORT_LEVEL_LOW);   /* red LED1 */
  }
  /* turn off yellow led */
static void turn_off_yellow_led()
  {
      g_ioport.p_api->pinWrite(IOPORT_PORT_09_PIN_01, IOPORT_LEVEL_LOW);   /* yellow LED2 */
  }

/* turn off the green led */
 static void turn_off_green_led(void)
  {
      g_ioport.p_api->pinWrite(IOPORT_PORT_09_PIN_02, IOPORT_LEVEL_LOW);   /* green LED3 */
  }

/* start AGT timer */
static void vStartAGT(void) {
    ssp_err_t ssp_err = SSP_SUCCESS;
    // Open AGT timer
    ssp_err = g_timer0.p_api->open(g_timer0.p_ctrl, g_timer0.p_cfg);
    APP_ERR_TRAP(ssp_err);

    //config the AGT timer
    ssp_err = g_timer0.p_api->start(g_timer0.p_ctrl);
    APP_ERR_TRAP(ssp_err);
}
/* provide indication of calibration finish, auto tune failure and heart beat */
static void handle_timer(void)
{
    static int LEDState = 0;    /*track led on off state*/
    static int count = 0;   /* led blinking counter at start up*/

    switch (timer_callback_args.event)
    {
        case TIMER_EVENT_EXPIRED:
            if (count<10)   /*calibration done */
            {
                count++;
                if(LEDState==0)
               {
//                    turn_on_red_led();
//                    turn_on_yellow_led();
//                   turn_on_green_led();
                   LEDState=1;
                  }
               else
               {
//                   turn_off_red_led();
//                  turn_off_yellow_led();
//                  turn_off_green_led();
                  LEDState=0;

               }
           }
            else
            {
                if(LEDState==0)
                {
                    if(Blink_Red_Led)
                    {
//                       turn_on_red_led();  /* calibration fail */
                    }
                    else
                    {
 //                       turn_on_green_led();    /*heart beat*/
                    }
                    LEDState=1;
                }
                else
                {
                    if(Blink_Red_Led)
                    {
//                        turn_off_red_led();
                    }
                    else
                    {
//                        turn_off_green_led();
                    }

                    LEDState=0;
                }
            }
            break;

        default:
            break;
    }
}

void incrementFsmArray(enum RAW_DATA_FSM state)
{
    static uint16_t i = 0u;
    static bool f_start = false;

    if (i == FSM_ARRAY_SIZE)
    {
        i = 0;
    }

    if (rawFsmArray[i] != state)
    {
        if (f_start == false)
        {
            f_start = true;
        }
        else
        {
            i++;
        }
        rawFsmArray[i] = state;
        turn_off_green_led();
        turn_off_yellow_led();
        turn_off_red_led();
    }
}

void fsm_startup(void)
{
    static uint16_t timer = SOLENOID_CLOSING_TIME * 3;


    if (timer)
    {
        timer--;
        //Here insert function to close solenoid

    }
    else
    {
        rawFsm = COLLECT_NWNH_SAMPLES;
        timer = SOLENOID_CLOSING_TIME * 3;
    }
}

void fsm_collect_nwnh_samples(void)
{
    if (mydata.f_buffer_loaded == true)         //If already loaded a full buffer of samples
    {
        mydata.average2_nw = mydata.sum/MYDATA_SIZE;                    //square the average to use variance instead of standard deviation
        //mydata.average2_nw = mydata.average2_nw * mydata.average2_nw;
        mydata.variance_nw = (mydata.sumOfSquares - (mydata.sumSquared/MYDATA_SIZE))/(MYDATA_SIZE - 1);
        mydata.stdev_nw = (uint32_t)sqrt(mydata.variance_nw);
        if (mydata.average2_nw > MIN_AVERAGE_NW)                        //If larger than minimum (to prevent short circuited sensor)
        {
            rawFsm = OPENING_SOLENOID;                                   //Go to the next state
        }
        else
        {
            rawFsm = STARTUP;                                           //Otherwise start all over again
        }
    }
}

void fsm_opening_solenoid(void)
{
    static uint16_t timer = SOLENOID_OPENING_TIME * 4;

    if (timer)
    {
        timer--;
        //Here insert function to open solenoid

    }
    else
    {
        rawFsm = COLLECT_WNH_SAMPLES;
        //mydata.f_buffer_loaded = false;
        timer = SOLENOID_OPENING_TIME * 4;
    }
}

void fsm_collect_wnh_samples(void)
{
    static uint16_t timer = TIME_DELAY_COLLECT_WNH;


    if (mydata.f_buffer_loaded == true)         //If already loaded a full buffer of samples
    {
        if (timer)                              //And the minimum time has NOT expired
        {
            timer--;
        }
        else
        {
            mydata.average2_w = mydata.sum/MYDATA_SIZE;                    //square the average to use variance instead of standard deviation
            //mydata.average2_w = mydata.average2_w * mydata.average2_w;
            mydata.variance_w = (mydata.sumOfSquares - (mydata.sumSquared/MYDATA_SIZE))/(MYDATA_SIZE - 1);
            mydata.stdev_w = (uint32_t)sqrt(mydata.variance_w);
            if ((mydata.average2_nw + (NOISE_SAFETY_MARGIN_TO_CLOSE * mydata.stdev_nw)) < mydata.average2_w)
            {
                timer = 0;
                rawFsm = CLOSING_SOLENOID;
            }
            else
            {
                timer = 0;
                rawFsm = STARTUP;                                           //Otherwise start all over again
            }
        }
    }
}

void fsm_closing_solenoid(void)
{
    static uint16_t timer = SOLENOID_CLOSING_TIME * 3;

    if (timer)
    {
        timer--;
        //Here insert function to close solenoid


    }
    else
    {
        rawFsm = FAUCET_CLOSED;                         //Put the FSM in normal operation
        //mydata.f_buffer_loaded = false;
        timer = SOLENOID_CLOSING_TIME;
    }
}

void calculateAverageVariance (void)
{
    mydata.average2 = mydata.sum/MYDATA_SIZE;                    //square the average to use variance instead of standard deviation
    //mydata.average2 = mydata.average2 * mydata.average2;
    mydata.variance = (mydata.sumOfSquares - (mydata.sumSquared/MYDATA_SIZE))/(MYDATA_SIZE - 1);
    mydata.stdev = (uint32_t)sqrt(mydata.variance);
}


void fsm_faucet_closed(void)
{
    static uint16_t timer = 0;

    if (mydata.f_buffer_loaded == true)         //If already loaded a full buffer of samples
    {
        calculateAverageVariance();
        if (mydata.average2 > (mydata.average2_nw + (NOISE_SAFETY_MARGIN_TO_OPEN * mydata.stdev_nw)))
        {
            if (timer < HAND_DETECTION_TIME)
            {
                timer++;


            }
            else
            {
                timer = 0;
                rawFsm = FAUCET_OPENING;                         //Put the FSM in normal operation
            }
        }
        else
        {
            if (timer > 0)
            {
                timer--;
            }
        }
    }
}

void fsm_faucet_opening (void)
{
    static uint16_t timer = SOLENOID_OPENING_TIME;

    if (timer)
    {
        timer--;
        //Here insert function to open solenoid

    }
    else
    {
        rawFsm = FAUCET_OPENED;                         //Put the FSM in normal operation
        //mydata.f_buffer_loaded = false;
        timer = SOLENOID_OPENING_TIME;
    }
}

void fsm_faucet_closing (void)
{
    static uint16_t timer = SOLENOID_CLOSING_TIME;

    calculateAverageVariance();
    if (mydata.average2 < (mydata.average2_nw + ((NOISE_SAFETY_MARGIN_TO_OPEN - 3) * mydata.stdev_nw)))
    {
        rawFsm = FAUCET_CLOSED;                         //Put the FSM in normal operation
    }
//    if (timer)
//    {
//        timer--;
//        //Here insert function to open solenoid
//
//    }
//    else
//    {
//        timer = SOLENOID_CLOSING_TIME;
//        rawFsm = FAUCET_CLOSED;                         //Put the FSM in normal operation
//        //mydata.f_buffer_loaded = false;
//    }
}

void fsm_faucet_opened (void)
{
    static uint16_t timer = 0;
    calculateAverageVariance();

    if (mydata.average2 < (mydata.average2_w + (NOISE_SAFETY_MARGIN_TO_CLOSE * mydata.stdev_w)))
    {
        if (timer < NO_HAND_DETECTION_TIME)
        {
            timer++;
        }
        else
        {
            timer = 0;
            rawFsm = FAUCET_CLOSING;                         //Put the FSM in normal operation
        }
    }
    else
    {
        if (timer > 0)
        {
            timer--;
        }
    }
}

/***********************************************************************************************************************
* Function Name: processRawData_FSM
* Description  : State machine that handles the processing of the raw data
* Arguments    : none
* Return Value : none
*
***********************************************************************************************************************/
void processRawData_FSM(void)
{
    switch (rawFsm)
    {
        case    STARTUP:                //Ensure solenoid is closed for enough time
            turn_on_red_led();
            turn_on_yellow_led();
            turn_on_green_led();
            turn_off_solenoid();
            fsm_startup();
            break;
        case    COLLECT_NWNH_SAMPLES:   //Collect NWNH samples used in calibration
            turn_on_green_led();
            fsm_collect_nwnh_samples();
            break;
        case    OPENING_SOLENOID:       //Open solenoid
            turn_on_yellow_led();
            turn_on_red_led();
            turn_on_solenoid();
            fsm_opening_solenoid();
            break;
        case    COLLECT_WNH_SAMPLES:    //Collect samples with water running
            turn_on_red_led();
            fsm_collect_wnh_samples();
            break;
        case    CLOSING_SOLENOID:       //Close solenoid and calculate parameters
            turn_on_green_led();
            turn_on_yellow_led();
            turn_off_solenoid();
            fsm_closing_solenoid();
            break;
        case    FAUCET_CLOSED:          //Normal Operation
            turn_on_green_led();
            turn_off_solenoid();
            fsm_faucet_closed();
            break;
        case    FAUCET_OPENING:
            turn_on_yellow_led();
            turn_on_red_led();
            turn_on_solenoid();
            fsm_faucet_opening();
            break;
        case    FAUCET_OPENED:
            turn_on_red_led();
            turn_on_solenoid();
            fsm_faucet_opened();
            break;
        case    FAUCET_CLOSING:
            turn_on_yellow_led();
            turn_on_green_led();
            turn_off_solenoid();
            fsm_faucet_closing();
            break;
        default:
            break;
    }
    incrementFsmArray(rawFsm);
}

/***********************************************************************************************************************
* Function Name: checkRawData
* Description  : Procedure that checks for more cap. touch sensor raw data and process it if available
* Arguments    : none
* Return Value : none
*
***********************************************************************************************************************/
void checkRawData(void)
{
    if (mydata.tail == MYDATA_SIZE)         //If it reached the end of the buffer make it go back to the beginning (circular)
    {
        mydata.tail = 0;
    }
    else
    {
        if (mydata.tail != mydata.head)      //If there is data to be processed
        {
            processRawData_FSM();
            mydata.tail++;                  //and increment index
        }
    }
}


/* USB_monitor_ Thread entry function */
void usb_monitor_thread_entry(void)
{
    UINT status;
    volatile ssp_err_t ssp_err = SSP_SUCCESS;

    /* start AGT timer */
    vStartAGT();
    /* open the monitoring framework */
    ssp_err = g_sf_ctsu_comm0.p_api->open(g_sf_ctsu_comm0.p_ctrl, g_sf_ctsu_comm0.p_cfg);
    APP_ERR_TRAP(ssp_err);

    while (true)
    {
        /* start monitoring */
        g_sf_ctsu_comm0.p_api->run(g_sf_ctsu_comm0.p_ctrl);

         /*check if AGT timer expired */
         status = tx_event_flags_get(&g_s3a7_st_flags, TIMER_EVENT, TX_OR_CLEAR, &events_got, 1);
         if (status == TX_SUCCESS)
           {
               switch(events_got)
               {
                   case TIMER_EVENT:
                       handle_timer();
                       break;
                   default:
                       break;
               }
           }
        checkRawData();
        tx_thread_sleep (1);
    }
}
