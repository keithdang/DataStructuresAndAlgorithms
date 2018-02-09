#include "doubleLinkedList.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;
void doubleLinkedList::start()
{
	cout << "Double Linked List\n";
	struct Node *node = NULL;
	struct Node *lastNode = NULL;
	createList(&node, 8, 9);
	printList(node);
	lastNode = node;
	getLastNode(&lastNode);
	cout << "\nLastNode:" << lastNode->data << "\n";
	pop(&lastNode);
	cout << "Pop\nLastNode:" << lastNode->data << "\n";
	printList(node);
	
	cout << "\nFirst Node:" << node->data << "\n";
	enqueue(&node,7);
	cout << "\nEnqueue Node:" << node->data << "\n";
	printList(node);
	cout << "\nDequeue\nNode:" << lastNode->data << "\n";
	dequeue(&lastNode);
	printList(node);
}
void doubleLinkedList::createList(struct Node **head_ref, int amount, int range)
{
	int appOrPush;
	int randNum;
	for (int i = 0; i < amount; i++)
	{
		appOrPush = rand() % 2;
		randNum = rand() % range;
		{
			if(appOrPush==0)
			{
				cout << "Push\n";
				push(head_ref, randNum);
			}
			else
			{
				cout << "Append\n";
				stackPush(head_ref, randNum);
			}
		}
	}
}
void doubleLinkedList::enqueue(struct Node **head_ref, int new_data)
{
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));

	new_node->data = new_data;
	new_node->next = (*head_ref);
	new_node->prev = NULL;
	if (*head_ref != NULL)
	{
		(*head_ref)->prev = new_node;
	}
	(*head_ref) = new_node;
	return;
}
void doubleLinkedList::dequeue(struct Node **head_ref)
{
	(*head_ref) = (*head_ref)->prev;
	(*head_ref)->next = NULL;
}
void doubleLinkedList::pop(struct Node **head_ref)
{
	while ((*head_ref)->next != NULL)
	{
		(*head_ref) = (*head_ref)->next;
	}
	(*head_ref) = (*head_ref) -> prev;
	(*head_ref)->next = NULL;
}
void doubleLinkedList::getLastNode(struct Node **node)
{
	while ((*node)->next != NULL)
	{
		(*node) = (*node)->next;
	}
}
void doubleLinkedList::printList(struct Node *node)
{
	struct Node *last=NULL;
	cout << "\nTransversing forward direction\n";
	while (node != NULL)
	{
		cout << node->data;
		last = node;
		node = node->next;
	}
	cout << "\nTransversing reverse direction\n";
	while (last != NULL)
	{
		cout << last->data;
		last = last->prev;
	}
}
void doubleLinkedList::push(struct Node **head_ref, int new_data)//puts it at the beginning of the node
{
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
	
	new_node->data = new_data;
	new_node->next = (*head_ref);
	new_node->prev = NULL;
	if (*head_ref != NULL)
	{
		(*head_ref)->prev = new_node;
	}
	(*head_ref) = new_node;
	return;
}
void doubleLinkedList::stackPush(struct Node **head_ref, int new_data)//this is a push in the stack
{
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
	struct Node *last = *head_ref;
	new_node->data = new_data;
	new_node->next = NULL;
	if (*head_ref == NULL)
	{
		new_node->prev = NULL;
		*head_ref = new_node;
		return;
	}
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next=new_node;
	new_node->prev = last;
	return;
}
doubleLinkedList::doubleLinkedList()
{
}


doubleLinkedList::~doubleLinkedList()
{
}
