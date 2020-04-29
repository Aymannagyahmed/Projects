/*
 * ex_interrupt.h
 *
 *  Created on: Apr 13, 2020
 *      Author: AymanW
 */

#ifndef EX_INTERRUPT_H_
#define EX_INTERRUPT_H_
#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>
#include "standerd_types.h"
#include"utils.h"
#define  NULL_PTR (void *)0
/*************************************************************************/
/*
//memory mapping
//Interrupt vector
//External interrupt Request 0
#define INT0_vect __vector_1
//External interrupt Request 1
#define INT1_vect __vector_2
//External interrupt Request 2
#define INT2_vect __vector_3
//External interrupt Request 3
#define INT3_vect __vector_4
//External interrupt Request 4
#define INT4_vect __vector_5
//External interrupt Request 5
#define INT5_vect __vector_6
*/
/*****************************************************************************/

//this line makes you to implement ISR
//you can remove this block of code if you (#include<avr/interrupt.h>)
/*
#  define ISR(vector)            \
    void vector (void) __attribute__ ((signal)\
    void vector (void)
*/


/*source of ISR or select which bin*/
typedef enum
{
	ex_int0=0,
	ex_int1,
	ex_int2
}ex_isr_surse_t;

/*Select (falling, rising edge or low level or any logical change) when isr occures*/
typedef enum
{
	low_level=0,
	any_logic_change,
	faling_edge,
	rising_edge
}trigger_edge_t;



/*Unmask the ISR, and you must put one of(ex_int0,ex_int1,ex_int2)*/
void EX_ISR_ENABLE(ex_isr_surse_t isr_surce);
/*Mask the ISR, and you must put one of(ex_int0,ex_int1,ex_int2)*/
void EX_ISR_DISABLE(ex_isr_surse_t isr_surce);
/*isr_surce one of(ex_int0,ex_int1,ex_int2)
 * and edge one of(low_level,any_logic_change,faling_edge,rising_edge)
 *  and ex_int2 use as only (faling_edge,rising_edge)
 */
void EX_ISR_TRIGGER_EDGE(ex_isr_surse_t isr_surce,trigger_edge_t edge);










#endif /* EX_INTERRUPT_H_ */
