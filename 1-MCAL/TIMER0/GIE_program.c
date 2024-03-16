/*
 * GIE_program.c
 *
 * Created: 3/3/2024  2:10:04 PM
 *  Author: Amira Ismail
 *
 */ 
 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE_interface.h"
#include "GIE_register.h"


void GIE_voidEnable(void)
{
	SET_BIT(SREG,SREG_I);
}

void GIE_voidDisable(void)
{
	CLR_BIT(SREG,SREG_I);
}
