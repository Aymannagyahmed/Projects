/*
 * assignment1_12.c
 *
 *  Created on: Feb 3, 2020
 *      Author: AymanW
 *(12) Write a program that reads a positive integer and
computes the factorial.
 */


#include<stdio.h>

void main(){
	int n=4;
	int i;
	int factorial=1;
	if(n>0){
		for(i=0;i<n;i++){
			factorial=factorial*(n-i);
		}
	}

	printf("factorial of (%d) is %d",n,factorial);
}
