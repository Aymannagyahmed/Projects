/*
 * assignment_5_5.c
 *
 *  Created on: Mar 12, 2020
 *      Author: AymanW
 *  C Function to store information (name, id and grade) for 10
 *  students in array of structures using pointers and another
 *  function to print all the structures using pointers.
 */
#include<stdio.h>
#define sizee 3
typedef struct{
	char name[50];
	int id;
	float grade;
}information;
void store(information arrPtr[],int size);
void printArrOfStruct(information arrPtr[],int size);
void main(void){
	information arr[sizee];
	store(arr,sizee);
	printArrOfStruct(arr,sizee);
}
void store(information* arrPtr,int size){
	int i;
	for(i=0;i<size;i++){
		printf("Enter Name then id then grade of stu (%d)\n",i+1);
		fflush(stdout);
		/* (arrPtr[i]->name) */ /* & (arrPtr[i]->id) */ /* & (arrPtr[i]->grade) */
		scanf("%s%d%f",(arrPtr->name),&(arrPtr->id),&(arrPtr->grade));

/*		printf("Id of stu %d :\n",i+1);
		fflush(stdout);
		scanf("%d",&(arrPtr->id));
*/
/*		printf("grade of stu %d :\n",i+1);
		fflush(stdout);
		scanf("%f",&(arrPtr->grade));
*/
		arrPtr++;
	}
}
void printArrOfStruct(information* arrPtr,int size){
	int i;
	for(i=0;i<size;i++){
		printf("stu %d Name is (%s) id is (%d) grade is (%.2f)\n",i+1,arrPtr->name,arrPtr->id,arrPtr->grade);
/*		printf("Id of stu %d is %d\n",i+1,arrPtr->id);
		printf("grade of stu %d is %.2f\n",i+1,arrPtr->grade);
*/
		arrPtr++;
	}
}
