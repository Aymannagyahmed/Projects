/*
* GccApplication1.c
*
* Created: 4/7/2020 12:20:58 AM
* Author : Laptop
*/
#include "FreeRTOS.h"
#include "task.h"
#include "croutine.h"
#include "semphr.h"
/* Task H files*/
#include "motor_task.h"
#include "lcd_task.h"
#include "keypad_task.h"
#include "main_task.h"

/*PRIORITIES*/
#define  LCD_TASK_PRIORITY  (4)
#define  KEYPAD_TASK_PRIORITY (3)
#define  LOGIC_TASK_TASK_PRIORITY (3)
#define  MOTOR_TASK_PRIORITY (5)

/*HANDLES */
TaskHandle_t MOTOR_TASK_HANDLE=NULL;
TaskHandle_t LCD_TASK_HANDLE=NULL;
TaskHandle_t KEYPAD_TASK_HANDLE=NULL;
TaskHandle_t LOGIC_TASK_HANDLE=NULL;

int main(void)
{
	DDRA=0XFF;
	PORTA=0x00;
	LCD_init();
	KEYPAD_init();
	/*TASK CREATION */
	xTaskCreate(MOTOR_TASK, "pcMOTOR", configMINIMAL_STACK_SIZE, MOTOR_TASK_HANDLE, MOTOR_TASK_PRIORITY, NULL);
	xTaskCreate(LCD_TASK, "pcLCD", configMINIMAL_STACK_SIZE, LCD_TASK_HANDLE, LCD_TASK_PRIORITY, NULL);
	xTaskCreate(KEYPAD_TASK, "pcKEYPAD", configMINIMAL_STACK_SIZE, KEYPAD_TASK_HANDLE, KEYPAD_TASK_PRIORITY, NULL);
	xTaskCreate(LOGIC_TASK, "pcLOGIC", configMINIMAL_STACK_SIZE, LOGIC_TASK_HANDLE, LOGIC_TASK_TASK_PRIORITY, NULL);
	
	/*LCD Queue CREATION*/
	LCD_QUEUE_HANDLE =xQueueCreate(LCD_QUEUE_LENGTH,LCD_QUEUE_ELEMENT_SIZE);
	/*KEYPAD Queue CREATION*/
	KEYPAD_QUEUE_HANDLE =xQueueCreate(KEYPAD_QUEUE_LENGTH,KEYPAD_QUEUE_ELEMENT_SIZE);
	
	KEYPAD_SEMAPHORE_HANDLE= xSemaphoreCreateBinary();
	MOTOR_LOGIC_SEMAPHORE_HANDLE= xSemaphoreCreateBinary();
	
	vTaskStartScheduler();
	
	while(1)
	{
		;
	}
	return 0;
}




