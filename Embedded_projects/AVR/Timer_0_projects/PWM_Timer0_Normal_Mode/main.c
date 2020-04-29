/*
 * PWM Timer0_Normal_Mode
 * F_CPU 8000000 and prescaler_8
 * PWM F of PWM =1KHz and Duty cycle 20%
 * Neglect context switching time
 *
 * Created: 4/23/2020 1:05:56 PM
 * Author : AymanW
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include "ex_interrupt.h"
#include "timer.h"
uint16_t isr_count =0;
uint16_t seconds =0;
uint16_t minutes =0;
uint16_t hours =0;
int main(void)
{
	/*Enable Global ISR*/
	sei();
	/*for LED'S */
	DDRA=0XFF;
	PORTA=0X00;
	/* for oscilloscope */
	DDRB=0XFF;
	PORTB=0X00;
	
	DDRD=0X00;
	/*(1) tick => 8/(8 Mega) == (1 Micro second)
	**************************************************************************************** // (1) tick == (1 Micro second) \\
	* Because off i start TCNT0 = 56
	**************************************************************************************** // 1 ISR== 200 tick== 200 Micro second \\
	*the ISR came every  [ (256 - TCNT0) tick => 200* (1 Micro second) == (200 Micro second) ]
	**************************************************************************************** // 1 ISR == (200 Micro second) \\
	* F PWM =1KHz => ( T= 1 milli second) => 1000 Micro seconed
	*Duty cycle 20% => (20*1000/100 = 200 Micro seconed on) and (800 Micro seconed of)
	*************************************************************************************** // (200 Micro on) and (800 Micro of) \\
	 */
    TIMER0_INIT(timer0_normal_mode,timer0_prescaler_8);
	TIMER0_INTERRUPT_ENABLE();
	/*to start counting from 0 */
	TCNT0=56;
	
    while (1) 
    {
    }
}

ISR(TIMER0_OVF_vect)
{
	/*to start timer from 56 every time */
	TCNT0=56;
	isr_count++;
	/*assume we start from low level*/
	if(isr_count==4)
	{
		SET_BIT(PORTB,PINB0);
	}
	/*end pf cycle */
	else if(isr_count==5)
	{
		CLEAR_BIT(PORTB,PINB0);
		isr_count=0;
	}
	
}