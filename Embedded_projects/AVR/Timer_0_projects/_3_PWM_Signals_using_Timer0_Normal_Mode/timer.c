/*
 * timer.c
 *
 * Created: 4/23/2020 1:06:25 PM
 *  Author: AymanW
 */ 

#include "timer.h"

void TIMER0_INIT(timer0_mode_t mode, timer0_prescaler_t prescaler)
{
/************************************* choosing mode *******************************************************************************/
	switch(mode)
	{
		case timer0_normal_mode:
		CLEAR_BIT(TCCR0,WGM00);
		CLEAR_BIT(TCCR0,WGM01);
		break;
		
		case timer0_phase_correct_mode:
		SET_BIT(TCCR0,WGM00);
		CLEAR_BIT(TCCR0,WGM01);
		break;
		
		case timer0_ctc_mode:
		CLEAR_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		break;

		case timer0_fast_pwm_mode:
		SET_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		break;
		
		default:
		break;
	}
	
/********************************************* choosing Prescaler *****************************************************************************************/
	switch(prescaler)
	{
		case timer0_stop:
		CLEAR_BIT(TCCR0,CS00);
		CLEAR_BIT(TCCR0,CS01);
		CLEAR_BIT(TCCR0,CS02);
		break;
		
		case timer0_prescaler_1:
		SET_BIT(TCCR0,CS00);
		CLEAR_BIT(TCCR0,CS01);
		CLEAR_BIT(TCCR0,CS02);
		break;		
		
		case timer0_prescaler_8:
		CLEAR_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		CLEAR_BIT(TCCR0,CS02);
		break;

		case timer0_prescaler_64:
		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		CLEAR_BIT(TCCR0,CS02);
		break;
		
		case timer0_prescaler_256:
		CLEAR_BIT(TCCR0,CS00);
		CLEAR_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
		break;
		
		case timer0_prescaler_1024:
		SET_BIT(TCCR0,CS00);
		CLEAR_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
		break;
		
		case timer0_ex_clk_falling_edge:
		CLEAR_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
		break;
		case timer0_ex_clk_rising_edge:
		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
		break;
		default :
		break;
	}
	
}



void TIMER0_INTERRUPT_ENABLE()
{
	SET_BIT(TIMSK,TOIE0);
}
void TIMER0_INTERRUPT_DISABLE()
{
	CLEAR_BIT(TIMSK,TOIE0);
}