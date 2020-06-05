/*
* keypad.c
*
* Created: 4/22/2019 5:26:00 PM
*  Author: Ayman88
*/
#include "keypad.h"
#define KEYPAD_col0 _PB3
#define KEYPAD_col1 _PB2
#define KEYPAD_col2 _PB1
#define KEYPAD_col3 _PB0
#define KEYPAD_row0 _PB4
#define KEYPAD_row1 _PB5
#define KEYPAD_row2 _PB6
#define KEYPAD_row3 _PB7
#define INPUT 0
#define OUTPUT 1
void KEYPAD_init(void){
	DIO_SetPinDirection(KEYPAD_row0,INPUT);
	DIO_SetPinDirection(KEYPAD_row1,INPUT);
	DIO_SetPinDirection(KEYPAD_row2,INPUT);
	DIO_SetPinDirection(KEYPAD_row3,INPUT);
	DIO_SetPinDirection(KEYPAD_col0,OUTPUT);
	DIO_SetPinDirection(KEYPAD_col1,OUTPUT);
	DIO_SetPinDirection(KEYPAD_col2,OUTPUT);
	DIO_SetPinDirection(KEYPAD_col3,OUTPUT);
	DIO_WritePin(KEYPAD_row0,HIGH);
	DIO_WritePin(KEYPAD_row1,HIGH);
	DIO_WritePin(KEYPAD_row2,HIGH);
	DIO_WritePin(KEYPAD_row3,HIGH);
	DIO_WritePin(KEYPAD_col0,LOW);
	DIO_WritePin(KEYPAD_col0,LOW);
	DIO_WritePin(KEYPAD_col0,LOW);
	DIO_WritePin(KEYPAD_col0,LOW);
}

uint8_t KEYPAD_isConnected(uint8_t row,uint8_t col){
	uint8_t isConnected = 0;
	if(!DIO_ReadPin(row)){
		DIO_WritePin(col,HIGH);
		if(DIO_ReadPin(row)){
			isConnected = 1;
		}
		DIO_WritePin(col,LOW);
	}
	return isConnected;
}
uint8_t KEYPAD_getKey(void){
	uint8_t key  = '-';
	if(KEYPAD_isConnected(KEYPAD_row0,KEYPAD_col0)){
		key = '1';
	}else if (KEYPAD_isConnected(KEYPAD_row0,KEYPAD_col1))
	{
		key = '2';
	}else if (KEYPAD_isConnected(KEYPAD_row0,KEYPAD_col2))
	{
		key = '3';
	}else if (KEYPAD_isConnected(KEYPAD_row0,KEYPAD_col3))
	{
		key = 'A';
	}else if (KEYPAD_isConnected(KEYPAD_row1,KEYPAD_col0))
	{
		key = '4';
	}else if (KEYPAD_isConnected(KEYPAD_row1,KEYPAD_col1))
	{
		key = '5';
	}else if (KEYPAD_isConnected(KEYPAD_row1,KEYPAD_col2))
	{
		key = '6';
	}else if (KEYPAD_isConnected(KEYPAD_row1,KEYPAD_col3))
	{
		key = 'B';
	}else if (KEYPAD_isConnected(KEYPAD_row2,KEYPAD_col0))
	{
		key = '7';
	}else if (KEYPAD_isConnected(KEYPAD_row2,KEYPAD_col1))
	{
		key = '8';
	}else if (KEYPAD_isConnected(KEYPAD_row2,KEYPAD_col2))
	{
		key = '9';
	}else if (KEYPAD_isConnected(KEYPAD_row2,KEYPAD_col3))
	{
		key = 'C';
	}else if (KEYPAD_isConnected(KEYPAD_row3,KEYPAD_col0))
	{
		key = '*';
	}else if (KEYPAD_isConnected(KEYPAD_row3,KEYPAD_col1))
	{
		key = '0';
	}else if (KEYPAD_isConnected(KEYPAD_row3,KEYPAD_col2))
	{
		key = '#';
	}else if (KEYPAD_isConnected(KEYPAD_row3,KEYPAD_col3))
	{
		key = 'D';
	}
	return key;
}