/**************************************************************************************/
/***********************************SSD_program.c************************************/
/**********************************Created: 1/3/2024***********************************/
/*********************************Author: Amira Ismail*********************************/
/**************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "SSD_interface.h"
#include "SSD_config.h"
#include "util/delay.h"


void SSD_voidDisplay (u8 Local_u8Num)
{
	DIO_voidSetPinDirection(SSD_PORT, SSD_PIN1, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(SSD_PORT, SSD_PIN2, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(SSD_PORT, SSD_PIN3, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(SSD_PORT, SSD_PIN4, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN3, DIO_PIN_OUTPUT);
	DIO_voidSetPinValue(DIO_PORTA, DIO_PIN3, DIO_PIN_LOW);

	u8 Local_u8Counter = 0;

	Local_u8Counter = GET_BIT(Local_u8Num, 0);
	DIO_voidSetPinValue(SSD_PORT, SSD_PIN1, Local_u8Counter);

	Local_u8Counter = GET_BIT(Local_u8Num, 1);
	DIO_voidSetPinValue(SSD_PORT, SSD_PIN2, Local_u8Counter);

	Local_u8Counter = GET_BIT(Local_u8Num, 2);
	DIO_voidSetPinValue(SSD_PORT, SSD_PIN3, Local_u8Counter);

	Local_u8Counter = GET_BIT(Local_u8Num, 3);
	DIO_voidSetPinValue(SSD_PORT, SSD_PIN4, Local_u8Counter);

	_delay_ms(1000);
	Local_u8Num ++;

	if (SSD_LastNum <= Local_u8Num)
		{
			Local_u8Num = 0;
		}

}





