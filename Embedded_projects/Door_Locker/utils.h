/*
 * utils.h
 *
 *  Created on: Apr 13, 2020
 *      Author: AymanW
 */

#ifndef MCAL_UTILS_H_
#define MCAL_UTILS_H_

#define SET_REG(reg) reg=0XFF
#define CLEAR_REG(reg) reg=0X00
#define TOGGLE_REG(reg) reg^=0XFF
#define ASSIGN_REG(reg,vaalue) reg=vaalue
#define SET_BIT(reg,bit) reg |=(1<<bit)
#define CLEAR_BIT(reg,bit) reg &= ~(1<<bit)
#define TOGGLE_BIT(reg,bit) reg^=(1<<bit)
#define READ_BIT(reg,bit) (reg&(1<<bit))


//#define WRITE_BITS(reg,vaalue) (reg|= (vaalue))




#endif /* MCAL_UTILS_H_ */
