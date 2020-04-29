/*
 * assignment1_7.c
 *
 *  Created on: Feb 3, 2020
 *      Author: AymanW.
 * (7) Write a program that takes three integers, and prints
 * out the smallest number.
 */
#include<stdio.h>

void main(){
	int firstNum;
	int secondNum;
	int thirdNum;
	int temp;
	puts("\npleas enter the first integer: ");
	scanf("%d",&firstNum);
	puts("\npleas enter the second integer: ");
	scanf("%d",&secondNum);
	puts("\npleas enter the third integer: ");
	scanf("%d",&thirdNum);
	if(firstNum >secondNum){
		temp=secondNum;

	}
	else if(firstNum <secondNum){
		temp=firstNum;
	}
	else{

	}
	if(thirdNum > temp){
		printf("\nThe smallest number is: %d",temp);
	}
	else{
		printf("\nThe smallest number is: %d",thirdNum);
	}
}

