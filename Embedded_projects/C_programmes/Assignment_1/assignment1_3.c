/*
 *
 *
 * (3) Write a program for converting temperature from
 * degrees Celsius to degrees Fahrenheit,
 * given the formula:
 * F = C * (9/5) + 32
 */


#include<stdio.h>

//void assignment2();
int celsiusToFahrenheit(int degInC);
void main(){
	int c;
	int f;
	puts("Enter degrees in Celsius:\n");
	scanf("%d",&c);
	f = celsiusToFahrenheit(c);
	printf("\n%d \n",f);

}

int celsiusToFahrenheit(int degInC){
	int degInF = ((degInC * 9)/5) + 32;
	return degInF;


}
