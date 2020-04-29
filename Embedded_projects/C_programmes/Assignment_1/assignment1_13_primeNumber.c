/*
 * assignment1_13.c
 *
 *  Created on: Feb 3, 2020
 *      Author: AymanW
 * (13) Write a program that reads a positive integer and
checks if it is a prime.
 */

#include<stdio.h>



void main(){
	int i;
	int number;
	int chek=0;
	puts("Enter the postive integer number:\n");
	scanf("%d",&number);
	if(number==1){
		printf("%d is a prime number\n",number);
	}
	else if(number>1){
		for(i=2;i<number;i++){
			if(((number%i)==0)){
				chek++;
				break;
			}

		}

		if(!(chek==0)){
			printf("%d is not a prime number\n",number);
		}
		else{
			printf("%d is a prime number\n",number);
		}
	}
	else{
		puts("this number is zero or nigative\n");
	}

	printf("chek= %d \n",chek);
}


