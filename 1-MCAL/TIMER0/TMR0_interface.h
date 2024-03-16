/**************************************************************************************/
/********************************TMR0_interface.h***************************************/
/**************************Created: 16/3/2024  10:30:00 PM*****************************/
/********************************Author: Amira Ismail**********************************/
/**************************************************************************************/

#ifndef TMR0_INTERFACE_H_
#define TMR0_INTERFACE_H_

#define TMR0_NORMAL_OVER_FLOW 		1
#define TMR0_CTC_COMPARE_MATCH		2


/*Options for TMR0 MODE
 * 1- TMR0_CTC MODE
 * 2- TMR0_NORMAL_MODE
 */
#define TMR0_MODE		TMR0_CTC_MODE


/*Options for TMR0_PRESCALER
 * 1- TMR0_NO_PRESCALING
 * 2- TMR0_PRESCALER_8
 * 3- TMR0_PRESCALER_64
 * 4- TMR0_PRESCALER_256
 * 5- TMR0_PRESCALER_1024
 */
#define TMR0_PRESCALER	TMR0_PRESCALER_64


void TMR0_voidInit(void);
void TMR0_voidStart(void);
void TMR0_voidStop(void);
//void TMR0_voidSetCallBackOVF(void(*Copy_pFunAction)(void));
void TMR0_voidSetCallBack(void(*Copy_pFunAction)(void), u8 Copy_u8InterruptSource);
void TMR0_voidSetDelay_ms_UsingCTC(u16 Copy_u16Delay_ms);

#endif  /*TMR0_INTERFACE_H_*/
