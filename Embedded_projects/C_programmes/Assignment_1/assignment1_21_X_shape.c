/*
 * assignment1_21.c
 *
 *  Created on: Feb 3, 2020
 *      Author: AymanW
 *  print a star or X pattern
 */
#include<stdio.h>


void main(){

    int i;
    int j;
    int size;
    //2
    printf("Enter number of lines : \n");
    fflush(stdout);
    scanf("%d",&size);
    for(i=0;i<size;i++)
    {
        for(j=0; j < size ;j++)
        {
            //5
            if(i==j || j==(size-i-1))
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        //6
        printf("\n");
    }

}

