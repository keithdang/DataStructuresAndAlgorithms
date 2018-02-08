#include "linkedList.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;
struct nodeL
{
	int key;
	struct nodeL *nextNode;
};
struct nodeL *newNode(int item)
{
	struct nodeL *temp = (struct nodeL *)malloc(sizeof(new nodeL));
	temp->key = item;
	temp->nextNode = NULL;
	return temp;
}
struct nodeL *head;
struct nodeL *insertNode(struct nodeL *node, int item)
{
	if (node == NULL)
	{
		return newNode(item);
	}
	else
	{
		node->nextNode = insertNode(node->nextNode, item);
	}
	return node;
}
void linkedList::insertAtStart(int val)
{
	struct nodeL *temp = (struct nodeL *)malloc(sizeof(new nodeL));
	temp->key = val;
	temp->nextNode = NULL;
	if (head != NULL)
	{
		temp->nextNode = head;
	}
	head = temp;
}
void linkedList::printNode(struct nodeL *node)
{
	if (node != NULL)
	{
		cout << node->key << "\n";
		printNode(node->nextNode);
	}
}
void linkedList::deleteNode(struct nodeL *node, int val)
{
	if (node->nextNode->key == val)
	{
		cout << "Found val: " << val << "\n";
		node->nextNode=node->nextNode->nextNode;
	}
	else
	{
		deleteNode(node->nextNode, val);
	}
}
void linkedList::start()
{
	cout << "Linked List\n";
	struct nodeL * root = NULL;
	root = insertNode(root, 5);
	insertNode(root, 10);
	insertNode(root, 7);
	insertNode(root, 4);
	insertNode(root, 15);
	deleteNode(root, 4);
	printNode(root);

	cout << "\nAnother list\n";
	
	insertAtStart(1);
	insertAtStart(3);
	insertAtStart(2);
	insertAtStart(4);
	struct nodeL * root2=head;
	while (root2 != NULL)
	{
		cout << root2->key<<"\n";
		root2 = root2->nextNode;
	}

}
linkedList::linkedList()
{
}


linkedList::~linkedList()
{
}
