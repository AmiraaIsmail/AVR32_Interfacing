/**************************************************************************************/
/********************************TMR0_config.h***************************************/
/**************************Created: 16/3/2024  10:30:00 PM*****************************/
/********************************Author: Amira Ismail**********************************/
/**************************************************************************************/

#ifndef TMR0_CONFIG_H_
#define TMR0_CONFIG_H_


/*if we need to tog led every 1 sec and OVF TIME is 1024
 * THEN OVF = 100000000/1024 = 976.56, COUNTER = 977
 * THEN PRELOAD VALUE = (1-0.56)*256 = 113
 */

#define TMR0_PRELOAD_VALUE		113
#define TMR0_OFV_COUNTER		977
#define TMR0_Compare_Value		249
#define TMR0_CTC_COUNTER		1500




#endif  /*TMR0_CONFIG_H_*/
