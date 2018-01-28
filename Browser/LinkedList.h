#ifndef _LINKED_LIST_
#define _LINKED_LIST_

#include <iostream>
#include "Tab.h"

class List
{
private:
	struct Node 
	{
		Tab data;
		Node *prev, *next;
		Node(const Tab& value) 
		{
			data = value;
			prev = next = nullptr;
		}
	};
	unsigned int size;
	Node * head;
	Node * current;

public:
	List();
	List(const List & other);
	List & operator = (const List & other);
	~List();


public:
	void remove(); 
	void insert(); //
	void back(); //
	void forward(); // 
	void print();	//
	void go(const char *); //

private:
	void init();
	void clear();
	void copy(Node * link);
	void copy_(const List & other);
};



#endif // _LINKED_LIST_