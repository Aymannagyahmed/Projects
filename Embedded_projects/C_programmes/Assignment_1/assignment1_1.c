/*
 * main.c
 *
 *  Created on: Feb 3, 2020
 *      Author: AymanW
 *
 *  (1) Write a program that take two integers from the user
	and print the results of this equation:
	Result = ((num1 + num2) * 3) - 10)
 */
#include<stdio.h>
void assignment1();
void main(void){

/*
	printf("pleas enter the first integer: ");
	scanf("%d",&firstNum);
	printf("\n pleas enter the second integer: ");
	scanf("%d",&secondNum);
	result = ((firstNum + secondNum) * 3) - 10;
	printf("\n result= %d",result);
	*/
	assignment1();
	//return 0;
}

void assignment1(void){
	int firstNum;
	int secondNum;
	int result;
	puts("pleas enter the first integer: ");
	scanf("%d",&firstNum);

	puts("\n pleas enter the second integer: ");
	scanf("%d",&secondNum);

	result= ((firstNum + secondNum) * 3) - 10;
	printf("\n %d \n", result);
}

