/*
 * FreeRTOS_test_4.c
 *
 * Created: 4/21/2020 8:25:52 AM
 * Author : AymanW
 */ 


#define F_CPU 8000000ul
#include <avr/io.h>
#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"
#include "semphr.h"
#include "utils.h"
UBaseType_t  TASK1_PRIORITY =(3);
UBaseType_t  TASK2_PRIORITY =(1);
TaskHandle_t task1_handle=NULL;
TaskHandle_t task2_handle=NULL;
SemaphoreHandle_t mutex_handel_1=NULL;
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
	
	mutex_handel_1=xSemaphoreCreateMutex();/****************************************there is a problem*********************/
	if(mutex_handel_1 !=NULL)
	{
		PORTB=0x01;
	}
	for (;;)
	{
		/*
		unsigned char mutex_flag=xSemaphoreTake(mutex_handel_1, (TickType_t)(0xffff));
		if(mutex_flag==1)
		{
			CLEAR_BIT(PORTD,PIND4);
			SET_BIT(PORTD,PIND4);
			vTaskDelay(2000);
			CLEAR_BIT(PORTD,PIND4);
			vTaskDelay(2000);
			xSemaphoreGive(mutex_handel_1);
		}
		*/
	}
}
/*Task2 Code */
void task2_code(void*pvParamter)
{
	/*
	int x=0;
	unsigned char m_flag= xSemaphoreTake(mutex_handel_1, (TickType_t)(0xffff));
	*/
	for (;;)
	{
		/*
		TOOGLE_REG(PORTD);
		x++;
		if(m_flag==1)
		{
			CLEAR_BIT(PORTD,x);
			SET_BIT(PORTD,x);
			vTaskDelay(5000);
			CLEAR_BIT(PORTD,x);
			vTaskDelay(5000);
			SET_BIT(PORTD,x);
			vTaskDelay(5000);
			xSemaphoreGive(mutex_handel_1);
		}
		*/
	}
}
