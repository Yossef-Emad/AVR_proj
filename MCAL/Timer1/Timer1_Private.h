/*
 * Timer1_Private.h
 *
 *  Created on: Aug 20, 2022
 *      Author: Abdulrahman
 */

#ifndef MCAL_TIMER1_TIMER1_PRIVATE_H_
#define MCAL_TIMER1_TIMER1_PRIVATE_H_

#define TCCR1A_REG			*(volatile u8*)0x4F
#define TCCR1B_REG			*(volatile u8*)0x4E

#define TIMSK_REG			*(volatile u8*)0x59

#define ICR1_REG			*(volatile u16*)0x46
#define ICR1L_REG			*(volatile u8*)0x46
#define ICR1H_REG			*(volatile u8*)0x47

#define TCNT1_REG			*(volatile u16*)0x4C
#define TCNT1L_REG			*(volatile u8*)0x4C
#define TCNT1H_REG			*(volatile u8*)0x4D

#define OCR1A_REG			*(volatile u8*)0x4A
#define OCR1B_REG			*(volatile u8*)0x48


// TCCR1A_REG BITS
#define WGM11_BIT       1
#define WGM10_BIT       0

// TCCR1B_REG BITS
#define ICES1_BIT		6
#define WGM13_BIT       4
#define WGM12_BIT       3
#define CS12_BIT        2
#define CS11_BIT        1
#define CS10_BIT        0

// TIMSK_REG BITS
#define TICIE1_BIT		5
#define TOIE1_BIT       2

#endif /* MCAL_TIMER1_TIMER1_PRIVATE_H_ */
