/**************************************************************************************/
/********************************EXTI_program.c****************************************/
/**************************Created: 3/3/2024  1:00 PM**********************************/
/********************************Author: Amira Ismail**********************************/
/**************************************************************************************/



#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "EXTI_register.h"
#include "EXTI_interface.h"

static void (*PRV_pFunCallBackINT0) (void) = NULL;
static void (*PRV_pFunCallBackINT1) (void) = NULL;
static void (*PRV_pFunCallBackINT2) (void) = NULL;

void EXTI_voidEnable (EXTI_Source copy_enumInterruptSource, EXTI_SenseControl copy_enumSenseControl)
{
	switch(copy_enumInterruptSource)
	{
	case EXTI_INT0:
		switch (copy_enumSenseControl)
		{
		case EXTI_RISING_EDGE:
			SET_BIT(MCUCR_REG, ISC00);
			SET_BIT(MCUCR_REG, ISC01);
			break;

		case EXTI_FALLING_EDGE:
			SET_BIT(MCUCR_REG, ISC01);
			CLR_BIT(MCUCR_REG, ISC00);
			break;

		case EXTI_LOW_LEVEL:
			CLR_BIT(MCUCR_REG, ISC01);
			CLR_BIT(MCUCR_REG, ISC00);
			break;

		case EXTI_ANY_LOGICAL_CHANGE:
			CLR_BIT(MCUCR_REG, ISC01);
			SET_BIT(MCUCR_REG, ISC00);
			break;
		}
		SET_BIT(GICR_REG, INT0);		//ENABLE EXTI_0
		break;

		case EXTI_INT1:
			switch (copy_enumSenseControl)
			{
			case EXTI_RISING_EDGE:
				SET_BIT(MCUCR_REG, ISC11);
				SET_BIT(MCUCR_REG, ISC10);
				break;

			case EXTI_FALLING_EDGE:
				SET_BIT(MCUCR_REG, ISC11);
				CLR_BIT(MCUCR_REG, ISC10);
				break;

			case EXTI_LOW_LEVEL:
				CLR_BIT(MCUCR_REG, ISC11);
				CLR_BIT(MCUCR_REG, ISC10);
				break;

			case EXTI_ANY_LOGICAL_CHANGE:
				CLR_BIT(MCUCR_REG, ISC11);
				SET_BIT(MCUCR_REG, ISC10);
				break;
			}
			SET_BIT(GICR_REG, INT1);	   //ENABLE EXTI_1
			break;

			case EXTI_INT2:
				switch(copy_enumSenseControl)
				{
				case EXTI_FALLING_EDGE:
					CLR_BIT(MCUCSR_REG, ISC2);
					break;
				case EXTI_RISING_EDGE:
					SET_BIT(MCUCSR_REG, ISC2);
					break;
				}
				SET_BIT(GICR_REG, INT2);	//ENABLE EXTI_2
				break;
	}
}

void EXTI_voidDisable (EXTI_Source copy_enumInterruptSource)
{
	switch (copy_enumInterruptSource)
	{
	case  EXTI_INT0:
		CLR_BIT(GICR_REG, INT0);
		break;

	case EXTI_INT1:
		CLR_BIT(GICR_REG, INT1);
		break;

	case EXTI_INT2:
		CLR_BIT(GICR_REG, INT2);
		break;
	}
}

void EXTI_voidSetCallBackInt0(void(*copy_pFunAction)(void))
{
	if(copy_pFunAction!=NULL)
	{
		PRV_pFunCallBackINT0 = copy_pFunAction;
	}
	else
	{
		//return error state
	}
}

void EXTI_voidSetCallBackInt1(void(*copy_pFunAction)(void))
{
	if(copy_pFunAction!=NULL)
	{
		PRV_pFunCallBackINT1 = copy_pFunAction;
	}
	else
	{
		//return error state
	}
}

void EXTI_voidSetCallBackInt2(void(*copy_pFunAction)(void))
{
	if(copy_pFunAction!=NULL)
	{
		PRV_pFunCallBackINT2 = copy_pFunAction;
	}
	else
	{
		//return error state
	}
}

void __vector_1(void) __attribute__((signal));    //EXTI_0
void __vector_1(void)
{
	if(PRV_pFunCallBackINT0 != NULL)
	{
		PRV_pFunCallBackINT0();
	}
}

void __vector_2(void) __attribute__((signal));    //EXTI_1
void __vector_2(void)
{
	if(PRV_pFunCallBackINT1 != NULL)
	{
		PRV_pFunCallBackINT1();
	}
}

void __vector_3(void) __attribute__((signal));     //EXTI_2
void __vector_3(void)
{
	if(PRV_pFunCallBackINT2 != NULL)
	{
		PRV_pFunCallBackINT2();
	}
}
