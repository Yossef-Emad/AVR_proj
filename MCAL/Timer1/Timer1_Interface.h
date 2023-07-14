/*
 * Timer1_Interface.h
 *
 *  Created on: Aug 20, 2022
 *      Author: Abdulrahman
 */

#ifndef MCAL_TIMER1_TIMER1_INTERFACE_H_
#define MCAL_TIMER1_TIMER1_INTERFACE_H_

#define TIMER1_ICU_FALLING_TIRGG		0
#define TIMER1_ICU_RISING_TIRGG			1

void M_Timer1_void_Init(void);
void M_Timer1_void_ICU_Init(void);
void M_Timer1_void_ICU_SetCallBack(void(*)(void));
void M_Timer1_void_ICU_IntEnable(void);
void M_Timer1_void_ICU_IntDisable(void);
void M_Timer1_void_ICU_SetTirgger(u8 Copy_u8_Trigger);
u16 M_Timer1_u16_ICU_Read(void);

#endif /* MCAL_TIMER1_TIMER1_INTERFACE_H_ */
