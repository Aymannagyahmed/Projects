/*
 * lcd_task.c
 *
 * Created: 5/27/2020 12:27:59 AM
 *  Author: AymanW
 */ 
#include "lcd_task.h"
UBaseType_t LCD_QUEUE_LENGTH = (10);
UBaseType_t LCD_QUEUE_ELEMENT_SIZE = sizeof(uint8_t);
QueueHandle_t LCD_QUEUE_HANDLE=NULL;
void LCD_TASK (void* pvParameters)
{
	uint8_t ch;
	BaseType_t success;
	for (;;)
	{
		success= xQueueReceive(LCD_QUEUE_HANDLE,(uint8_t *) &ch,portMAX_DELAY);
		if(success==pdTRUE){
			if (ch>=' '&&ch<127) /* between visible character in ascii table */
			{
				LCD_displayCharacter(ch);
			}
			else if(ch==127) /*clear Screen*/
			{
				LCD_clearScreen();
				LCD_goToRowColumn(0,0);
			}
			else if(ch<32) /* character bigger than or equal  0 and less than 32 */
			{
				LCD_goToRowColumn(ch/16,ch%16);
			}
			
		}
		
	}
}
void LCD_RTOS_D_STR(const char * str){
	uint8_t i = 0;
	while(str[i]!='\0'){
		xQueueSend(LCD_QUEUE_HANDLE,(uint8_t *)str+i,portMAX_DELAY);
		i++;
	}
}
