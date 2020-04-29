/*
 * assignment1_19.c
 *
 *  Created on: Feb 3, 2020
 *      Author: AymanW
 * (19) Write a program to display inverted half pyramid using
stars pattern. 
 */

#include<stdio.h>
void main(){
	int i;
	int j;
	int n=5;
	for(i=0;i<n;i++){
		for(j=(n-i);j>0;j--){
			printf("* ");
		}
		printf("\n");
	}



}

