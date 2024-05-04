/**************************************************************************************/
/********************************TMR0_program.c***************************************/
/**************************Created: 16/3/2024  10:30:00 PM*****************************/
/********************************Author: Amira Ismail**********************************/
/**************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include"TMR0_interface.h"
#include"TMR0_config.h"
#include"TMR0_private.h"
#include"TMR0_register.h"


static void (*PRV_pFunCallBackOVF)(void) = NULL;
static void (*PRV_pFunCallBackCTC)(void) = NULL;
static u16 PRV_ctcCounter;

void TMR0_voidInit(void)
{
#if TMR0_MODE == TMR0_CTC_MODE
	//SELECT CTC MODE
	CLR_BIT(TCCR0_REG, WGM00);
	SET_BIT(TCCR0_REG, WGM01);

	//INIT TIMER WITH OUTPUT COMPARE VALUE
	OCR0_REG = TMR0_Compare_Value;

	//Enable OC Interrupt
	SET_BIT(TIMSK_REG, OCIE0);

#elif TMR0_MODE == TMR0_NORMAL_MODE
	//SELECT NORMAL MODE
	CLR_BIT(TCCR0_REG, WGM00);
	CLR_BIT(TCCR0_REG, WGM01);

	//INIT TIMER WITH PRELOAD VALUE
	TCNT0_REG = TMR0_PRELOAD_VALUE;

	//Enable OVF Interrupt
	SET_BIT(TIMSK_REG, TOIE0);

#endif
}

void TMR0_voidStart(void)
{
	//CHOOSE PRESCALER
#if TMR0_PRESCALER == TMR0_NO_PRESCALING
	SET_BIT(TCCR0_REG,  CS00);
	CLR_BIT(TCCR0_REG,  CS01);
	CLR_BIT(TCCR0_REG,  CS02);

#elif TMR0_PRESCALER == TMR0_PRESCALER_8
	CLR_BIT(TCCR0_REG,  CS00);
	SET_BIT(TCCR0_REG,  CS01);
	CLR_BIT(TCCR0_REG,  CS02);

#elif TMR0_PRESCALER == TMR0_PRESCALER_64
	SET_BIT(TCCR0_REG,  CS00);
	SET_BIT(TCCR0_REG,  CS01);
	CLR_BIT(TCCR0_REG,  CS02);

#elif TMR0_PRESCALER == TMR0_PRESCALER_256
	CLR_BIT(TCCR0_REG,  CS00);
	CLR_BIT(TCCR0_REG,  CS01);
	SET_BIT(TCCR0_REG,  CS02);

#elif TMR0_PRESCALER == TMR0_PRESCALER_1024
	SET_BIT(TCCR0_REG,  CS00);
	CLR_BIT(TCCR0_REG,  CS01);
	SET_BIT(TCCR0_REG,  CS02);
#endif
}

void TMR0_voidStop(void)
{
	CLR_BIT(TCCR0_REG,  CS00);
	CLR_BIT(TCCR0_REG,  CS01);
	CLR_BIT(TCCR0_REG,  CS02);
}

/*void TMR0_voidSetCallBackOVF(void(*Copy_pFunAction)(void))
{
	if (Copy_pFunAction!=NULL)
	{
		PRV_pFunCallBackOVF = Copy_pFunAction;
	}
	else
	{
		//
	}
}*/

void TMR0_voidSetCallBack(void(*Copy_pFunAction)(void), u8 Copy_u8InterruptSource)
{
	if (Copy_pFunAction!=NULL)
	{
		switch(Copy_u8InterruptSource)
		{
		case TMR0_NORMAL_OVER_FLOW:
			PRV_pFunCallBackOVF = Copy_pFunAction;
			break;

		case TMR0_CTC_COMPARE_MATCH:
			PRV_pFunCallBackCTC = Copy_pFunAction;
			break;
		}
	}
	else
	{
		//
	}
}

void TMR0_voidSetDelay_ms_UsingCTC(u16 Copy_u16Delay_ms)
{
	//Under Condition Tick Time = 4us
	OCR0_REG = 249;
	PRV_ctcCounter = Copy_u16Delay_ms;
}

void __vector_11 (void) __attribute__((signal));
void __vector_11 (void)
{
	static u16 Local_u16OFVCounter = 0;
	Local_u16OFVCounter++;

	if(TMR0_OFV_COUNTER == Local_u16OFVCounter)
	{
		//Init Counter with Preload Value
		TCNT0_REG = TMR0_PRELOAD_VALUE;

		//Clear Counter
		Local_u16OFVCounter = 0;

		//CALL ACTION
		if(PRV_pFunCallBackOVF!=NULL)
		{
			PRV_pFunCallBackOVF();
		}

	}
}

void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	static u16 Local_u16CTCCounter = 0;
	Local_u16CTCCounter++;

	if(PRV_ctcCounter == Local_u16CTCCounter)
	{
		//Clear Counter
		Local_u16CTCCounter = 0;

		//CALL ACTION
		if(PRV_pFunCallBackCTC!=NULL)
		{
			PRV_pFunCallBackCTC();
		}

	}
}
