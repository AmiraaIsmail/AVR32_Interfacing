/**************************************************************************************/
/********************************EXTI_interface.h**************************************/
/**************************Created: 3/3/2024  1:00 PM**********************************/
/********************************Author: Amira Ismail**********************************/
/**************************************************************************************/


 
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_register.h"


typedef enum
{
	EXTI_INT0 = 0,
	EXTI_INT1,
	EXTI_INT2,
}EXTI_Source; 

typedef enum
{
	EXTI_RISING_EDGE = 0,
	EXTI_FALLING_EDGE,
	EXTI_LOW_LEVEL,
	EXTI_ANY_LOGICAL_CHANGE,
}EXTI_SenseControl;


void EXTI_voidEnable  (EXTI_Source copy_enumInterruptSource, EXTI_SenseControl copy_enumSenseControl);
void EXTI_voidDisable (EXTI_Source copy_enumInterruptSource); 
void EXTI_voidSetCallBackInt0(void(*copy_pFunAction)(void));
void EXTI_voidSetCallBackInt1(void(*copy_pFunAction)(void));
void EXTI_voidSetCallBackInt2(void(*copy_pFunAction)(void));


 
 
 
#endif		/*EXTI_INTERFACE_H_*/
 
