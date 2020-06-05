/*
 * keypad_task.h
 *
 * Created: 5/27/2020 12:35:03 AM
 *  Author: AymanW
 */ 


#ifndef KEYPAD_TASK_H_
#define KEYPAD_TASK_H_
#include "FreeRTOS.h"
#include "semphr.h"
extern QueueHandle_t KEYPAD_QUEUE_HANDLE ;
extern UBaseType_t KEYPAD_QUEUE_LENGTH ;
extern UBaseType_t KEYPAD_QUEUE_ELEMENT_SIZE;
extern SemaphoreHandle_t KEYPAD_SEMAPHORE_HANDLE;
void KEYPAD_TASK (void* pvParameters);





#endif /* KEYPAD_TASK_H_ */