/*
 * assignment_4.c
 *
 *  Created on: Feb 3, 2020
 *      Author: AymanW
 * (4) Write a program that reads the radius of a circle and
 * calculates the area and circumference then prints the
 * results.
 */
#include <stdio.h>
void areaAndCircumference(int radius);
void main(){
	int radius;
	puts("Enter the radius of a circle\n");
	scanf("%d",&radius);
	areaAndCircumference(radius);

}
void areaAndCircumference(int radius){
	double pi=3.14159;
	double circumference;
	double area;
	area= pi*radius*radius;
	circumference= 2*pi*radius;
	printf("area= %.2lf\ncircumference= %.2lf ",area,circumference);
}

