/*
 * FreeRTOS_test_5.c
 *
 * Created: 4/22/2020 7:56:57 AM
 * Author : AymanW
 */ 

#define F_CPU 8000000ul
#include <avr/io.h>
#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"
#include "semphr.h"
#include "utils.h"
UBaseType_t  TASK1_PRIORITY =(2);
UBaseType_t  TASK2_PRIORITY =(1);
TaskHandle_t task1_handle=NULL;
TaskHandle_t task2_handle=NULL;
SemaphoreHandle_t sem_handel_1;
SemaphoreHandle_t mutex_handel_1;
void task1_code(void*pvParamter);
void task2_code(void*pvParamter);

int main(void)
{
	DDRB=0XFF;
	PORTB=0X00;
	DDRD=0XFF;
	PORTD=0X00;
	xTaskCreate(task1_code,"pcTask1",85,task1_handle,TASK1_PRIORITY,NULL);
	xTaskCreate(task2_code,"pcTask2",85,task2_handle,TASK2_PRIORITY,NULL);
	vSemaphoreCreateBinary(sem_handel_1);
	
	vTaskStartScheduler();
	while (1)
	{
		;
	}
	return 0;
}
/*Task1 Code  */
void task1_code(void*pvParamter)
{
	sem_handel_1=xSemaphoreCreateMutex();
	for (;;)
	{
		if(sem_handel_1==NULL)
		{
			TOOGLE_BIT(PORTB,PINB0);
			vTaskDelay(2000);
		}
		else
		{
			TOOGLE_BIT(PORTD,PINB0);
			vTaskDelay(2000);
		}
	}
}
/*Task2 Code */
void task2_code(void*pvParamter)
{
	for (;;)
	{

	}
}
