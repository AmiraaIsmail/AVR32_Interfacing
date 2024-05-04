/**************************************************************************************/
/***********************************PORT_config.h**************************************/
/**************************Created: 1/3/2024  8:00:00 PM*******************************/
/********************************Author: Amira Ismail**********************************/
/**************************************************************************************/

#ifndef PORT_CONFIG_H_
#define PORT_CONFIG_H_

/*CHOOSE : 0 FOR INPUT 
		   1 FOR OUTPUT*/
		   
		   
#define PORTA_PIN0_DIR    1
#define PORTA_PIN1_DIR    1
#define PORTA_PIN2_DIR    1
#define PORTA_PIN3_DIR    1
#define PORTA_PIN4_DIR    1
#define PORTA_PIN5_DIR    1
#define PORTA_PIN6_DIR    1
#define PORTA_PIN7_DIR    1

#define PORTB_PIN0_DIR    1
#define PORTB_PIN1_DIR    1
#define PORTB_PIN2_DIR    1
#define PORTB_PIN3_DIR    1
#define PORTB_PIN4_DIR    1
#define PORTB_PIN5_DIR    1
#define PORTB_PIN6_DIR    1
#define PORTB_PIN7_DIR    1

#define PORTC_PIN0_DIR    1
#define PORTC_PIN1_DIR    1
#define PORTC_PIN2_DIR    1
#define PORTC_PIN3_DIR    1
#define PORTC_PIN4_DIR    1
#define PORTC_PIN5_DIR    1
#define PORTC_PIN6_DIR    1
#define PORTC_PIN7_DIR    1

#define PORTD_PIN0_DIR    0
#define PORTD_PIN1_DIR    0
#define PORTD_PIN2_DIR    0
#define PORTD_PIN3_DIR    0
#define PORTD_PIN4_DIR    0
#define PORTD_PIN5_DIR    0
#define PORTD_PIN6_DIR    0
#define PORTD_PIN7_DIR    0

/*CHOOSE INIT VALUE 
  IF DIR (OUT)   1->HIGH 
                 0->LOW 
  ELSE DIR (IN)  1->PULL UP
                 0->FLOATING  */
				 
				 

#define PORTA_PIN0_VAL    0
#define PORTA_PIN1_VAL    0
#define PORTA_PIN2_VAL    1
#define PORTA_PIN3_VAL    0
#define PORTA_PIN4_VAL    0
#define PORTA_PIN5_VAL    0
#define PORTA_PIN6_VAL    0
#define PORTA_PIN7_VAL    0

#define PORTB_PIN0_VAL    0
#define PORTB_PIN1_VAL    0
#define PORTB_PIN2_VAL    0
#define PORTB_PIN3_VAL    0
#define PORTB_PIN4_VAL    0
#define PORTB_PIN5_VAL    0
#define PORTB_PIN6_VAL    0
#define PORTB_PIN7_VAL    0


#define PORTC_PIN0_VAL    0
#define PORTC_PIN1_VAL    0
#define PORTC_PIN2_VAL    0
#define PORTC_PIN3_VAL    0
#define PORTC_PIN4_VAL    0
#define PORTC_PIN5_VAL    0
#define PORTC_PIN6_VAL    0
#define PORTC_PIN7_VAL    0


#define PORTD_PIN0_VAL    0
#define PORTD_PIN1_VAL    0
#define PORTD_PIN2_VAL    0
#define PORTD_PIN3_VAL    0
#define PORTD_PIN4_VAL    0
#define PORTD_PIN5_VAL    0
#define PORTD_PIN6_VAL    0
#define PORTD_PIN7_VAL    0


#endif
