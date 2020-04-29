/*
 * assignment1_10.c
 *
 *  Created on: Feb 3, 2020
 *      Author: AymanW
 */

#include<stdio.h>


void main(){
	char operator;
	double firestNumber;
	double secondNumber;
	printf("Enter the operator + - * / :\n");
	fflush(stdout);
	scanf("%c",&operator);

	printf("Enter firest Number :\n");
	fflush(stdout);
	scanf("%lf",&firestNumber);

	printf("Enter second tNumber :\n");
	fflush(stdout);
	scanf("%lf",&secondNumber);

	switch(operator) {
	case '+':
		printf("%lf + %lf = %lf \n",firestNumber,secondNumber, firestNumber+secondNumber);
		break;
	case '-':
		printf("%lf - %lf = %lf \n",firestNumber,secondNumber, firestNumber-secondNumber);
		break;
	case '*':
		printf("%lf * %lf = %lf \n",firestNumber,secondNumber, firestNumber*secondNumber);
		break;
	case '/':
		if(secondNumber==0){
			printf("You can't devidded on (zero) \n");
			break;
		}
		else{
			printf("%lf / %lf = %lf \n",firestNumber,secondNumber, firestNumber/secondNumber);
			break;
		}
		default:
		printf("rong operator \n");
		break;
	}



}
