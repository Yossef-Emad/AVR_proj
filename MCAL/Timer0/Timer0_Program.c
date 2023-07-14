/*
 * Timer0_Program.c
 *
 *  Created on: Aug 17, 2022
 *      Author: Abdulrahman
 */

#include "Timer0_Interface.h"
#include "Timer0_Private.h"
#include <stdlib.h>

u32 Timer0_u32_NumOfOVF;
u32 Timer0_u32_NumOfCompMatch;
u8 Timer0_u8_RemTicks;
void (*Timer0_CallBack[2])(void) = {NULL};


void M_Timer_0_void_Init(void)
{
#if(TIMER_0_MODE	==	 TIMER0_NORMAL_MODE)
	// to select normal mode
	CLR_BIT(TCCR0_REG,WGM01_BIT);
	CLR_BIT(TCCR0_REG,WGM00_BIT);
	#if		TIMER_0_OC0_MODE >= 0 && TIMER_0_OC0_MODE <=3
	// apply mask
	TCCR0_REG &= TIMER0_OC0_MASK;
	// insert value
	TCCR0_REG |= (TIMER_0_OC0_MODE << TIMER0_OC0_SHIFT);

	#else
	#error ("Wrong OC0 mode")

	#endif

#elif		TIMER_0_MODE	==	 TIMER0_CTC_MODE

	SET_BIT(TCCR0_REG,WGM01_BIT);
	CLR_BIT(TCCR0_REG,WGM00_BIT);

#elif		TIMER_0_MODE	==	 TIMER0_PHASECORRECT_MODE
	CLR_BIT(TCCR0_REG,WGM01_BIT);
	SET_BIT(TCCR0_REG,WGM00_BIT);
	#if(TIMER_0_OC0_MODE	==	TIMER0_OC0_PWM_NON_INVERTING	||	TIMER_0_OC0_MODE	==	TIMER0_OC0_PWM_INVERTING)
	// apply mask
	TCCR0_REG &= TIMER0_OC0_MASK;
	// insert value
	TCCR0_REG |= TIMER_0_OC0_MODE;

	#else
	#error ("Wrong OC0 mode")

	#endif

#elif		TIMER_0_MODE	==	 TIMER0_FASTPWM_MODE
	SET_BIT(TCCR0_REG,WGM01_BIT);
	SET_BIT(TCCR0_REG,WGM00_BIT);
	#if(TIMER_0_OC0_MODE	==	TIMER0_OC0_PWM_NON_INVERTING	||	TIMER_0_OC0_MODE	==	TIMER0_OC0_PWM_INVERTING)
	// apply mask
	TCCR0_REG &= TIMER0_OC0_MASK;
	// insert value
	TCCR0_REG |= TIMER_0_OC0_MODE;


	#else
	#error ("Wrong OC0 mode")

	#endif

#else
	#error ("Wrong timer mode")

#endif

}

void M_Timer_0_void_SetTime(u32 Copy_u32_DesiredTime)
{
	u32 Local_arr_Prescalar[5] = {1,8,64,256,1024};
	u32 Local_u32_TickTime   = Local_arr_Prescalar[TIMER_0_PRESCALER-1] / F_OSC;	// result in micro
	u32 Local_u32_TotalTicks = (Copy_u32_DesiredTime * 1000) / Local_u32_TickTime;
#if(TIMER_0_MODE	==	TIMER0_NORMAL_MODE)
	Timer0_u32_NumOfOVF 	 = Local_u32_TotalTicks / 256;
	Timer0_u8_RemTicks 		 = Local_u32_TotalTicks % 256;
	if(Timer0_u8_RemTicks != 0)
	{
		TCNT0_REG = 256 - Timer0_u8_RemTicks;
		Timer0_u32_NumOfOVF++;
	}
#elif(TIMER_0_MODE	==	TIMER0_CTC_MODE)
	u8 Local_u8_Counter = 255;
	while(Local_u32_TotalTicks % Local_u8_Counter)
		Local_u8_Counter--;
	Timer0_u32_NumOfCompMatch = Local_u32_TotalTicks / Local_u8_Counter;
	OCR0_REG = Local_u8_Counter;

#endif

}

void M_Timer_0_void_SetFastPWM(u8 Copy_u8_DutyCycle)
{
#if(TIMER_0_MODE	==	TIMER0_FASTPWM_MODE)
	#if(TIMER_0_OC0_MODE	==	TIMER0_OC0_PWM_NON_INVERTING)
		OCR0_REG = abs(((Copy_u8_DutyCycle * 256)/100)-1);

	#elif(TIMER_0_OC0_MODE	==	TIMER0_OC0_PWM_INVERTING)
		OCR0_REG = abs(255-((Copy_u8_DutyCycle * 256)/100));

	#else
	#error ("Wrong OC0 mode")

	#endif

#endif
}

void M_Timer_0_void_SetPhaseCorrectPWM(u8 Copy_u8_DutyCycle)
{
#if(TIMER_0_MODE	==	TIMER0_PHASECORRECT_MODE)
	#if(TIMER_0_OC0_MODE	==	TIMER0_OC0_PWM_NON_INVERTING)
		OCR0_REG = (Copy_u8_DutyCycle * 255) / 100;

	#elif(TIMER_0_OC0_MODE	==	TIMER0_OC0_PWM_INVERTING)
		OCR0_REG = 255 - ((Copy_u8_DutyCycle * 255) / 100;);

	#else
	#error ("Wrong OC0 mode")

	#endif

#endif
}

void M_Timer_0_void_Start(void)
{
#if(TIMER_0_PRESCALER >0 && TIMER_0_PRESCALER <= 7)
	// apply timer mask
	TCCR0_REG &= TIMER0_PRESCALAR_MASK;

	TCCR0_REG |= TIMER_0_PRESCALER;

#else
	#error ("Wrong choice")

#endif

}

void M_Timer_0_void_Stop(void)
{
	CLR_BIT(TCCR0_REG,CS00_BIT);
	CLR_BIT(TCCR0_REG,CS01_BIT);
	CLR_BIT(TCCR0_REG,CS02_BIT);
}

void M_Timer_0_void_SetCallBack(void (*Copy_Ptr)(void) , u8 Copy_u8_IntId)
{
	Timer0_CallBack[Copy_u8_IntId] = Copy_Ptr;
}

void M_Timer_0_void_EnableInt(u8 Copy_u8_IntId)
{
	switch(Copy_u8_IntId)
	{
	case TIMER0_OVF_INT_ID:
		SET_BIT(TIMSK_REG,TOIE0_BIT);
		break;
	case TIMER0_COMP_MATCH_INT_ID:
		SET_BIT(TIMSK_REG,OCIE0_BIT);
		break;
	default:
		break;
	}
}

void M_Timer_0_void_DisableInt(u8 Copy_u8_IntId)
{
	switch(Copy_u8_IntId)
		{
	case TIMER0_OVF_INT_ID:
		CLR_BIT(TIMSK_REG,TOIE0_BIT);
		break;
	case TIMER0_COMP_MATCH_INT_ID:
		CLR_BIT(TIMSK_REG,OCIE0_BIT);
		break;
		}
}

ISR(TIMER0_OVF_vect)
{
	if(Timer0_CallBack != NULL)
	{
		static u32 Local_u32_Counter = 0;
		Local_u32_Counter++;
		if(Local_u32_Counter == Timer0_u32_NumOfOVF)
		{
			Timer0_CallBack[TIMER0_OVF_INT_ID]();
			Local_u32_Counter = 0;
			TCNT0_REG = 256 - Timer0_u8_RemTicks;
		}
	}
	else
	{

	}
}

ISR(TIMER0_COMP_vect)
{
	if(Timer0_CallBack != NULL)
		{
			static u32 Local_u32_Counter = 0;
			Local_u32_Counter++;
			if(Local_u32_Counter == Timer0_u32_NumOfCompMatch)
			{
				Timer0_CallBack[TIMER0_COMP_MATCH_INT_ID]();
				Local_u32_Counter = 0;
			}
		}
		else
		{

		}
}
