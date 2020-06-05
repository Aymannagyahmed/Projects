/*
 * motor_task.h
 *
 * Created: 5/26/2020 11:57:26 PM
 *  Author: AymanW
 */ 


#ifndef MOTOR_TASK_H_
#define MOTOR_TASK_H_
#include "FreeRTOS.h"
#include "semphr.h"

void MOTOR_TASK (void* pvParameters);

extern SemaphoreHandle_t MOTOR_LOGIC_SEMAPHORE_HANDLE;



#endif /* MOTOR_TASK_H_ */