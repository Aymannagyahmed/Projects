

#ifndef DIO_H_
#define DIO_H_
#include <stdint.h>
#include "Bitwiseoperations.h"
#define ZERO 0
#define EIGHT 8
#define SIXTEEN 16
#define TWINTY_FOUR 24
#define THIRTY_TWO 32
#define HIGH 1
#define LOW 0 
enum PIN_NUM_E {
	_PA0=0u,
	_PA1,
	_PA2,
	_PA3,
	_PA4,
	_PA5,
	_PA6,
	_PA7,
	_PB0,
	_PB1,
	_PB2,
	_PB3,
	_PB4,
	_PB5,
	_PB6,
	_PB7,
	_PC0,
	_PC1,
	_PC2,
	_PC3,
	_PC4,
	_PC5,
	_PC6,
	_PC7,
	_PD0,
	_PD1,
	_PD2,
	_PD3,
	_PD4,
	_PD5,
	_PD6,
	_PD7
	};
void DIO_WritePin(uint8_t PinNum,uint8_t PinValue);
uint8_t DIO_ReadPin(uint8_t PinNum);
void DIO_SetPinDirection(uint8_t PinNum,uint8_t PinDirection);

void DIO_WritePort(uint8_t port ,uint8_t value);
void DIO_SetPortDirection(uint8_t port,uint8_t direction);

#endif /* DIO_H_ */