/*
 * TWI_private.h
 *
 *  Created on: Aug 29, 2022
 *      Author: yassi
 */

#ifndef MCAL_TWI_TWI_PRIVATE_H_
#define MCAL_TWI_TWI_PRIVATE_H_
#define TWBR_REG    (*((volatile u8*)0x20))//BIT RATE FOR SPEED
#define TWCR_REG    (*((volatile u8*)0x56))// send start/stop/enable ACK/ ENABLE interuppt
#define TWSR_REG    (*((volatile u8*)0x21))//PRESCALLER(config) ,STATUS CODE(Read)
#define TWAR_REG     (*((volatile u8*)0x22))//my address as slave+disable/enable broadcast responce
#define TWDR_REG     (*((volatile u8*)0x23))//1 byte data sent/received
// TWCR_REG
#define TWINT_BIT     7//Interuppt flag
#define TWEA_BIT     6//ACK enable
#define TWSTA_BIT 5   //SEND START enable
#define TWSTO_BIT  4  //stop bit enable
#define TWWC_BIT   3  //write collision flag when we write we write above it
#define TWEN_BIT 2  // Enabl TWI
#define TWIE_BIT  0//Enable Interrupt
//TWSR_REG
#define TWPS1_BIT  1
#define TWPS0_BIT  0
//TWAR_REG
#define TWGCE_BIT   0
#define TWI_STATUS_CODE_MASK 0b11111000
#endif /* MCAL_TWI_TWI_PRIVATE_H_ */
