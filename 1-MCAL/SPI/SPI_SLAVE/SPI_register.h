///**************************************************************************************/
///***********************************DIO_register.h*************************************/
///**************************Created: 5/3/2024  11:30:00 AM******************************/
///********************************Author: Amira Ismail**********************************/
///**************************************************************************************/
//
#ifndef SPI_REGISTER_H_
#define SPI_REGISTER_H_


#include"STD_TYPES.h"

typedef struct
{
	u8 SPCR_REG;
	u8 SPSR_REG;
	u8 SPDR_REG;
}SPI;

#define SPI_REGS 					((volatile SPI*)0x2D)
/*
SPI_REGS -> SPDR_REG
(*SPI_REGS). SPDR_REG
*/


#define  SPIE				7
#define  SPE				6
#define  DORD				5
#define  MSTR				4
#define  CPOL				3
#define  CPHA				2
#define  SPR1				1
#define  SPR0				0

#define  SPIF				7
#define  WCOL				6
#define  SPI2X				0

#define  MSP				7
#define  LSB				0


#endif  /*SPI_REGISTER_H_*/


