/*
 * assignment_5_2.c
 *
 *  Created on: Mar 12, 2020
 *      Author: AymanW
 *  C Program to add two distances (inch-feet) using
 *  structure and display the result.
 */
#include<stdio.h>
typedef struct{
	int inch;
	int feet;
}length;
void main(void){
	length first={1,5};
	length second;
	length* secptr=&second;
	secptr->inch=50;
	secptr->feet=100;
	printf("%d inch + %d inch = %d inch\n",first.inch,secptr->inch,(first.inch+secptr->inch));
	printf("%d inch + %d inch = %d inch\n",first.feet,secptr->feet,(first.feet+secptr->feet));
}
