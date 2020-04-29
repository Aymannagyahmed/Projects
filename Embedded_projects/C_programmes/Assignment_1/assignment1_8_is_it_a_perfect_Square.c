/*
 * assignment1_8.c
 *
 *  Created on: Feb 3, 2020
 *      Author: AymanW
 * (8) Write a program that reads a positive integer and
 * checks if it is a perfect square.
 */


#include<stdio.h>
void isPerfectSquare(int num);
void main(){

	int num;
	printf("Enter the number: \n");
	fflush(stdout);
	scanf("%d",&num);
	isPerfectSquare(num);


}

void isPerfectSquare(int num){
	int i;
	for(i=0;i<=num;i++){
		if(num==(double)(i*i)){
			printf("%d is a perfect square \n",num);
			break;
		}
		if((i==num)){
			printf("%d is not a perfect square \n",num);
		}
	}


}
