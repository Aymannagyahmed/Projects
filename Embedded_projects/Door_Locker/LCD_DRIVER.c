/*
* LCD_DRIVER.c
*
* Created: 5/15/2020 4:15:52 AM
*  Author: AymanW
*/
#include "LCD_DRIVER.h"

/*******************************************************************************
*                      Functions Definitions                                  *
*******************************************************************************/
void LCD_init(void)
{
	LCD_DATA_PORT_DIR = 0xFF; /* Configure the data port as output port */
	LCD_CTRL_PORT_DIR |= (1<<E) | (1<<RS) | (1<<RW); /* Configure the control pins(E,RS,RW) as output pins */
	
	LCD_sendCommand(TWO_LINE_LCD_Eight_BIT_MODE); /* use 2-line lcd + 8-bit Data Mode + 5*7 dot display Mode */
	
	LCD_sendCommand(CURSOR_OFF); /* cursor off */
	
	LCD_sendCommand(CLEAR_COMMAND); /* clear LCD at the beginning */
}

void LCD_sendCommand(uint8_t command)
{
	CLEAR_BIT(LCD_CTRL_PORT,RS); /* Instruction Mode RS=0 */
	CLEAR_BIT(LCD_CTRL_PORT,RW); /* write data to LCD so RW=0 */
	_delay_ms(1); /* delay for processing Tas = 50ns */
	SET_BIT(LCD_CTRL_PORT,E); /* Enable LCD E=1 */
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */
	LCD_DATA_PORT = command; /* out the required command to the data bus D0 --> D7 */
	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	CLEAR_BIT(LCD_CTRL_PORT,E); /* disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */
}



void LCD_displayCharacter(uint8_t data)
{
	SET_BIT(LCD_CTRL_PORT,RS); // Data Mode RS=1
	CLEAR_BIT(LCD_CTRL_PORT,RW); // write data to LCD so RW=0
	_delay_ms(1); // delay for processing Tas = 50ns
	SET_BIT(LCD_CTRL_PORT,E); // Enable LCD E=1
	_delay_ms(1); // delay for processing Tpw - Tdws = 190ns
	LCD_DATA_PORT =(uint8_t) data; // out the required data char to the data bus D0 --> D7
	_delay_ms(1); // delay for processing Tdsw = 100ns
	CLEAR_BIT(LCD_CTRL_PORT,E); // disable LCD E=0
	_delay_ms(1); // delay for processing Th = 13ns
}

void LCD_displayString(const uint8_t *Str)
{
	uint8_t i = 0;
	while(Str[i] != '\0')
	{
		LCD_displayCharacter(Str[i]);
		i++;
	}
	/***************** Another Method ***********************
	while((*Str) != '\0')
	{
	LCD_displayCharacter(*Str);
	Str++;
	}
	*********************************************************/
}

void LCD_goToRowColumn(uint8_t row,uint8_t col)
{
	uint8_t Address=0;//////////////////////////////////////////////////////////////////////////////////////////////
	
	/* first of all calculate the required address */
	switch(row)
	{
		case 0:
		Address=col;
		break;
		case 1:
		Address=col+0x40;
		break;
		case 2:
		Address=col+0x10;
		break;
		case 3:
		Address=col+0x50;
		break;
	}
	/* to write to a specific address in the LCD
	* we need to apply the corresponding command 0b10000000+Address */
	LCD_sendCommand(Address | SET_CURSOR_LOCATION);
}

void LCD_displayStringRowColumn(uint8_t row,uint8_t col,const uint8_t *Str)
{
	LCD_goToRowColumn(row,col); /* go to to the required LCD position */
	LCD_displayString(Str); /* display the string */
}


void LCD_clearScreen(void)
{
	LCD_sendCommand(CLEAR_COMMAND); //clear display
}

void LCD_WRITE_NUMBER(uint16_t num,uint8_t format_length)
{
	/*TAKE MAX LENGTH OF INPUT NUMBER (123)->6*/
	uint8_t i =0;
	if(num==0){
		LCD_displayCharacter('0');
		LCD_sendCommand(CURSOR_SHIFT_LEFT);
		LCD_sendCommand(CURSOR_SHIFT_LEFT);
	}
	while(num!=0){
		LCD_displayCharacter((num%10)+'0');
		num =num/10;
		LCD_sendCommand(CURSOR_SHIFT_LEFT);
		LCD_sendCommand(CURSOR_SHIFT_LEFT);
		i++;
	}
	while( (i < format_length)  && !(i>6)){
		i++;
		LCD_displayCharacter(' ');
		LCD_sendCommand(CURSOR_SHIFT_LEFT);
		LCD_sendCommand(CURSOR_SHIFT_LEFT);
	}
}

void LCD_number_display(int16_t num, uint8_t format_length, uint8_t dot_position){
	/*TAKE MAX LENGTH OF INPUT NUMBER (123)->6*/
	uint8_t i =0;
	uint8_t sign= (num<0);
	if(sign){
		num *=-1;
	}
	if(!num==0){		
		while(num!=0){
			LCD_displayCharacter((num%10)+'0');
			num =num/10;
			LCD_sendCommand(CURSOR_SHIFT_LEFT);
			LCD_sendCommand(CURSOR_SHIFT_LEFT);
			i++;
			if (i==dot_position){
				LCD_displayCharacter('.');
				LCD_sendCommand(CURSOR_SHIFT_LEFT);
				LCD_sendCommand(CURSOR_SHIFT_LEFT);
				if(num==0){
					LCD_displayCharacter('0');
					LCD_sendCommand(CURSOR_SHIFT_LEFT);
					LCD_sendCommand(CURSOR_SHIFT_LEFT);
				}
			}
		}
	}
	while(i < dot_position ){
		LCD_displayCharacter('0');
		LCD_sendCommand(CURSOR_SHIFT_LEFT);
		LCD_sendCommand(CURSOR_SHIFT_LEFT);
		i++;
		if (i==dot_position){
			LCD_displayCharacter('.');
			LCD_sendCommand(CURSOR_SHIFT_LEFT);
			LCD_sendCommand(CURSOR_SHIFT_LEFT);
			LCD_displayCharacter('0');
			LCD_sendCommand(CURSOR_SHIFT_LEFT);
			LCD_sendCommand(CURSOR_SHIFT_LEFT);
		}
	}
	if (i==0){
		LCD_displayCharacter('0');
		LCD_sendCommand(CURSOR_SHIFT_LEFT);
		LCD_sendCommand(CURSOR_SHIFT_LEFT);
	}
	if(sign){
		LCD_displayCharacter('-');
		LCD_sendCommand(CURSOR_SHIFT_LEFT);
		LCD_sendCommand(CURSOR_SHIFT_LEFT);
		i++;
	}
	while( (i < format_length)  && !(i>6)){
		i++;
		LCD_displayCharacter(' ');
		LCD_sendCommand(CURSOR_SHIFT_LEFT);
		LCD_sendCommand(CURSOR_SHIFT_LEFT);
	}
}