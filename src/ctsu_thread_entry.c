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

#include "ctsu_thread.h"
#include "utility.h"

static ULONG events_got1 = 0;  /* Events retrieved */
static touch_button_callback_arg_t button_callback_args; /* button callback saved */
static void Handle_Button_Events (void);    /* handle button events */


/* handle button events */
static void Handle_Button_Events (void)
{
    switch(button_callback_args.event)
      {
          case TOUCH_BUTTON_EVENT_REQUEST_DELAY:
              tx_thread_sleep(1);
              break;
#ifndef  FAUCET_EXAMPLE_CODE
          case TOUCH_BUTTON_EVENT_PRESSED:
              g_ioport.p_api->pinWrite(IOPORT_PORT_09_PIN_00, IOPORT_LEVEL_HIGH);   /* red LED1 */
               break;
          case TOUCH_BUTTON_EVENT_RELEASED:
              g_ioport.p_api->pinWrite(IOPORT_PORT_09_PIN_00, IOPORT_LEVEL_LOW);   /* red LED1 */
              break;
#endif
          default:
              break;
      }

}

/*button callback*/
void touch_button_common_callback(touch_button_callback_arg_t * p_arg)
{
    button_callback_args = *p_arg;
    tx_event_flags_set(&ctsu_event_flags, BUTTON_EVENT, TX_OR);
}


/* ctsu thread entry function */
void ctsu_thread_entry(void)
{

    volatile touch_err_t err = TOUCH_SUCCESS;
    UINT status;

    /* calibrate to usage environment */
    err = g_touch0_on_g_ctsu.p_api->calibrate(g_touch0_on_g_ctsu.p_ctrl);
    if(TOUCH_SUCCESS != err)
    {
        Blink_Red_Led = 1;
    }

    /* add error checking */
    while(true)
    {
        /*check if button is pressed or AGT timer expired */
          status = tx_event_flags_get(&ctsu_event_flags, ALL_EVENTS, TX_OR_CLEAR, &events_got1, TX_NO_WAIT);

        if (status == TX_SUCCESS)
          {
              switch(events_got1)
              {
                  /* button events happened */
                  case BUTTON_EVENT:
                      Handle_Button_Events();
                      break;

                  default:
                      break;
              }
          }
        /* wait for update finish */
        if (g_touch0_on_g_ctsu.p_api->update (g_touch0_on_g_ctsu.p_ctrl) == TOUCH_SUCCESS)
        {
            /* scan the CTSU to perform a capacitance measurement*/
            g_touch0_on_g_ctsu.p_api->scan(g_touch0_on_g_ctsu.p_ctrl);
        }
        tx_thread_sleep(1);
    }

    return;
}


