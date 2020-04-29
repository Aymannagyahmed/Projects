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
#define TOOGLE_REG(reg) reg^=0XFF
#define ASSIGN_REG(reg,value) reg=vlaeu
#define SET_BIT(reg,bit) reg |=(1<<bit)
#define CLEAR_BIT(reg,bit) reg &= ~(1<<bit)
#define TOOGLE_BIT(reg,bit) reg^=(1<<bit)




#endif /* MCAL_UTILS_H_ */
