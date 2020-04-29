/*
 * assignment1_17.c
 *
 *  Created on: Feb 3, 2020
 *      Author: AymanW
 * (17) Write a program to count number of digits in a
decimal number.
 */

#include<stdio.h>
void countNumberOfDigits(int num);
void main(){
	int num=12345;
	countNumberOfDigits(num);
}
void countNumberOfDigits(int num){
	int count=0;
	while(num !=0){
		count++;
		num=num/10;
	}
	printf("number of digits is (%d)\n",count);
}
