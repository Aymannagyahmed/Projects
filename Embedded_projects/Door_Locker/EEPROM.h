/*
 * IncFile1.h
 *
 * Created: 5/20/2019 10:30:25 PM
 *  Author: Ayman88
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include <avr/io.h>

#include <util/delay.h>
#include "standerd_Types.h"
#include "utils.h"

typedef enum EEPROM_ERR_E {
	EEPROM_SUCCESS=0,
	EEPROM_FAIL=1,
	}EEPROM_ERR_E;
#define EEPROM_SIZE 50u
EEPROM_ERR_E EEPROM_WRITE (uint16_t address, uint8_t data );
EEPROM_ERR_E EEPROM_READ (uint16_t address, uint8_t *data);


#endif /* EEPROM_H_ */