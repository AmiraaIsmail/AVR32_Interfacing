/**************************************************************************************/
/***********************************SSD_MUL_config.h***************************************/
/*********************************Created: 5/3/2024************************************/
/********************************Author: Amira Ismail**********************************/
/**************************************************************************************/

 
#ifndef SSD_CONFIG_H_
#define SSD_CONFIG_H_

#include"DIO_interface.h"


#define SSD_PORT			DIO_PORTB

#define SSD_PIN1			DIO_PIN0
#define SSD_PIN2	     	DIO_PIN1
#define SSD_PIN3		    DIO_PIN2
#define SSD_PIN4		    DIO_PIN4

#define SSD_CONTROL_PORT	DIO_PORTD
#define SSD1_CONTROL_PIN	DIO_PIN0
#define SSD2_CONTROL_PIN	DIO_PIN1
#define SSD3_CONTROL_PIN	DIO_PIN2
#define SSD4_CONTROL_PIN	DIO_PIN3

#endif /*SSD_CONFIG_H*/
