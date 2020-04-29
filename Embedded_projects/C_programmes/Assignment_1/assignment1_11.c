/*
 * assignment1_11.c
 *
 *  Created on: Feb 3, 2020
 *      Author: AymanW
 * (11) Print sum of first 100 integers. ///////(With data validation)/////////
 */

#include<stdio.h>

void main(){
	int n=100;
	int i=0;
	int sum=0;
	for(i=0;i<n;i++){
		sum=sum+i;
	}
	printf("sum = %i",sum);
}

