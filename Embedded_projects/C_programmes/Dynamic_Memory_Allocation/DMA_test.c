/*
 * DMA_test.c
 *
 *  Created on: Mar 15, 2020
 *      Author: AymanW
 */
#include"DMA_FUNC.h"

void main(void)
{
	/*					*/
	insertAtFirst(10);
	insertAtFirst(20);
	//printList();
	/*					*/
	insertAtLast(1);
	insertAtLast(2);
	printList();
	/*					*/
	sizeOfList();
	findItemInTheList(200);
	updateItemInTheList(2,200);
	printList();
	removeNodeFromTheList(200);
	printList();
}
