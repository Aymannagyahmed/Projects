/*
 * DMA_FUNC.c
 *
 *  Created on: Mar 16, 2020
 *      Author: AymanW
 */
#include"DMA_FUNC.h"
struct node* head=NULL;
//struct node* current=NULL;
void insertAtFirst(int ddata)
{
	//1-creat node
	struct node* link= (struct node*)malloc(sizeof(struct node));
	//2-set data
	link->data= ddata;
	//3-ptr_node = head
	link->next= head;
	//4-head = new_node
	head= link;
}
void insertAtLast(int data)
{
	struct node* link=(struct node*)malloc(sizeof(struct node));
	link->data=data;
	link->next=NULL;
	///////////////////////////////////
	// If head is empty, create new list
	   if(head==NULL)
	   {
	      head = link;
	      return;
	   }

	struct node* current=head;
	while(current->next!=NULL)
	{
		current=current->next;
	}
	current->next=link;

}
void sizeOfList(void)
{
	int size=0;
	struct node* ptr=head;
	if(head==NULL)
	{
		printf("size of list is (%d)\n",size);
		return;
	}
	while(ptr!=NULL)
	{
		size++;
		ptr=ptr->next;
	}
	printf("size of list is (%d)\n",size);
}
void findItemInTheList(int item)
{
	int numOfNode=1;
	struct node* current=head;
	if(head==NULL)
		{
			printf("Empty list \n");
			return;
		}
	while(current!=NULL)
	{
		if(current->data==item)
		{
			printf("found (%d) in node num (%d)\n",item,numOfNode);
			return;
		}
		current=current->next;
		numOfNode++;

	}
	printf("(%d) is not found\n",item);

}

void updateItemInTheList(int old, int new)
{
	struct node* current=head;
	if(head==NULL)
	{
		printf("list is Empety\n");
		return;
	}
	while(current!=NULL)
	{
		if(current->data==old)
		{
			current->data=new;
			printf("(%d) updated to (%d)\n",old,new);
			return;
		}
		current=current->next;
	}
	printf("data not found\n");
}

void removeNodeFromTheList(int data)
{
	int position=1;
	struct node* current=head;
	struct node* aftercurrent=current->next;
	if(head==NULL)
	{
		printf("list is Empety\n");
		return;
	}
	if(head->data==data)
	{
		head=head->next;
		free(current);
		printf("%d found at position %d and deleted \n", data, position);
		return;
	}
	position=2;
	while(aftercurrent!=NULL)
	{
		if(aftercurrent->data==data)
		{
			current->next=aftercurrent->next;
			free(aftercurrent);
			printf("%d found at position %d and deleted \n", data, position);
			return;
		}
		current=current->next;
		aftercurrent=aftercurrent->next;
		position++;
	}
	printf("data not found\n");
}

void printList(void)
{
	struct node* ptr=head;
	printf("[head] =>");
	//////////////////////////
	while(ptr!=NULL)
	{
		//printf("(%p)",ptr->next);
		printf("%d =>",ptr->data);
		ptr= ptr->next;
	}
	printf(" [null]\n");

}



