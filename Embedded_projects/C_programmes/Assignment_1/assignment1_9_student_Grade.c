/*
 * assignment1_9.c
 *
 *  Created on: Feb 3, 2020
 *      Author: AymanW
 */
#include<stdio.h>
void testGrade(int grade);
void main(){
	int grade;
	printf("put your grade:\n");
	fflush(stdout);
	scanf("%d",&grade);
	testGrade(grade);
}

void testGrade(int grade){
	if((grade>=85)&&((grade<=100))){
		printf("Excellent\n");
	}
	else if((grade>=75) && (grade<85)){
		printf("Very Good\n");
	}
	else if((grade>=65) && (grade<75)){
		printf("Good\n");
	}
	else if((grade>=55) && (grade<65)){
		printf("Pass\n");
	}
	else if((grade>=0) && (grade<55)){
		printf("Fail\n");
	}
	else{
		printf("rong number\n");
	}
}
