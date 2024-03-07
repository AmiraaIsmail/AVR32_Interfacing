#ifndef PORT_REGISTER_H_
#define PORT_REGISTER_H_

#include "STD_TYPES.h"

 
#define  DDRA              *((volatile u8*)0X3A)
#define  DDRB              *((volatile u8*)0X37)
#define  DDRC              *((volatile u8*)0X34)
#define  DDRD              *((volatile u8*)0X31)

#define  PORTA             *((volatile u8*)0X3B)
#define  PORTB             *((volatile u8*)0X38)
#define  PORTC             *((volatile u8*)0X35)
#define  PORTD             *((volatile u8*)0X32)

 
#endif
