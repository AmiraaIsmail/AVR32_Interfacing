/**************************************************************************************/
/***********************************SSD_MUL_program.c**********************************/
/**********************************Created: 5/3/2024***********************************/
/*********************************Author: Amira Ismail*********************************/
/**************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "SSD_MUL_interface.h"
#include "SSD_MUL_config.h"
#include "util/delay.h"


void SSD_voidInit(void)
{
	//7 SEG PINS -> OUTPUT
	DIO_voidSetPinDirection(SSD_PORT, SSD_PIN1, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(SSD_PORT, SSD_PIN2, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(SSD_PORT, SSD_PIN3, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(SSD_PORT, SSD_PIN4, DIO_PIN_OUTPUT);

	//ETA32 KIT PINS -> OUTPUT, LOW
	DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN3, DIO_PIN_OUTPUT);
	DIO_voidSetPinValue    (DIO_PORTA, DIO_PIN3, DIO_PIN_LOW);
	DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN2, DIO_PIN_OUTPUT);
	DIO_voidSetPinValue    (DIO_PORTA, DIO_PIN2, DIO_PIN_LOW);
	DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN5, DIO_PIN_OUTPUT);
	DIO_voidSetPinValue    (DIO_PORTB, DIO_PIN5, DIO_PIN_LOW);
	DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN6, DIO_PIN_OUTPUT);
	DIO_voidSetPinValue    (DIO_PORTB, DIO_PIN6, DIO_PIN_LOW);

	//7 SEG CONTROL PORT -> OUTPUT
	DIO_voidSetPortDirection(SSD_CONTROL_PORT, DIO_PORT_OUTPUT);

}

void SSD_voidDisplay (u16 num)
{
	u8 Local_u8Num;
	u8 Local_u8Counter = 0;

	/********************************************CONTROL SSD1*******************************************/
	DIO_voidSetPinValue(SSD_CONTROL_PORT, SSD2_CONTROL_PIN, DIO_PIN_HIGH);
	DIO_voidSetPinValue(SSD_CONTROL_PORT, SSD3_CONTROL_PIN, DIO_PIN_HIGH);
	DIO_voidSetPinValue(SSD_CONTROL_PORT, SSD4_CONTROL_PIN, DIO_PIN_HIGH);

	Local_u8Num = num % 10;
	num = num / 10;

	Local_u8Counter = GET_BIT(Local_u8Num, 0);
	DIO_voidSetPinValue(SSD_CONTROL_PORT, SSD1_CONTROL_PIN, DIO_PIN_LOW);
	DIO_voidSetPinValue(SSD_PORT, SSD_PIN1, Local_u8Counter);

	Local_u8Counter = GET_BIT(Local_u8Num, 1);
	DIO_voidSetPinValue(SSD_PORT, SSD_PIN2, Local_u8Counter);

	Local_u8Counter = GET_BIT(Local_u8Num, 2);
	DIO_voidSetPinValue(SSD_PORT, SSD_PIN3, Local_u8Counter);

	Local_u8Counter = GET_BIT(Local_u8Num, 3);
	DIO_voidSetPinValue(SSD_PORT, SSD_PIN4, Local_u8Counter);
	_delay_ms(1);


	/********************************************CONTROL SSD2*******************************************/
	DIO_voidSetPinValue(SSD_CONTROL_PORT, SSD1_CONTROL_PIN, DIO_PIN_HIGH);
	DIO_voidSetPinValue(SSD_CONTROL_PORT, SSD3_CONTROL_PIN, DIO_PIN_HIGH);
	DIO_voidSetPinValue(SSD_CONTROL_PORT, SSD4_CONTROL_PIN, DIO_PIN_HIGH);

	Local_u8Num = num % 10;
	num = num / 10;

	Local_u8Counter = GET_BIT(Local_u8Num, 0);
	DIO_voidSetPinValue(SSD_CONTROL_PORT, SSD2_CONTROL_PIN, DIO_PIN_LOW);
	DIO_voidSetPinValue(SSD_PORT, SSD_PIN1, Local_u8Counter);

	Local_u8Counter = GET_BIT(Local_u8Num, 1);
	DIO_voidSetPinValue(SSD_PORT, SSD_PIN2, Local_u8Counter);

	Local_u8Counter = GET_BIT(Local_u8Num, 2);
	DIO_voidSetPinValue(SSD_PORT, SSD_PIN3, Local_u8Counter);

	Local_u8Counter = GET_BIT(Local_u8Num, 3);
	DIO_voidSetPinValue(SSD_PORT, SSD_PIN4, Local_u8Counter);
	_delay_ms(1);


	/********************************************CONTROL SSD3*******************************************/
	DIO_voidSetPinValue(SSD_CONTROL_PORT, SSD1_CONTROL_PIN, DIO_PIN_HIGH);
	DIO_voidSetPinValue(SSD_CONTROL_PORT, SSD2_CONTROL_PIN, DIO_PIN_HIGH);
	DIO_voidSetPinValue(SSD_CONTROL_PORT, SSD4_CONTROL_PIN, DIO_PIN_HIGH);

	Local_u8Num = num % 10;
	num = num / 10;

	Local_u8Counter = GET_BIT(Local_u8Num, 0);
	DIO_voidSetPinValue(SSD_CONTROL_PORT, SSD3_CONTROL_PIN, DIO_PIN_LOW);
	DIO_voidSetPinValue(SSD_PORT, SSD_PIN1, Local_u8Counter);

	Local_u8Counter = GET_BIT(Local_u8Num, 1);
	DIO_voidSetPinValue(SSD_PORT, SSD_PIN2, Local_u8Counter);

	Local_u8Counter = GET_BIT(Local_u8Num, 2);
	DIO_voidSetPinValue(SSD_PORT, SSD_PIN3, Local_u8Counter);

	Local_u8Counter = GET_BIT(Local_u8Num, 3);
	DIO_voidSetPinValue(SSD_PORT, SSD_PIN4, Local_u8Counter);
	_delay_ms(1);


	/********************************************CONTROL SSD4*******************************************/
	DIO_voidSetPinValue(SSD_CONTROL_PORT, SSD1_CONTROL_PIN, DIO_PIN_HIGH);
	DIO_voidSetPinValue(SSD_CONTROL_PORT, SSD2_CONTROL_PIN, DIO_PIN_HIGH);
	DIO_voidSetPinValue(SSD_CONTROL_PORT, SSD3_CONTROL_PIN, DIO_PIN_HIGH);

	Local_u8Num = num % 10;
	num = num / 10;

	Local_u8Counter = GET_BIT(Local_u8Num, 0);
	DIO_voidSetPinValue(SSD_CONTROL_PORT, SSD4_CONTROL_PIN, DIO_PIN_LOW);
	DIO_voidSetPinValue(SSD_PORT, SSD_PIN1, Local_u8Counter);

	Local_u8Counter = GET_BIT(Local_u8Num, 1);
	DIO_voidSetPinValue(SSD_PORT, SSD_PIN2, Local_u8Counter);

	Local_u8Counter = GET_BIT(Local_u8Num, 2);
	DIO_voidSetPinValue(SSD_PORT, SSD_PIN3, Local_u8Counter);

	Local_u8Counter = GET_BIT(Local_u8Num, 3);
	DIO_voidSetPinValue(SSD_PORT, SSD_PIN4, Local_u8Counter);
	_delay_ms(1);
}

