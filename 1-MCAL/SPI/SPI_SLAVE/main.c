/*
 * main.c
 *
 *  Created on: Mar 5, 2024
 *      Author: Amira
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "SPI_interface.h"
#include "util/delay.h"

//SLAVE PROGRAM

void main(void)
{
	DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN4, DIO_PIN_INPUT);
	DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN5, DIO_PIN_INPUT);
	DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN6, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN7, DIO_PIN_INPUT);
	DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN6, DIO_PIN_OUTPUT);  //LED

	SPI_voidInitSlave();

	u8 Local_u8ReceivedData;
	while(1)
	{
		SPI_u8Transieve(35, &Local_u8ReceivedData); //SEND
		if (Local_u8ReceivedData == 2)
		{
			DIO_voidTogglePinValue(DIO_PORTA, DIO_PIN6);
			_delay_ms(1000);
		}
	}
}
