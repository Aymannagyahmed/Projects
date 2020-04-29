/*
 * 3 pulses PWM Timer0_Normal_Mode
 * PINB0	PWM1 =100 Hz	Duty cycle 50%
 * PINB1	PWM2 =50  Hz	Duty cycle 50%
 * PINB2	PWM3 =20  Hz	Duty cycle 50%
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
uint8_t isr_count =0;
uint8_t num_of_milli_seconds =0;

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
	*the ISR came every  [ (256 - TCNT0) tick => 200* (1 Micro second) == (200 Micro second) ]
	**************************************************************************************** // 1 ISR== 200 tick== 200 Micro second \\
	* F PWM_1 =100Hz => ( T= 10 milli second) => 10,000 Micro seconed
	*Duty cycle 50% => (50*10000/100 = 5000 Micro seconed on) and (5000 Micro seconed of)
	*************************************************************************************** // (5000 Micro on) and (5000 Micro of) \\
	* F PWM_2 =50Hz => ( T= 20 milli second) => 20,000 Micro seconed
	*Duty cycle 50% => (50*10000/100 = 10,000 Micro seconed on) and (10,000 Micro seconed of)
	*************************************************************************************** // (5000 Micro on) and (5000 Micro of) \\
	* F PWM_3 =20Hz => ( T= 50 milli second) => 50,000 Micro seconed
	*Duty cycle 50% => (50*10000/100 = 25,000 Micro seconed on) and (25,000 Micro seconed of)
	*************************************************************************************** // (25,000 Micro on) and (25,000 Micro of) \\
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
	if(isr_count==5)
	{
		num_of_milli_seconds++;
		isr_count=0;
		/********PWM 1 ************/
		if(num_of_milli_seconds%5==0)
		{
			TOOGLE_BIT(PORTB,PINB0);
		}
		/********PWM 2 ************/
		if(num_of_milli_seconds%10==0)
		{
			TOOGLE_BIT(PORTB,PINB1);
		}
		/********PWM 3************/
		if(num_of_milli_seconds%25==0)
		{
			TOOGLE_BIT(PORTB,PINB2);
		}
		/*50 milli that number because every pwm 1,2,3 can devidded on it*/
		if(num_of_milli_seconds%50==0)
		{
			num_of_milli_seconds=0;
		}
	}
}