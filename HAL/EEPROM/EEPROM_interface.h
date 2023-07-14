/*
 * EEPROM_interface.h
 *
 *  Created on: Aug 30, 2022
 *      Author: yassi
 */

#ifndef HAL_EEPROM_EEPROM_INTERFACE_H_
#define HAL_EEPROM_EEPROM_INTERFACE_H_

void H_EEPROM_void_Init(void);
/*
 *  H_EEPROM_void_WriteByte to write 1 byte data to EEPROM address
 *  input
 * */
u8 H_EEPROM_void_WriteByte(u16 copy_u16Add,u8 copy_u8Byte);
u8 H_EEPROM_void_ReadByte(u16 copy_u16Add,u8*ptr);
#endif /* HAL_EEPROM_EEPROM_INTERFACE_H_ */
