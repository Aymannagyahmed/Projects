/*
 * PWM using Timer0_Normal_Mode
 * PINB0	PWM1 =5 KHz	Duty cycle 25%
 * F_CPU 8000000 and prescaler_8
 * Neglect context switching time
 *
 * Created: 4/23/2020 1:05:56 PM
 * Author : AymanW
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include "ex_interrupt.h"
#include "timer.h"

int main(void)
{
	/*Enable Global ISR*/
	sei();
	/* for oscilloscope */
	DDRB=0XFF;
	PORTB=0X00;
	/*(1) tick => 8/(8 Mega) == (1 Micro second)
	**************************************************************************************** // (1) tick == (1 Micro second) \\
	* Because off i start TCNT0 = 106
	*the ISR came every  [ (256 - TCNT0) tick => 150* (1 Micro second) == (200 Micro second) ]
	**************************************************************************************** // 1 ISR== 150 tick== 150 Micro second \\
	* F PWM = 5 KHz => ( T= 0.2 milli second) => 200 Micro seconed
	*Duty cycle 25% => (25*200,000/100 = 50,000 Micro seconed on) and (150,000 Micro seconed of)
	*************************************************************************************** // (50,000 Micro on) and (150,000 Micro of) \\
	*/
    TIMER0_INIT(timer0_normal_mode,timer0_prescaler_8);
	TIMER0_INTERRUPT_ENABLE();
	/*to start counting from 106 */
	TCNT0=106;
	
    while (1) 
    {
    }
}

ISR(TIMER0_OVF_vect)
{
	static uint16_t flag=0;
	/*assume we start from low level*/
	if(flag==0)
	{
		TCNT0=206;
		SET_BIT(PORTB,PINB0);
		flag=1;
	}
	else
	{
		TCNT0=106;
		CLEAR_BIT(PORTB,PINB0);
		flag=0;
	}
}