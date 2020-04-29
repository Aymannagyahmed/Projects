/*
* Using timer_1 in (FASTPWM_ICR_TOP mode) to generate 2 waves 
* 
* wave_1 F_pwm = (F_timer/(top_tick))== (1,000,000 / 100) =10,000Hz
* ICR1 = top
* wave_1 OCRA =( (Duty_cycle*100) / top== 25/100
* 
* wave_2 F_pwm = (F_timer/(top_tick))== (1,000,000 / 100) =10,000Hz
* wave_2 OCRB =( (Duty_cycle*100) / top== 50/100
*
*/

#define  F_CPU 8000000
#include "Std_Types.h"
#include "Mem_Map32.h"
#include "LCD.h"

#include "EX_Interrupt.h"
#include "Timers.h"
volatile u32 t_total;

int main(void)
{
	sei();
	DIO_Init();
	
	Timer1_Init(TIMER1_FASTPWM_ICR_TOP_MODE,TIMER1_SCALER_8,OCRA_NON_INVERTING,OCRB_INVERTING);
	/*will goo down after 100 tick*/
	ICR1=100;
	/*first wave Duty_cycle*/
	OCR1A=25;
	/*Second wave Duty_cycle*/
	OCR1B=50;
	
	while(1)
	{
		;
	
	}
return 0;
}

 
 

