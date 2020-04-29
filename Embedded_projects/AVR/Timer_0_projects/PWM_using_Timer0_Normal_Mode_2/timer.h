/*
 * timer.h
 *
 * Created: 4/23/2020 1:06:39 PM
 *  Author: AymanW
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "avr/io.h"
#include "standerd_Types.h"
#include "utils.h"

typedef enum 
{
	timer0_normal_mode =0,
	timer0_phase_correct_mode,
	timer0_ctc_mode,
	timer0_fast_pwm_mode
}timer0_mode_t;

typedef enum
{
	timer0_stop =0,
	timer0_prescaler_1,
	timer0_prescaler_8,
	timer0_prescaler_64,
	timer0_prescaler_256,
	timer0_prescaler_1024,
	timer0_ex_clk_falling_edge,
	timer0_ex_clk_rising_edge
}timer0_prescaler_t;

void TIMER0_INIT(timer0_mode_t mode, timer0_prescaler_t prescaler);
void TIMER0_INTERRUPT_ENABLE();
void TIMER0_INTERRUPT_DISABLE();











#endif /* TIMER_H_ */