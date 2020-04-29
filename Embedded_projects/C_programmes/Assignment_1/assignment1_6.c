/*
 *  Write a program that print the relation between two
 *  integer number if those numbers are equal, not equal and
 *  which one contain the higher value.
 * */


#include<stdio.h>
void compare(int fN,int sN);
void main(){

	int firstNumber;
	int secondNumber;
	puts("enter the first number\n");
	scanf("%d",&firstNumber);
	puts("enter the second Number\n");
	scanf("%d",&secondNumber);
	compare( firstNumber,secondNumber);

}
void compare(int fN,int sN){
	if(fN>sN)
		printf("the first number(%d) larger than the second number (%d)\n",fN,sN);
	else if(fN<sN)
		printf("the first number(%d) smaller than the second number (%d)\n",fN,sN);
	else
		puts("the two numbers are equal\n");

}
