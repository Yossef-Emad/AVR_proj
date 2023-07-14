/*
 * TWI_programme.c
 *
 *  Created on: Aug 29, 2022
 *      Author: yassi
 */
#include"StandardTypes.h"
#include"BitMath.h"
#include"TWI_configuration.h"
#include"TWI_interface.h"
#include"TWI_private.h"
//Master Transmmiter
void M_TWI_void_Init(void){
	//speed 400 Kbits,FCPU=8MHz,prescaller=1
	CLR_BIT(TWSR_REG,TWPS0_BIT);
	CLR_BIT(TWSR_REG,TWPS1_BIT);
	TWBR_REG=0X02;
	//Enable TWI interface using polling not enterupt
	SET_BIT(TWCR_REG,TWEN_BIT);



}
void M_TWI_void_sendStart(void){
	TWCR_REG=(1<<TWINT_BIT)|(1<<TWSTA_BIT)|(1<<TWEN_BIT);
	while(GET_BIT(TWCR_REG,TWINT_BIT)==0);//wait until intrupt flag is raised(be 1 means cleared)
}
void M_TWI_void_sendStop(void){

	TWCR_REG=(1<<TWINT_BIT)|(1<<TWEN_BIT)|(1<<TWSTO_BIT);

}
void M_TWI_void_sendByte(u8 copy_u8Byte){
	TWDR_REG=copy_u8Byte;
	TWCR_REG=(1<<TWINT_BIT)|(1<<TWEN_BIT);
	while(GET_BIT(TWCR_REG,TWINT_BIT)==0);//wait until intrupt flag
}
u8 M_TWI_void_ReceiveByte_Ack(void){
	//step1:clear flag,Enable Ack
	TWCR_REG=(1<<TWINT_BIT)|(1<<TWEN_BIT)|(1<<TWEA_BIT);
	while(GET_BIT(TWCR_REG,TWINT_BIT)==0);//wait until intrupt flag
	return TWDR_REG;


}
u8 M_TWI_void_ReceiveByte_NAck(void){
	//step1:clear flag,disable ACK
		TWCR_REG=(1<<TWINT_BIT)|(1<<TWEN_BIT);
		while(GET_BIT(TWCR_REG,TWINT_BIT)==0);//wait until intrupt flag
		return TWDR_REG;

}
u8 M_TWI_void_GetStatus(void){
	return (TWI_STATUS_CODE_MASK&TWSR_REG);

}
