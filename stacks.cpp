//First In Last Out
#include "stacks.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

void stacks::start()
{
	cout << "Stacks\n";
	struct node *root = NULL;
	struct node *tail = NULL;
	struct node *head = NULL;
	root = createList(root, 10, 10);
	head = root;
	tail = endOfList(root);
	printList(root);
	printList(tail); 
	pop(root);
	printList(root);
	printList(head);
}
void stacks::printList(struct stacks::node *node)
{
	cout << "Printing list\n";
	while (node != NULL)
	{
		cout << node->key << "\n";
		node = node->next;
	}
}
struct stacks::node *stacks::endOfList(struct stacks::node *node)
{
	while (node->next != NULL)
	{
		node = node->next;
	}
	return node;
}
void stacks::pop(struct stacks::node *node)
{
	while (node->next->next != NULL)
	{
		node = node->next;
	}
	node->next = NULL;
}
struct stacks::node *stacks::newNode(int val)
{
	struct stacks::node *temp = (struct stacks::node *)malloc(sizeof(new stacks::node));
	temp->key = val;
	temp->next = NULL;
	return temp;
}
struct stacks::node *stacks::insertAtEnd(struct stacks::node *node, int val)
{
	if (node == NULL)
	{
 		node = newNode(val);
	}
	else
	{
		node->next = insertAtEnd(node->next, val);
	}
	return node;
}
struct stacks::node *stacks::insertAtStart(struct stacks::node *node, int val)
{
	if (node == NULL)
	{
		node = newNode(val);
	}
	else
	{
		struct stacks::node *temp = (struct stacks::node *)malloc(sizeof(new stacks::node));
		temp->key = val;
		temp->next = node;
		node = temp;
	}
	return node;
}
struct stacks::node *stacks::createList(struct stacks::node *node, int amount, int range)
{
	int randNum;
	for (int i = 0; i < amount; i++)
	{
		randNum = rand() % range;
		node = insertAtEnd(node, randNum);
		//node = insertAtStart(node, randNum);
	}
	return node;
}

stacks::stacks()
{
}


stacks::~stacks()
{
}
