/*
 * EEPROM_programme.c
 *
 *  Created on: Aug 30, 2022
 *      Author: yassi
 */
#include"TWI_interface.h"
#include"StandardTypes.h"
#include"EEPROM_configuration.h"
#include"EEPROM_interface.h"
#include"EEPROM_private.h"
void H_EEPROM_void_Init(void)
{M_TWI_void_Init();

}

u8 H_EEPROM_void_WriteByte(u16 copy_u16Add,u8 copy_u8Byte)
{   u8 status;
    u8 _3MSB;
	//step1: send start
	M_TWI_void_sendStart();
	//step2:check status
	status=M_TWI_void_GetStatus();
	if(TWI_MT_DATA_SENT_NOACK!=status){return 0;}
     //step3:send A+3MSB of byte address
	_3MSB=(u8)((copy_u16Add&0x0700)<<7);
	M_TWI_void_sendByte(_3MSB|0xA0);
	//step4:check status
	status=M_TWI_void_GetStatus();
	if(TWI_MT_SLA_W_ACK!=status){return 0;}
	// step5:send the rest of byte address
	M_TWI_void_sendByte((u8)copy_u16Add);
    // check status
	status=M_TWI_void_GetStatus();\
	if(TWI_MT_DATA_SENT_ACK!=status){return 0;}
	//send data byte to be written in EEPROM
	M_TWI_void_sendByte(copy_u8Byte);
	//check status
	status=M_TWI_void_GetStatus();\
		if(TWI_MT_DATA_SENT_ACK!=status){return 0;}
	//send stop
	M_TWI_void_sendStop();
	return 1;
}
u8 H_EEPROM_void_ReadByte(u16 copy_u16Add,u8*ptr)
{
	u8 status;
	    u8 _3MSB;
		//step1: send start
		M_TWI_void_sendStart();
		//step2:check status
		status=M_TWI_void_GetStatus();
		if(TWI_MT_DATA_SENT_NOACK!=status){return 0;}
	     //step3:send A+3MSB of byte address
		_3MSB=(u8)((copy_u16Add&0x0700)<<7);
		M_TWI_void_sendByte(_3MSB|0xA0);
		//step4:check status
		status=M_TWI_void_GetStatus();
		if(TWI_MT_SLA_W_ACK!=status){return 0;}
		// step5:send the rest of byte address
		M_TWI_void_sendByte((u8)copy_u16Add);
	    // check status
		status=M_TWI_void_GetStatus();
		if(TWI_MT_DATA_SENT_ACK!=status){return 0;}

		//step7:send repeated start
		M_TWI_void_sendStart();
		//step8:check status
		status=M_TWI_void_GetStatus();
				if(TWI_MR_REPEATED_START_SUCCESS!=status){return 0;}
		//step9: send SLA+R
				M_TWI_void_sendByte(0xA0|0x01);
		//step10:check status
				status=M_TWI_void_GetStatus();
				if(TWI_MR_SLA_R_ACK!=status){return 0;}
		//step11:receive data from EEPROM
			*ptr	=M_TWI_void_ReceiveByte_Ack();
		//step12:check status
			status=M_TWI_void_GetStatus();
		if(TWI_MR_DATA_RECEIVE_ACK !=status){return 0;}
		//step13:send stop
		M_TWI_void_sendStop();

return 1;



}
