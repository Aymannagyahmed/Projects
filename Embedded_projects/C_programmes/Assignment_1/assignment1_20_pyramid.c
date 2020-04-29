/*
 * assignment1_20.c
 *
 *  Created on: Feb 3, 2020
 *      Author: AymanW
 *  (20) Write a program to display a full pyramid using stars
pattern.
 */

#include<stdio.h>
void drowPyramid(int numOfRow);
void drowInvPyramid(int numOfRow);
void main(){
	int n=5;
	drowPyramid(n);

}

void drowPyramid(int numOfRow){
	int i;
	int j;
	for(i=1;i<=numOfRow;i++){
		for(j=0;j<(numOfRow-i);j++){
			printf(" ");
		}
		for(j=0;j<((2*i)-1);j++ ){
		  printf("*");
		}

		printf("\n");
	}
}

void drowInvPyramid(int numOfRow){

}
