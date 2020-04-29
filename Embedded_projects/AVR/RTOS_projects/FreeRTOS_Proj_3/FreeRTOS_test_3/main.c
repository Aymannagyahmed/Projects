/*
 * FreeRTOS_test_3.c
 *
 * Created: 4/21/2020 6:28:52 AM
 * Author : AymanW
 */ 

#define F_CPU 8000000ul
#include <avr/io.h>
#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"
#include "semphr.h"
#include "utils.h"
#define  TASK1_PRIORITY (3)
#define  TASK2_PRIORITY (2)
TaskHandle_t task1_handle=NULL;
TaskHandle_t task2_handle=NULL;
SemaphoreHandle_t sem_handel_1;
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
	xSemaphoreTake(sem_handel_1,0xffff);
	for (;;)
	{
		if(xSemaphoreTake(sem_handel_1,0xffff))
		{
			SET_BIT(PORTD,PIND0);
			vTaskDelay(5000);
			CLEAR_BIT(PORTD,PIND0);
			vTaskDelay(5000);
			SET_BIT(PORTB,PIND0);
			xSemaphoreGive(sem_handel_1);
		}
	}
}
/*Task2 Code */
void task2_code(void*pvParamter)
{
	for (;;)
	{
		SET_BIT(PORTD,PIND1);
		vTaskDelay(5000);
		CLEAR_BIT(PORTD,PIND1);
		vTaskDelay(5000);
		xSemaphoreGive(sem_handel_1);
	}
}
