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

//MASTER PROGRAM

void main(void)
{
	DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN4, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN5, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN6, DIO_PIN_INPUT);
	DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN7, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN5, DIO_PIN_OUTPUT);  //LED


	SPI_voidInitMaster();

	u8 Local_u8ReceiveData;
	while(1)
	{
		DIO_voidSetPinValue(DIO_PORTB, DIO_PIN4, DIO_PIN_HIGH);
		_delay_ms(1);
		DIO_voidSetPinValue(DIO_PORTB, DIO_PIN4, DIO_PIN_LOW);

		SPI_u8Transieve(2, &Local_u8ReceiveData);  //SEND 2

		if(Local_u8ReceiveData == 35)
		{
			DIO_voidTogglePinValue(DIO_PORTA, DIO_PIN5);
			_delay_ms(1000);
		}
	}
}


