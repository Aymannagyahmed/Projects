/*
 * FreeRTOS_test_2.c
 *
 * Created: 4/21/2020 4:18:24 AM
 * Author : AymanW
 */ 

#define F_CPU 8000000ul
#include <avr/io.h>
#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"
#include "queue.h"
#include "utils.h"
#define  TASK1_PRIORITY (3)
#define  TASK2_PRIORITY (2)
TaskHandle_t task1_handle=NULL;
TaskHandle_t task2_handle=NULL;
QueueHandle_t Queue_1;
void task1_code(void*pvParamter);
void task2_code(void*pvParamter);
BaseType_t counter_Que1=0;
int main(void)
{
	DDRB=0XFF;
	PORTB=0X00;
	DDRD=0XFF;
	PORTD=0X00;
	xTaskCreate(task1_code,"pcTask1",85,task1_handle,TASK1_PRIORITY,NULL);
	xTaskCreate(task2_code,"pcTask2",85,task2_handle,TASK2_PRIORITY,NULL);
	vTaskStartScheduler();
	/* Replace with your application code */
	while (1)
	{
		;
	}
	return 0;
}
/*Task1 Code */
void task1_code(void*pvParamter)
{
	TickType_t LastWake;
	const TickType_t freq=100;
	LastWake= xTaskGetTickCount();
	BaseType_t flag_Que1;
	Queue_1= xQueueCreate( 10, sizeof(unsigned char ));
	PORTB |= (1<<0);
	for (;;)
	{
		counter_Que1++;
		if(counter_Que1<10)
		{
			flag_Que1= xQueueSend(Queue_1, (void *) &counter_Que1, (TickType_t)10);
			vTaskDelayUntil(&LastWake,800);
		}
		else if(counter_Que1==10)
		{
			PORTB = 0x00;
			vTaskDelayUntil(&LastWake,300);
			PORTB |= (1<<2);
			vTaskDelayUntil(&LastWake,100);
			vTaskSuspend(task1_handle);
		}
		else
		{
			;
		}
	}
}

/*Task2 Code */
void task2_code(void*pvParamter)
{
	TickType_t LastWake2;
	const TickType_t freq2=4000;
	LastWake2= xTaskGetTickCount();
	BaseType_t flag_Que1;
	PORTB |= (1<<1);
	for (;;)
	{
		if(counter_Que1==10)
		{
			for(counter_Que1=9;counter_Que1>=0;counter_Que1--)
			{
			TOOGLE_BIT(PORTB,PINB3);
			vTaskDelayUntil(&LastWake2,1000);
			flag_Que1=(unsigned int) xQueueReceive(Queue_1,&counter_Que1, (TickType_t)10);
			vTaskDelayUntil(&LastWake2,freq2);	
			}
		}
		PORTB |= (1<<3);
	}
}