/*
 * EEPROM.c
 *
 * Created: 5/20/2019 10:30:10 PM
 *  Author: Ayman88
 */ 
#include "EEPROM.h"

EEPROM_ERR_E EEPROM_WRITE (uint16_t address, uint8_t data )
{
	if(address > EEPROM_SIZE){
		return EEPROM_FAIL;
	}

	while(EECR & (1<<EEWE))
	{
		;	
	}
	EEAR = address;
	EEDR = data;
	EECR |= (1<<EEMWE);
	
	EECR |= (1<<EEWE);
	return EEPROM_SUCCESS;
}

EEPROM_ERR_E EEPROM_READ (uint16_t address, uint8_t * data)
{
	if (address>EEPROM_SIZE)
	{
		return EEPROM_FAIL;
	}
	while(EECR & (1<<EEWE))
	{
		;
	}
	EEAR = address;
	EECR |= (1<<EERE);
	
	*data = EEDR;	
	return EEPROM_SUCCESS;
}










