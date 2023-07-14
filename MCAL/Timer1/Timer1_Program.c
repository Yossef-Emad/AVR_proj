/*
 * Timer1_Program.c
 *
 *  Created on: Aug 20, 2022
 *      Author: Abdulrahman
 */

#include "StandardTypes.h"
#include "BitMath.h"
#include "avr/interrupt.h"
#include "Timer1_Interface.h"
#include "Timer1_Private.h"

static void (*Timer_ICU_CallBack)(void) = NULL;

void M_Timer1_void_Init(void)
{
	// config. timer in normal mode
	CLR_BIT(TCCR1A_REG,WGM10_BIT);
	CLR_BIT(TCCR1A_REG,WGM11_BIT);
	CLR_BIT(TCCR1B_REG,WGM12_BIT);
	CLR_BIT(TCCR1B_REG,WGM13_BIT);

	// config prescalar -> 256
	SET_BIT(TCCR1B_REG,CS12_BIT);
	CLR_BIT(TCCR1B_REG,CS11_BIT);
	CLR_BIT(TCCR1B_REG,CS10_BIT);
}

void M_Timer1_void_ICU_Init(void)
{
	// set trigger as rising edge
	SET_BIT(TCCR1B_REG,ICES1_BIT);
}

void M_Timer1_void_ICU_SetCallBack(void(*Copy_Ptr)(void))
{
	Timer_ICU_CallBack = Copy_Ptr;
}

void M_Timer1_void_ICU_IntEnable(void)
{
	SET_BIT(TIMSK_REG,TICIE1_BIT);
}

void M_Timer1_void_ICU_IntDisable(void)
{
	CLR_BIT(TIMSK_REG,TICIE1_BIT);
}

void M_Timer1_void_ICU_SetTirgger(u8 Copy_u8_Trigger)
{
	// method 1
	/*switch(Copy_u8_Trigger)
	{
	case TIMER1_ICU_RISING_TIRGG:
		SET_BIT(TCCR1B_REG,ICES1_BIT);
		break;
	case TIMER1_ICU_FALLING_TIRGG:
		CLR_BIT(TCCR1B_REG,ICES1_BIT);
		break;
	default:
		break;
	}*/

	// method 2
	TCCR1B_REG &= 0b10111111;
	TCCR1B_REG |= (Copy_u8_Trigger << 6);

}

u16 M_Timer1_u16_ICU_Read(void)
{
	return ICR1_REG;
}

ISR(TIMER1_CAPT_vect)
{
	Timer_ICU_CallBack();
}
