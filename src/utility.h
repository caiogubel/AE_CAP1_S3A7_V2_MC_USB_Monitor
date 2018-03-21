/*
 * utility.h
 *
 *  Created on: Dec 11, 2017
 *      Author: xianghui.wang
 */

#ifndef __UTILITY_H__  //[
#define __UTILITY_H__

#define BUTTON_EVENT        (0x1)
#define TIMER_EVENT         (0x2)
#define ALL_EVENTS          (0x3)
#define APP_ERR_TRAP(a)     if(a) {__asm("BKPT #0\n");} /* trap the error location */

int Blink_Red_Led;       /* auto tune failure indication */



#endif //] _UTILITY_H__
