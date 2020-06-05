/*
 * standerd_Types.h
 *
 *  Created on: Mar 15, 2020
 *      Author: AymanW
 */

#ifndef STANDERD_TYPES_H_
#define STANDERD_TYPES_H_
	/*unsigned types*/
typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long uint32_t;
typedef unsigned long long uint64_t;
	/*signed types*/
typedef signed char sint8_t;
typedef signed short sint16_t;
typedef signed long sint32_t;
typedef signed long long sint64_t;
	/*float and double*/
typedef float float32_t;
typedef double float64_t;
/*
char* FLOAT_TO_STR(sint16_t num)
{
	static char str[20]="0";
	char rev_str[20]="0";
	uint8_t size=0;
	if(num==0)
	{
		str[0]='0';
		str[1]='.';
		str[2]='0';
		str[3]='0';
		str[4]='\0';
		return str;
	}
	else if(num>0)
	{
		uint16_t i=0;
		uint16_t temp;
		while(num!=0)
		{
			rev_str[i]= ((num%10)+'0');
			num /=10;
			i++;
		}
		
		rev_str[i]='.';
		i++;
		rev_str[i]='0';
		i++;
		rev_str[i]='0';
		i++;
		rev_str[i]='\0';	
		size=i;
		for(i=0;i<=(size-1);i++)
		{
			str[i]=rev_str[size-1-i];
		}
	}
	
}

*/



#endif /* STANDERD_TYPES_H_ */
