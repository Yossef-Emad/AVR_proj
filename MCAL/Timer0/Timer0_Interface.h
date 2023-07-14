/*
 * Timer0_Interface.h
 *
 *  Created on: Aug 17, 2022
 *      Author: Abdulrahman
 */

#ifndef MCAL_TIMER0_TIMER0_INTERFACE_H_
#define MCAL_TIMER0_TIMER0_INTERFACE_H_

#include "StandardTypes.h"
#include "BitMath.h"
#include "avr/interrupt.h"
#include "Timer0_Configuration.h"

#define TIMER0_OVF_INT_ID			0
#define TIMER0_COMP_MATCH_INT_ID	1

void M_Timer_0_void_Init(void);
void M_Timer_0_void_SetTime(u32);
void M_Timer_0_void_Start(void);
void M_Timer_0_void_Stop(void);
void M_Timer_0_void_EnableInt(u8);
void M_Timer_0_void_DisableInt(u8);
void M_Timer_0_void_SetCallBack(void (*)(void) , u8);
void M_Timer_0_void_SetFastPWM(u8);
void M_Timer_0_void_SetPhaseCorrectPWM(u8);

#endif /* MCAL_TIMER0_TIMER0_INTERFACE_H_ */
