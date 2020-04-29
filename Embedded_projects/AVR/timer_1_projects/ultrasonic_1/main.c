/*
 * Created: 4/28/2020 8:44:29 PM
 *  Author: AymanW
 *
 * ultrasonic
 * use timer1 to test ultrasonic
 * timer1 in normal mode F_CPU 8Mega Hz prescaler 8
 *
 */ 

#define  F_CPU 8000000
#include "Std_Types.h"
#include "Mem_Map32.h"
#include "LCD.h"
#include "EX_Interrupt.h"
#include "Timers.h"
#include "Timers_Services.h"
#include "ultrasonic.h"
#include <util/delay.h>


int main(void)
{
	sei();
	DIO_Init();
	LCD_Init();
	Timer1_Init( TIMER1_NORMAL_MODE,TIMER1_SCALER_8,OCRA_DISCONNECTED,OCRB_DISCONNECTED);
	ULTRASONIC_Init();
	u16 distance;
	u8 x=0;
	
	while(1)
	{
		LCD_GoTo(0,13);
		LCD_WriteNumber(x);
		if(x==10)
		{
			x=0;
		}
		_delay_ms(300);
		distance=ULTRASONIC_GetDistance(ULTRASONIC_1);
		LCD_GoTo(0,6);
		LCD_WriteNumber(distance);
	
	}
return 0;
}



 

