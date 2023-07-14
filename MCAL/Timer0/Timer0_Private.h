/*
 * Timer0_Private.h
 *
 *  Created on: Aug 17, 2022
 *      Author: Abdulrahman
 */

#ifndef MCAL_TIMER0_TIMER0_PRIVATE_H_
#define MCAL_TIMER0_TIMER0_PRIVATE_H_

#define TCCR0_REG		*(volatile u8*)0x53
#define TIMSK_REG		*(volatile u8*)0x59
#define TCNT0_REG		*(volatile u8*)0x52
#define OCR0_REG		*(volatile u8*)0x5C
// TCCR0_REG BITS
#define WGM00_BIT		6
#define WGM01_BIT		3
#define CS02_BIT		2
#define	CS01_BIT		1
#define	CS00_BIT		0

// TIMSK_REG BITS
#define TOIE0_BIT		0
#define OCIE0_BIT		1

//TIMER0_MODES
#define TIMER0_NORMAL_MODE				0
#define TIMER0_CTC_MODE					1
#define TIMER0_PHASECORRECT_MODE		2
#define TIMER0_FASTPWM_MODE				3

//TIMER0 CLK
#define TIMER0_PRESCALAR_1						1
#define TIMER0_PRESCALAR_8						2
#define TIMER0_PRESCALAR_64						3
#define TIMER0_PRESCALAR_256					4
#define TIMER0_PRESCALAR_1024					5
#define TIMER0_PRESCALAR_EXTCLK_FALLEDGE		6
#define TIMER0_PRESCALAR_EXTCLK_RISEEDGE		7

//TIMER0 OC0 MODES (Non PWM):
#define TIMER0_OC0_DISCONNECTED				0
#define TIMER0_OC0_TOG						1
#define TIMER0_OC0_CLR						2
#define TIMER0_OC0_SET						3
//TIMER0 OC0 MODES (PWM):
#define TIMER0_OC0_PWM_NON_INVERTING		0b00100000 //value is inside mask
#define TIMER0_OC0_PWM_INVERTING			0b00110000 //value is inside mask

#define TIMER0_PRESCALAR_MASK		0b11111000

#define TIMER0_OC0_MASK				0b11001111

#define TIMER0_OC0_SHIFT			4

#endif /* MCAL_TIMER0_TIMER0_PRIVATE_H_ */
