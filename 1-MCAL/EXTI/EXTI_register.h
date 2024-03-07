/**************************************************************************************/
/********************************EXTI_register.h***************************************/
/**************************Created: 3/3/2024  1:00 PM**********************************/
/********************************Author: Amira Ismail**********************************/
/**************************************************************************************/


 
#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_

#define MCUCR_REG			*((volatile u8*)0X55)
#define ISC11				3
#define ISC10				2
#define ISC01				1
#define ISC00				0


#define MCUCSR_REG			*((volatile u8*)0x54)
#define ISC2				6


#define GICR_REG			*((volatile u8*)0x5B)
#define INT1				7
#define INT0				6
#define INT2				5


#define GIFR_REG			*((volatile u8*)0x5A)
#define INTF0				6
#define INTF1				7
#define INTF2				5


#endif		/*EXTI_REGISTER_H_*/
 
