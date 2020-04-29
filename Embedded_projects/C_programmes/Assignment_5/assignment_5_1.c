/*
 * assignment_5_1.c
 *
 *  Created on: Mar 12, 2020
 *      Author: AymanW
 *  C Program to store information (name, roll and
 *  marks) for a student using structure and display it.
 */
#include<stdio.h>
typedef struct{
	char* name;
	int id;
	int marks;
}student;
void main(void){
	student x;
	student f={"ayman",55,90};
	printf("name is %s\nId is %d\nmarks is %d\n",f.name,f.id,f.marks);
	student* xptr=&x;
	xptr->name = "mohamed";
	xptr->id=66;
	xptr->marks=100;
	printf("name is %s\nId is %d\nmarks is %d\n",xptr->name,xptr->id,xptr->marks);
}
