#pragma once
class linkedList
{
public:
	void start();
	void printNode(struct nodeL *node);
	void deleteNode(struct nodeL *node, int val);
	void insertAtStart(int val);
	linkedList();
	~linkedList();
};

