/*
 * main_task.c
 *
 * Created: 5/27/2020 12:52:42 AM
 *  Author: AymanW
 */ 
#include "main_task.h"
uint8_t get_password(uint8_t * password_buffer);

const char const * welcomeMsg = "Welcome...";
void LOGIC_TASK (void* pvParameters)
{
	
	for (;;)
	{
		TOGGLE_BIT(PORTA,PINA0);
		/*clear screen*/
		LCD_CLEAR();

		/*display welcome*/
		LCD_RTOS_D_STR(welcomeMsg);
		vTaskDelay(1000);
		/*start from position 0,0*/
		
		LCD_GOTO(0);
		LCD_RTOS_D_STR("Enter Password");
		LCD_GOTO(16);
		/*Get password */
		uint8_t password[PASSWORD_LENGTH]="";
		uint8_t password_correct=0;
		uint8_t wrong=0;
		/*if wrong password*/
		while(password_correct==0)
		{
			uint8_t password_length = get_password(password);
			password_correct = VERIFY_PASSWORD(password,password_length);
			if(password_correct==0)
			{
				wrong++;
				if(wrong>3){
					LCD_CLEAR();
					LCD_RTOS_D_STR("Wait 10 seconds");
					vTaskDelay(5000);
				}
				LCD_CLEAR();
				LCD_GOTO(0);
				LCD_RTOS_D_STR("Wrong Password...");
				vTaskDelay(500);
				LCD_GOTO(0);
				LCD_RTOS_D_STR("Reenter Password...");
				LCD_GOTO(16);
			}
		}
		/*correct password*/
		LCD_GOTO(16);
		LCD_RTOS_D_STR("Correct Password");
		vTaskDelay(1000);
		
		/*first line*/
		LCD_CLEAR();
		LCD_RTOS_D_STR("1: open door");
		/*second line*/
		LCD_GOTO(16);
		LCD_RTOS_D_STR("2: change pass");
		/*get key to open or change pass */
		uint8_t key='-';
		while (!(key=='1'||key=='2'))
		{
			xSemaphoreGive(KEYPAD_SEMAPHORE_HANDLE);
			xQueueReceive(KEYPAD_QUEUE_HANDLE,(uint8_t*) &key,portMAX_DELAY);
		}
		if(key=='1')
		{
			LCD_CLEAR();
			LCD_RTOS_D_STR("door is opening");
			xSemaphoreGive(MOTOR_LOGIC_SEMAPHORE_HANDLE);
			vTaskDelay(3000);
			LCD_CLEAR();
			LCD_RTOS_D_STR("door open");
			vTaskDelay(5000);
			LCD_CLEAR();
			LCD_RTOS_D_STR("Door is closing");
			vTaskDelay(3000);
		}
		/*change pass*/
		else if(key=='2')
		{
			uint8_t password_valid=0;
			while(password_valid==0){
				LCD_CLEAR();
				LCD_RTOS_D_STR("enter new password");
				LCD_GOTO(16);
				uint8_t new_password_length =get_password(password);
				if(new_password_length>=4){
					WRITE_PASSWORD_EEPROM(password,new_password_length);
					password_valid=1;
					LCD_CLEAR();
					LCD_RTOS_D_STR("password changed!");
					vTaskDelay(3000);
					} else{
					LCD_CLEAR();
					LCD_RTOS_D_STR("invalid");
					vTaskDelay(2000);
					LCD_CLEAR();
					LCD_RTOS_D_STR("pass 4:10 number");
					vTaskDelay(1000);
				}
			}
		}
	}
}




uint8_t get_password(uint8_t * password_buffer){
	uint8_t key='-';
	uint8_t i=0;
	const uint8_t astrick='*';
	while(key!='#')
	{
		xSemaphoreGive(KEYPAD_SEMAPHORE_HANDLE);
		xQueueReceive(KEYPAD_QUEUE_HANDLE,(uint8_t*) &key,portMAX_DELAY);
		if(i<PASSWORD_LENGTH && key!='#'){
			password_buffer[i]=key;
			xQueueSend(LCD_QUEUE_HANDLE,(uint8_t *) &astrick,portMAX_DELAY);
			i++;
		}
	}
	return i;
}