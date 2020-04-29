/*
* servo motor
* F_CPU= 8Mega Hz, Prescaler= 8
* F_servo= 50 Hz, 1 milli sec -> 0 degre, 2 milli sec -> 180 degre
*
* T_one_tick= (8 Mega/8 ) == 1 Micro sec
* Using timer_1 to  control angle of servo motor using button 
* F_pwm on OCRA 
*
*
*/

#define  F_CPU 8000000UL
#include "Std_Types.h"
#include "Mem_Map32.h"
#include "DIO_Interface.h"


#include "EX_Interrupt.h"
#include "Timers.h"



/*call back function of button EX_INT0 */
void button_1 (void)
{
	static u16 angle=0,step=9;
	angle= angle + step;
	/*to convert between angle and value put in OCFR1A*/
	OCR1A=( ((u32)angle*1000)/180 )+999;
}
int main(void)
{
	/*enable global interrupt */
	sei();
	/* initiate DIO*/
	DIO_Init();
	/* BUTTON enable EX_INT0, mode falling edge, and call back */
	EXI_Enable(EX_INT0);
	EXI_TriggerEdge(EX_INT0,FALLING_EDGE);
	EXI_SetCallBack(EX_INT0,button_1);
	/*Timer_1 initialization */
	Timer1_Init(TIMER1_FASTPWM_ICR_TOP_MODE,TIMER1_SCALER_8,OCRA_NON_INVERTING,OCRB_NON_INVERTING);
	/*20,000 tick*/
	/* 19999 because of it take action in the next tick*/
	ICR1=19999;
	while(1)
	{
		
	}
return 0;
}
