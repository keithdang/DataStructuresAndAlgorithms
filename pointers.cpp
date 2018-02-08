//this class is just to help me see how to play with pointers
#include "pointers.h"
#include <iostream>
#include <string>

void pointers::start()
{
	int val = 5;
	int *p1;
	int np = val;
	p1 = &val;
	std::cout << "Val: " << val << "\tp1: " << p1 << "\t*p1: " << *p1<<"\tnp:"<<np<<"\n";
	*p1 = 10;
	std::cout << "Assigning *p1=10\nVal: " << val << "\tp1: " << p1 << "\t*p1: " << *p1<<"\tnp:"<<np;
}

pointers::pointers()
{
}


pointers::~pointers()
{
}
