/*
 * Digital clock using Timer0-> Normal mode and prescaler_64
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
	sei();
	DDRA=0XFF;
	PORTA=0X00;
	
	DDRB=0XFF;
	PORTB=0X00;
	
	DDRD=0X00;
	/*(1) tick => 64/(8 Mega) == (8 Micro second)
	***************************************************************************************** // (1) tick == (8 Micro second) \\
	*Because off i start TCNT0 = 0
	*the ISR cam every  [ (256 - TCNT0) tick => 256* (8 Micro second) == (2048 Micro second) ]
	**************************************************************************************** // 1 ISR == (2048 Micro second) \\
	*( 1 second) == (1000000 Micro)
	*( 1 second == 1000000/ ( 2048 Micro => time of one ISR) == 488 ISR
	*************************************************************************************** // 1 second == 488 ISR \\
	 */
    TIMER0_INIT(timer0_normal_mode,timer0_prescaler_64);
	TIMER0_INTERRUPT_ENABLE();
	/*to start counting from 0 */
	TCNT0=0;
	
    while (1) 
    {
    }
}

ISR(TIMER0_OVF_vect)
{
	isr_count++;
	if(isr_count==488)
	{
		isr_count=0;
		TOOGLE_BIT(PORTA,PINA0);
		seconds++;
	}
	if(seconds==60)
	{
		seconds=0;
		minutes++;
		SET_BIT(PORTA,minutes);
	}
	if(minutes==60)
	{
		minutes=0;
		hours++;
	}
	if(hours==24)
	{
		hours=0;
		minutes=0;
		seconds=0;
	}
}