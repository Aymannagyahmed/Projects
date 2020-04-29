/*
 * DMA_FUNC.h
 *
 *  Created on: Mar 16, 2020
 *      Author: AymanW
 */

#ifndef DMA_FUNC_H_
#define DMA_FUNC_H_
#include<stdio.h>
/* to use functions of DMA */
#include<stdlib.h>
/*to appear error message in run time*/
#include<assert.h>
struct node
{
	int data;
	struct node* next;
};

void insertAtFirst(int ddata);
void printList(void);
void insertAtLast(int data);
void sizeOfList(void);
void findItemInTheList(int item);
void updateItemInTheList(int old, int new);
void removeNodeFromTheList(int data);

#endif /* DMA_FUNC_H_ */
