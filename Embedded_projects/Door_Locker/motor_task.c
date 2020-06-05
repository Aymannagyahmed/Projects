/*
 * motor_task.c
 *
 * Created: 5/27/2020 12:01:10 AM
 *  Author: AymanW
 */ 
#include "motor_task.h"
SemaphoreHandle_t MOTOR_LOGIC_SEMAPHORE_HANDLE=NULL;

void opne_door();
void close_door();
void MOTOR_TASK (void* pvParameters)
{
	DDRA|=(1<<PINA1)|(1<<PINA2);
	CLEAR_BIT(PORTA,PINA2);
	CLEAR_BIT(PORTA,PINA1);
	for (;;)
	{
		if( MOTOR_LOGIC_SEMAPHORE_HANDLE == NULL )
		{
			;
		}
		else
		{
			if(xSemaphoreTake(MOTOR_LOGIC_SEMAPHORE_HANDLE, portMAX_DELAY)==pdTRUE){
				opne_door();
				vTaskDelay(5000);
				close_door();
			}
			/* The semaphore can now be used. Its handle is stored in the
			xSemahore variable.  Calling xSemaphoreTake() on the semaphore here
			will fail until the semaphore has first been given. */
		}
	}
}
void opne_door()
{
	CLEAR_BIT(PORTA,PINA1);
	CLEAR_BIT(PORTA,PINA2);
	SET_BIT(PORTA,PINA1);
	vTaskDelay(3000);
	CLEAR_BIT(PORTA,PINA2);
	CLEAR_BIT(PORTA,PINA1);
}
void close_door()
{
	CLEAR_BIT(PORTA,PINA1);
	CLEAR_BIT(PORTA,PINA2);
	SET_BIT(PORTA,PINA2);
	vTaskDelay(3000);
	CLEAR_BIT(PORTA,PINA1);
	CLEAR_BIT(PORTA,PINA2);
}

