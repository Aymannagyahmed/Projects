/*
 * assignment1_16.c
 *
 *  Created on: Feb 3, 2020
 *      Author: AymanW
 * (16) Write a program to reverse a number.
 */
#include<stdio.h>
void revNum(long number);

double invNumb(double num);
void main(){
	long num;
	printf("Enter a number to reverse\n");
	fflush(stdout);
	scanf("%ld", &num);
	revNum(num);




}

double invNumb(double num){
	double inversNum;
	inversNum= 1/num;
	printf("invers num is %lf",inversNum);
	return inversNum;
}

void revNum(long number){
	long revnum=0;
	while(!(number==0)){
		revnum=revnum*10;
		revnum= revnum +(number%10);
		number= number/10;
	}
	printf("Reverse of the number = %ld\n",revnum);
	fflush(stdout);
}



