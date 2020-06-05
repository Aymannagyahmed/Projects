/*
 * keypad.h
 *
 * Created: 4/22/2019 5:25:38 PM
 *  Author: Ayman88
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "DIO.h"

void KEYPAD_init(void);
uint8_t KEYPAD_getKey(void);

#endif /* KEYPAD_H_ */