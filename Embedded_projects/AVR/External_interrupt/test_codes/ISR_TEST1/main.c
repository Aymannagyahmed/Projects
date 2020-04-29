/*
 * main.c
 *
 *  Created on: Apr 12, 2020
 *      Author: AymanW
 */

#include "ex_interrupt.h"

void func1(void)
{
	/*
	if(butten1==1)
	{

	}
	*/
}
void func2(void)
{
	/*
	if(butten2==1)
	{

	}
	*/
}
void func3(void)
{
	/*
	if(butten3==1)
	{

	}
	*/
}
void main(void)
{
	/*gpio init*/
	DDRB=0XFF;
	PORTB=0XFF;

	//Enable global ISR
	sei();
	//which ISR do you want and when it will happen
	EX_ISR_TRIGGER_EDGE(ex_int0,rising_edge);
	//EX_ISR_ENABLE(ex_int0);

/*************************************************calback of isr*******************************/
	EX_ISR_SET_CALLBACK(ex_int0,func1);
	EX_ISR_SET_CALLBACK(ex_int1,func2);
	EX_ISR_SET_CALLBACK(ex_int2,func3);
/**********************************************enable must be the last instruction**************/
	EX_ISR_ENABLE(ex_int0);
	while(1)
	{
		PORTB = PORTB^(0xff);
		_delay_ms(800);

	}

}






