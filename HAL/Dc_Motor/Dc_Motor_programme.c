/*
 * Dc_Motor_programme.c
 *
 *  Created on: Aug 30, 2022
 *      Author: yassi
 */

#ifndef HAL_DC_MOTOR_DC_MOTOR_PROGRAMME_C_
#define HAL_DC_MOTOR_DC_MOTOR_PROGRAMME_C_
#include "Dio_Interface.h"
#include "Timer0_Interface.h"
#include "StandardTypes.h"
#include "Dc_Motor_configuration.h"
#include "Dc_MOTOR_Private.h"
#include "BitMath.h"
#include"Dc_Motor_interface.h"
void H_DcMOTOR_void_Init(void){
M_Dio_void_PinMode(DCMOTOR_PIN1,OUTPUT);
M_Dio_void_PinMode(DCMOTOR_PIN2,OUTPUT);
M_Dio_void_PinMode(PB3_PIN,OUTPUT);
M_Timer_0_void_Init();
M_Timer_0_void_Start();
}
void H_DcMOTOR_void_DcMotorMove(void){
#if( DCMOTOR_MOVE_SELECT    ==   DCMOTOR_MOVE_CLKWISE)
	M_Dio_void_PinWrite(DCMOTOR_PIN1,LOW);
	M_Dio_void_PinWrite(DCMOTOR_PIN2,HIGH);
#elif( DCMOTOR_MOVE_SELECT    ==   DCMOTOR_MOVE_ANTI_CLKWISE)
	M_Dio_void_PinWrite(DCMOTOR_PIN1,HIGH);
		M_Dio_void_PinWrite(DCMOTOR_PIN2,LOW);
#elif( DCMOTOR_MOVE_SELECT    ==   DCMOTOR_MOVE_STOP)
		M_Dio_void_PinWrite(DCMOTOR_PIN1,LOW);
		M_Dio_void_PinWrite(DCMOTOR_PIN2,LOW);
#endif
}

void H_DcMOTOR_void_DcMotorSpeed(void){
#if(DCMOTOR_SPEED_SELECT   ==   DCMOTOR_SPEED_NORMAL)
	M_Timer_0_void_SetFastPWM(50);
#elif(DCMOTOR_SPEED_SELECT  ==    DCMOTOR_SPEED_HIGH)
	M_Timer_0_void_SetFastPWM(100);
#elif(DCMOTOR_SPEED_SELECT   ==   DCMOTOR_SPEED_LOW)
	M_Timer_0_void_SetFastPWM(10);
#endif
}


#endif /* HAL_DC_MOTOR_DC_MOTOR_PROGRAMME_C_ */
