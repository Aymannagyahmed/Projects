/*
 * assignment1_15.c
 *
 *  Created on: Feb 3, 2020
 *      Author: AymanW
 * (15) Write a program to calculate the power of a number.
The number and its power are input from user.
 */
#include<stdio.h>
void main(){
	int num;
	int power;
	int i;
	double numpower=1;
	puts("Enter the number\n");
	scanf("%d",&num);
	puts("Enter the power of the number\n");
	scanf("%d",&power);

	if(!(num==0)){
		if(power==0){
			printf("(%d) power (%d) = 1\n",num,power);
		}
		else if(power>0){
			for(i=1;i<=power;i++){
				numpower *= num;
			}
		}
		else{
			for(i=-1;i>=power;i--){
				numpower *= (1/(double)num);
			}
		}

	}
	else{
		puts(" Can't determined \n");
	}
	printf("(%d) power (%d) = %.3lf\n",num,power,numpower);
}
