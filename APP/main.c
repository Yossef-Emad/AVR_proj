/*
 * main.c

 *
 *  Created on: Aug 29, 2022
 *      Author: zeyad
 */
#include "Lcd_interface.h"
#include "Led_interface.h"
#include "Buzzer_interface.h"
#include "KeyPad_interface.h"
#include"Timer0_Interface.h"
#include"GIE_interface.h"
#include"TempSensor_interface.h"
#include"Timer1_Interface.h"
#include"util/delay.h"

u8 Local_u8_myPassword[]={"12345"};
u8 G_Temp_u8Value;
u8 G_Flag_u8Input=0;
void WrongCount(void);
int checkPassword(u8 Sender[],u8 Reciver[]){
	u8 i=0;
	while(Reciver[i]!='\0'){
		if(Sender[i]!=Reciver[i]){return 0;}
		i++;
	}
	return 1;
}
void Input_Password(u8 Local_u8_Password[]){

	u8 i=0;
	u8 j=(sizeof( Local_u8_myPassword)/sizeof(u8))-1;
	H_Lcd_void_LcdGoTo(1,0);
	while(1){
	Local_u8_Password[i]=H_KeyPad_void_KeyPadRead();
			if(Local_u8_Password[i] != 0)
			{
				H_Lcd_void_LcdSendCharacter('*');
				i++;
				j--;
			}
			if(j==0){break;}
	}

}
int Input_Led(){
	u8 Local_u8_copy;
	H_Lcd_void_LcdClear();
	H_Lcd_void_LcdGoTo(0,0);
	H_Lcd_void_LcdSendString("1-LedON");
	H_Lcd_void_LcdGoTo(1,0);
	H_Lcd_void_LcdSendString("2-LedOff");
	u8 j=1;
	while(1){
		Local_u8_copy=H_KeyPad_void_KeyPadRead();
			if(Local_u8_copy != 0)
			{  j--;
				H_Lcd_void_LcdSendCharacter(Local_u8_copy);
             if(Local_u8_copy=='1'){
				return 1;}

			}
			if(j==0){return 0;}
	}

}
void ICU_HW(void);


int main()
{
    u8 Local_u8_Password[]={' '};
	u8 Local_u8_WrongCount=0;
	u8 Local_u8_copyLed=0;

	H_Lcd_void_LcdInit();
	H_Led_void_LedInit(BLU_LED);
	H_Led_void_LedInit(RED_LED);
	H_Led_void_LedInit(GRN_LED);
	H_Buzzer_void_BuzzerInit();
	H_KeyPad_void_KeyPadInit();
    H_DcMOTOR_void_Init();
    H_TempSensor_void_Init();
    M_Timer1_void_Init();
    M_Timer1_void_ICU_Init();
    M_Timer1_void_ICU_SetCallBack(ICU_HW);
    M_Timer1_void_ICU_IntEnable();
//choose pin to be input of temp sensor
	while(1)
	{

	H_Lcd_void_LcdSendString("Please Enter Password");
    Input_Password(Local_u8_Password);
   if(checkPassword(Local_u8_Password,Local_u8_myPassword)){
	H_Lcd_void_LcdClear();
	H_Lcd_void_LcdGoTo(1,3);
	H_Lcd_void_LcdSendString("Welcome Ahmed");
	H_Lcd_void_LcdClear();
    if(Input_Led()){
	H_Led_void_LedOn(RED_LED);
	H_Led_void_LedOn(BLU_LED);
	H_Led_void_LedOn(GRN_LED);
    }
    }
   else
   {   H_Lcd_void_LcdClear();
	H_Lcd_void_LcdGoTo(1,1);
	H_Lcd_void_LcdSendString("Wrong Password");
	_delay_ms(3000);
	 H_Lcd_void_LcdClear();
	 H_Lcd_void_LcdGoTo(0,1);
	H_Lcd_void_LcdSendString("Enter Again");
	_delay_ms(3000);
	H_Lcd_void_LcdClear();
	Local_u8_WrongCount++;
      if(Local_u8_WrongCount==3){

	   H_Lcd_void_LcdGoTo(0,1);
	   H_Lcd_void_LcdSendString("Please Try Later");
        _delay_ms(120000);


   }

}


}


	}



void ICU_HW(void)
{
G_Temp_u8Value=H_TempSensor_u16_Read();
}
