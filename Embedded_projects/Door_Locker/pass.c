/*
* pass.c
*
* Created: 5/16/2020 12:32:28 AM
*  Author: AymanW
*/
#include "pass.h"

/* second location in EEPROM to hold the first location of current password */
#define start_location_of_pass_address 0x01 //to hold location of FIRST char in password at the memory

/*first location in EEPROM to hold the new location will write the next pass starting from it */
#define end_location_of_pass_address 0x00 //to hold location of LAST char in password at the memory
void WRITE_PASSWORD_EEPROM(uint8_t *new_pass,uint8_t length_of_new_pass){
	uint8_t i=0;
	uint8_t end_of_pass_address=0x00;  //       last address in pass which puts in location 1 in EEPROM 
	EEPROM_READ(end_location_of_pass_address,&end_of_pass_address);
	/* at lat possession of EEPROM  start from first possession */
	if(end_of_pass_address==0xff)
	{
		/* escape first TWO location (start and end address of current password) */
		end_of_pass_address=0x02;
	}
	
	/*write new password in EEPROM*/
	for(i=0;i<length_of_new_pass;i++)
	{
		EEPROM_WRITE(end_of_pass_address+i,new_pass[i]);	
	}
	
	EEPROM_WRITE(start_location_of_pass_address,end_of_pass_address);
	EEPROM_WRITE(end_location_of_pass_address,end_of_pass_address+length_of_new_pass);
}

uint8_t VERIFY_PASSWORD(uint8_t * string,uint8_t length){
	uint8_t i;
	uint8_t start_of_pass_address=0x00;
	uint8_t end_of_pass_address=0x00;
	EEPROM_READ(start_location_of_pass_address,&start_of_pass_address);
	EEPROM_READ(end_location_of_pass_address,&end_of_pass_address);
	/*verify if length of saved pass == length of input pass*/
	if(!(length== (end_of_pass_address-start_of_pass_address)))
	{
		return 0;
	}
	else
	{
		for(i=0;i<length;i++)
		{
			uint8_t temp;
			EEPROM_READ(start_of_pass_address+i,&temp);
			if(string[i]!=temp){
				return 0;
			}
		}
		return  1;
	}
}