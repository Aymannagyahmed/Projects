/*
 * assignment_4_11.c
 *
 *  Created on: Mar 3, 2020
 *      Author: AymanW
 *  SWAP the value of the two 16-bits of 32-bits integer number.
 */
#include<stdio.h>

void swape16to32BitInt(int* numptr);
void main(void){
	int x=0xFFEE;
	printf("old is %x\n",x);
	swape16to32BitInt(&x);
	printf("new is %x\n",x);



}

void swape16to32BitInt(int* numPtr){
	*numPtr=(((*numPtr)<<8)|((*numPtr)>>4));
}
