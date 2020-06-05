/*
 * LCD_DRIVER.h
 *
 * Created: 5/15/2020 4:16:07 AM
 *  Author: AymanW
 * on proteus LM016L
 */ 


#ifndef LCD_DRIVER_H_
#define LCD_DRIVER_H_

#include <avr/io.h>
#include <util/delay.h>
#include "utils.h"
#include "standerd_Types.h"

/* LCD HW Pins */
#define RS PIND4
#define RW PIND5
#define E  PIND6

#define LCD_CTRL_PORT PORTD
#define LCD_CTRL_PORT_DIR DDRD
#define LCD_DATA_PORT PORTC
#define LCD_DATA_PORT_DIR DDRC

/* LCD Commands */
#define CLEAR_COMMAND 0x01
#define TWO_LINE_LCD_Eight_BIT_MODE 0x38
#define CURSOR_OFF 0x0C
#define CURSOR_ON 0x0E
#define SET_CURSOR_LOCATION 0x80
#define CURSOR_SHIFT_LEFT  0b00010000
#define CURSOR_SHIFT_RIGHT 0b00010100

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void LCD_init(void);
void LCD_goToRowColumn(uint8_t row,uint8_t col);
void LCD_displayCharacter(uint8_t data);
void LCD_displayString(const uint8_t *Str);
void LCD_sendCommand(uint8_t command);
void LCD_clearScreen(void);
void LCD_displayStringRowColumn(uint8_t row,uint8_t col,const uint8_t *Str);
void LCD_intgerToString(uint16_t data);
void LCD_WRITE_NUMBER(uint16_t num,uint8_t format_length);
void LCD_number_display(int16_t num, uint8_t format_length, uint8_t dot_position);
#endif /* LCD_DRIVER_H_ */