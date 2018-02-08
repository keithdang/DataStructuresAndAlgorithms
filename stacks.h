#pragma once
class stacks
{
public:
	struct node
	{
		int key;
		node *next;
	};
	void start();
	void printList(struct node *node);
	void pop(struct node *node);
	struct node *newNode(int val);
	struct node *insertAtEnd(struct node *node, int val);
	struct node *insertAtStart(struct node *node, int val);
	struct node *createList(struct node *node, int amount, int range);
	struct node *endOfList(struct node *node);
	stacks();
	~stacks();
};

