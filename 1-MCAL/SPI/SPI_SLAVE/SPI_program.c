/**************************************************************************************/
/***********************************DIO_pprogram.c*************************************/
/**************************Created: 5/3/2024  11:30:00 AM******************************/
/********************************Author: Amira Ismail**********************************/
/**************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SPI_interface.h"
#include "SPI_register.h"
#include "DIO_interface.h"

void SPI_voidInitMaster(void)
{
	//DISABLE SPI INTERRUPT
	CLR_BIT(SPI_REGS -> SPCR_REG, SPIE);

	SET_BIT(SPI_REGS -> SPCR_REG, DORD);

	//ENABLE MASTER
	SET_BIT(SPI_REGS -> SPCR_REG, MSTR);

	SET_BIT(SPI_REGS -> SPCR_REG, CPOL);
	SET_BIT(SPI_REGS -> SPCR_REG, CPHA);

	//select clk rate = FCPU/64  (250 KHZ)
	CLR_BIT(SPI_REGS -> SPCR_REG, SPR0);
	SET_BIT(SPI_REGS -> SPCR_REG, SPR1);
	CLR_BIT(SPI_REGS -> SPSR_REG, SPI2X);

	//ENABLE SPI
	SET_BIT(SPI_REGS -> SPCR_REG, SPE);

}

void SPI_voidInitSlave (void)
{
	//DISABLE SPI INTERRUPT
	CLR_BIT(SPI_REGS -> SPCR_REG, SPIE);

	SET_BIT(SPI_REGS -> SPCR_REG, DORD);

	//DISABLE MASTER
	CLR_BIT(SPI_REGS -> SPCR_REG, MSTR);

	SET_BIT(SPI_REGS -> SPCR_REG, CPOL);
	SET_BIT(SPI_REGS -> SPCR_REG, CPHA);

	//ENABLE SPI
	SET_BIT(SPI_REGS -> SPCR_REG, SPE);
}

void SPI_u8Transieve (u8 copy_u8TxData, u8* copy_pu8RxData)
{
	if(copy_pu8RxData != NULL)
	{
		SPI_REGS -> SPDR_REG = copy_u8TxData;

		//Busy Wait for SPI Flag
		while(0 == GET_BIT(SPI_REGS -> SPSR_REG, SPIF));

		*copy_pu8RxData = SPI_REGS -> SPDR_REG;
	}
	else
	{
		//returen error state
	}
}

