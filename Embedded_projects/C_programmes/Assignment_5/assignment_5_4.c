/*
 * assignment_5_4.c
 *
 *  Created on: Mar 12, 2020
 *      Author: AymanW
 *   C Function to calculate the difference between two
 *   time periods using structures.
 */

#include<stdio.h>

typedef struct{
	int sec;
	int min;
	int hour;
}difference_st;
void diffBetween2Period(difference_st f,difference_st s,difference_st* dif);
void main(void){
	difference_st x={0,0,4};
	difference_st y={0,30,5};
	difference_st result;
	diffBetween2Period(x,y,&result);
	printf("diff is %d:%d:%d\n",result.hour,result.min,result.sec);
}
void diffBetween2Period(difference_st f,difference_st s,difference_st* dif){
	/* secondes*/
	if(f.sec< s.sec){
		dif->sec=60-(s.sec-f.sec);
	}
	else{
		dif->sec=f.sec-s.sec;
	}
	/* minuts */
	if(f.min< s.min){
			dif->min=60-(s.min-f.min);
		}
	else{
			dif->min=f.min-s.min;
		}
	/* hours */
	if(f.hour< s.hour){
			dif->hour=24-(s.hour-f.hour);
		}
	else{
			dif->hour=f.hour-s.hour;
		}
}
