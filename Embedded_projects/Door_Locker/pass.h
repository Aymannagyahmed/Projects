/*
 * pass.h
 *
 * Created: 5/16/2020 12:45:23 AM
 *  Author: AymanW
 */ 


#ifndef PASS_H_
#define PASS_H_
#include "EEPROM.h"
void WRITE_PASSWORD_EEPROM(uint8_t *new_pass,uint8_t length_of_new_pass);
uint8_t VERIFY_PASSWORD(uint8_t * string,uint8_t length);



#endif /* PASS_H_ */