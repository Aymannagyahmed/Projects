/*
 * assignment_5_6.c
 *
 *  Created on: Mar 12, 2020
 *      Author: AymanW
 *  Create Union type called family_name it shall have two
 *  members first_name and last_name. The two members are
 *  array of characters with same size 30. Try to write string in
 *  the first member first_name then print the second member
 *  last_name plus print the size of the union
 */

#include<stdio.h>
/*  to use strcpy */
#include<string.h>
#define sizee 3
typedef union{
	char first_name[30];
	char last_name[30];
}family_name_un;
void main(void){
	family_name_un x;
	/* strcpy  */
	strcpy(x.first_name,"ayman");
	printf("%s\n",x.last_name);
	printf("%I64d\n",sizeof(x));
}
