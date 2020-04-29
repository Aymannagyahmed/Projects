/*
 * assignment1_18.c
 *
 *  Created on: Feb 3, 2020
 *      Author: AymanW
 * (18) Write a program to display half pyramid using stars
pattern.
 */

#include<stdio.h>
void main(){
	int i;
	int j;
	int n=5;
	for(i=0;i<5;i++){
		for(j=0;j<(i+1);j++){
			printf("* ");
		}
		printf("\n");

	}


}
