/*
 * assignment_5_3.c
 *
 *  Created on: Mar 12, 2020
 *      Author: AymanW
 *  C function to add two complex numbers by passing
 *  two structure to a function and display the results.
 */
#include<stdio.h>
typedef struct{
	float real;
	float img;
}num_st;
num_st add2NumInStruct(num_st* f,num_st* s);
void main(void){
	num_st x;
	num_st y;
	num_st result;
	x.real=10.5;
	y.real=20.25;
	x.img=100.1;
	y.img=64.3;
	result = add2NumInStruct(&x,&y);
	printf("the sum is (%.3f + %.3fi)\n",result.real,result.img);
}
num_st add2NumInStruct(num_st* f,num_st* s){
	num_st ret;
	ret.real=f->real+s->real;
	ret.img=f->img+s->img;
	//printf("%d + %d = %d\n",f->real,s->real,(f->real+s->real));
	//printf("%d + %d = %d\n",f->img,s->img,(f->img+s->img));
	return ret;
}
