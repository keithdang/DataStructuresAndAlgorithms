#pragma once
class doubleLinkedList
{
public:
	struct Node
	{
		int data;
		struct Node *prev;
		struct Node *next;
	};
	void start();
	void printList(struct Node *node);
	void append(struct Node **head_ref, int new_data);
	void push(struct Node **head_ref, int new_data);
	void getLastNode(struct Node **head_ref);
	void pop(struct Node **head_ref);
	void createList(struct Node **head_ref, int amount, int range);
	doubleLinkedList();
	~doubleLinkedList();
};

