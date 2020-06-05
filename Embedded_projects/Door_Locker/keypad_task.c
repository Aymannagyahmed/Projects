/*
 * keypad_task.c
 *
 * Created: 5/27/2020 12:35:29 AM
 *  Author: AymanW
 */ 
#include "keypad_task.h"
QueueHandle_t KEYPAD_QUEUE_HANDLE=NULL;
UBaseType_t KEYPAD_QUEUE_LENGTH = (12);
UBaseType_t KEYPAD_QUEUE_ELEMENT_SIZE = sizeof(uint8_t);
SemaphoreHandle_t KEYPAD_SEMAPHORE_HANDLE=NULL;


void KEYPAD_TASK (void* pvParameters)
{
	uint8_t key='-';
	uint8_t last_key='-';
	for (;;)
	{
		if(KEYPAD_SEMAPHORE_HANDLE!=NULL)
		{
			key = KEYPAD_getKey();
			if(key=='-' || key==last_key)
			{
				vTaskDelay(50);
			}
			else
			{
				if( (xSemaphoreTake(KEYPAD_SEMAPHORE_HANDLE,portMAX_DELAY)) == pdTRUE)
				{
					xQueueSend(KEYPAD_QUEUE_HANDLE,(uint8_t *)&key,portMAX_DELAY);
				}
			}
			last_key=key;
			
		}
	}
}