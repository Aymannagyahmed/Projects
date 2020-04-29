/*
* servo motor
* F_CPU= 8Mega Hz, Prescaler= 8
* F_servo= 50 Hz, 1 milli sec -> 0 degre, 2 milli sec -> 180 degre
*
* T_one_tick= (8 Mega/8 ) == 1 Micro sec
* Using timer_0 to  F_servo= 50 Hz 
* F_pwm= F_servo= 50 Hz
* T_pwm= T_servo= 20,000 Micro sec
* 1000 Micro sec -> 0 degre, 2000 Micro sec -> 180 degre
* 
* timer_0 CTCmode 
*
*
*/

#define  F_CPU 8000000
#include "Std_Types.h"
#include "Mem_Map32.h"
#include "LCD.h"

#include "EX_Interrupt.h"
#include "Timers.h"
#include <util/delay.h>
volatile u16 t_on,t_total;

/*call back function of button EX_INT0 */
void button_1 (void)
{
	static u16 flag=0;
	if(flag==0)
	{
		t_on=10;
		flag=1;
	}
	if(flag==1)
	{
		t_on=15;
		flag=2;
	}
	if(flag==2)
	{
		t_on=20;
		flag=0;
	}
}

int main(void)
{
	sei();
	DIO_Init();
	LCD_Init();
	/* BUTTON enable EX_INT0, mode falling edge, and call back */
	EXI_Enable(EX_INT0);
	EXI_TriggerEdge(EX_INT0,FALLING_EDGE);
	LCD_Init();
	EXI_SetCallBack(EX_INT0,button_1);
	
	Timer0_Init(TIMER0_CTC_MODE,TIMER1_SCALER_8,OCO_DISCONNECTED);
	OCR0=100;
	t_total=200;
	/*to use Timer1 ISR*/
	Timer0_OC_InterruptEnable();
	
	/* degree 180 */
	
	
	//Timer1_Init(TIMER1_FASTPWM_ICR_TOP_MODE,TIMER1_SCALER_8,OCRA_NON_INVERTING,OCRB_INVERTING);
	/*will goo down after 100 tick*/
	//ICR1=100;
	
	/*first wave Duty_cycle*/
	//OCR1A=25;
	/*Second wave Duty_cycle*/
	//OCR1B=50;
	while(1)
	{
		
	}
return 0;
}

ISR(TIMER0_COMP_vect)
{
	static u8 isr_counter=0;
	isr_counter++;
	if(isr_counter==t_on)
	{
		CLEAR_BIT(PORTB,PINB0);
		//DIO_WritePin(PINB0,LOW);
	}
	else if(isr_counter==t_total)
	{
		SET_BIT(PORTB,PINB0);
		isr_counter=0;
	}

}