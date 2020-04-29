/*
 * assignment_5.c
 *
 *  Created on: Feb 3, 2020
 *      Author: AymanW
 * (5) Write a program to print the ASCII value of a character
 * input by the user
 */

#include<stdio.h>
void printCharToAscii(char ch);
void printIntToAscii(char integer);
void main(){
	char c;
	int i;
	puts("Enter the character \n");
	scanf("%c",&c);
	puts("Enter the number between 0-127  \n");
	scanf("%d",&i);
	printCharToAscii(c);
	printIntToAscii(i);

}

void printCharToAscii(char ch){
	printf("the ASCII value of %c is (%d)\n",ch,ch);
}

void printIntToAscii(char integer){
	printf("the ASCII value of %d is (%c)\n",integer,integer);
}
