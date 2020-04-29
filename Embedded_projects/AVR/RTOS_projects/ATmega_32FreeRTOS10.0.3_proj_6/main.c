/*
 * GccApplication1.c
 *
 * Created: 4/7/2020 12:20:58 AM
 * Author : Laptop
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
//#include <util/delay.h>

#include "FreeRTOS.h"
#include "task.h"
#include "croutine.h"
#include "semphr.h"

void task1 (void* pvParameters);
void task2 (void* pvParameters);
void task3 (void* pvParameters);

UBaseType_t  TASK1_PRIORITY =(4);
UBaseType_t  TASK2_PRIORITY =(2);
UBaseType_t  TASK3_PRIORITY =(1);
TaskHandle_t task1_handle=NULL;
TaskHandle_t task2_handle=NULL;
TaskHandle_t task3_handle=NULL;
SemaphoreHandle_t mutex_handel_1=NULL;

void vApplicationIdleHook()
{
}

int main(void)
{
	DDRA=0XFF;
	PORTA=0x00;
	DDRB=0XFF;
	PORTB=0x00;
	xTaskCreate(task1, "pcTask1", configMINIMAL_STACK_SIZE, task1_handle, TASK1_PRIORITY, NULL);
	xTaskCreate(task2, "pcTask2", configMINIMAL_STACK_SIZE, task2_handle, TASK2_PRIORITY, NULL);
	xTaskCreate(task3, "pcTask3", configMINIMAL_STACK_SIZE, task3_handle, TASK3_PRIORITY, NULL);
	mutex_handel_1= xSemaphoreCreateMutex();
	vTaskStartScheduler();
	
	while(1)
	{
		
	}
	return 0;
}

void task1 (void* pvParameters)
{
	BaseType_t mutex_task1_take=0;
	BaseType_t mutex_task1_give=0;
	//mutex_handel_1= xSemaphoreCreateMutex();
	
	for(;;)
	{
		vTaskDelay(1000);
		mutex_task1_take = xSemaphoreTake(mutex_handel_1, (TickType_t)portMAX_DELAY);
		PORTA |= (1<<PINA7);
		if(mutex_task1_take == 1)
		{
			vTaskDelay(2000);
			PORTA &= ~(1<<PINA7);
		
			mutex_task1_give = xSemaphoreGive(mutex_handel_1);
		}

	}
}

void task2 (void* pvParameters)
{
	for(;;)
	{
		PORTB ^= (1<<PINB1);
		vTaskDelay(5000);
	}
}

void task3 (void* pvParameters)
{
	BaseType_t mutex_task3_take;
	mutex_task3_take = xSemaphoreTake(mutex_handel_1, (TickType_t)10);
		
	PORTA |= (1<< uxTaskPriorityGet( task3_handle ));
	vTaskDelay(3000);
	//PORTA &= ~(1<< uxTaskPriorityGet( task3_handle ));

	//mutex_task3_take = xSemaphoreGive(mutex_handel_1);
	
	for(;;)
	{

		//mutex_task3_take = xSemaphoreTake(mutex_handel_1, (TickType_t)10);
		/*
		PORTA |= (1<< uxTaskPriorityGet( task3_handle ));
		vTaskDelay(1000);
		PORTA &= ~(1<< uxTaskPriorityGet( task3_handle ));
		vTaskDelay(1000);
		*/

		if(mutex_task3_take == 1)
		{
			
			//vTaskDelay(10);
			PORTA |= (1<< uxTaskPriorityGet( task3_handle ));
			vTaskDelay(1000);
			PORTA &= ~(1<< uxTaskPriorityGet( task3_handle ));
			vTaskDelay(1000);
			mutex_task3_take = xSemaphoreGive(mutex_handel_1);
		}
	}
}

