/*
* lcd_task.h
*
* Created: 5/27/2020 12:28:16 AM
*  Author: AymanW
*/


#ifndef LCD_TASK_H_
#define LCD_TASK_H_
#include "FreeRTOS.h"
#include "semphr.h"
#define LCD_GOTO(position) do	\
{								\
	uint8_t pos=position;		\
	xQueueSend(LCD_QUEUE_HANDLE,(uint8_t *) &pos, portMAX_DELAY);\
} while (0)
#define LCD_CLEAR() do			\
{								\
	uint8_t pos=127;			\
	xQueueSend(LCD_QUEUE_HANDLE,(uint8_t *) &pos, portMAX_DELAY);\
}while(0)
extern UBaseType_t LCD_QUEUE_LENGTH;
extern UBaseType_t LCD_QUEUE_ELEMENT_SIZE;
extern QueueHandle_t LCD_QUEUE_HANDLE;

void LCD_TASK (void* pvParameters);
void LCD_RTOS_D_STR(const char * str);





#endif /* LCD_TASK_H_ */