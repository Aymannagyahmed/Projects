/*
 * Created: 4/28/2020 8:44:29 PM
 *  Author: AymanW
 *
 * ultrasonic
 * use timer1 to read 4 ultrasonic
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
	
	while(1)
	{
		/*Ultrasonic 1 PINC0*/
		distance=ULTRASONIC_GetDistance(ULTRASONIC_1);
		LCD_GoTo(1,0);
		LCD_WriteNumber(distance);
		/*Ultrasonic 2 PINC1*/
		distance=ULTRASONIC_GetDistance(ULTRASONIC_2);
		LCD_WriteNumber(distance);
		LCD_GoTo(1,4);
		/*Ultrasonic 3 PINC2*/
		distance=ULTRASONIC_GetDistance(ULTRASONIC_3);
		LCD_GoTo(1,8);
		LCD_WriteNumber(distance);
		/*Ultrasonic 4 PINC3*/
		distance=ULTRASONIC_GetDistance(ULTRASONIC_4);
		LCD_GoTo(1,12);
		LCD_WriteNumber(distance);
	
	}
return 0;
}



 

