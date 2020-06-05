/*
 * main_task.h
 *
 * Created: 5/27/2020 12:53:00 AM
 *  Author: AymanW
 */ 


#ifndef MAIN_TASK_H_
#define MAIN_TASK_H_
#include "FreeRTOS.h"
#include "semphr.h"
#include "lcd_task.h"
#include "keypad_task.h"
#include "motor_task.h"
#include "pass.h"


#define PASSWORD_LENGTH 10
void LOGIC_TASK (void* pvParameters);




#endif /* MAIN_TASK_H_ */