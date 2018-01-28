#include "LinkedList.h"

void List::print()
{
	Node * element = this->head;
	while (element != nullptr)
	{
		if (element == current)
		{
			std::cout << ">";
		}
		element->data.print();
		element = element->next;
	}
}

void List::init()
{
	Tab tab;
	Node * element = new Node(tab);
	this->head = element;
	this->current = element;
	size = 1;
}

void List::clear()
{
	Node * element;
	while (this->head != nullptr)
	{
		element = this->head;
		this->head = this->head->next;
		delete element;
	}
	size = 0;
	this->head = nullptr;
	this->current = nullptr;
}



void List::copy(Node * link)
{
	//clear();
	this->head = nullptr;
	this->current = nullptr;
	this->size = 0;
	while (link != nullptr)
	{
		Node * element = new Node(link->data);
		if (this->size == 0)
		{
			this->head = element;
			this->current = element;
			element->prev = nullptr;
			element->next = nullptr;
		}
		else
		{
			current->next = element;
			current->next->prev = current;
			current = element;
		}
		
		this->size++;
		link = link->next;
	}
}

void List::copy_(const List & other)
{
	copy(other.head);

	this->current = this->head;
	Node * temp = other.head;
	while (temp != other.current)
	{
		temp = temp->next;
		current = current->next;
	}
}


void List :: forward()
{
	if (this->current->next != nullptr)
	{
		this->current = this->current->next;
	}
}

void List::back()
{
	if (this->current->prev != nullptr)
	{
		this->current = this->current->prev;
	}
}

List::List()
{
	init();
}

List::List(const List & other)
{
	copy_(other);
}

List & List :: operator = (const List & other)
{
	if (this != &other)
	{
		clear();
		copy(other.head);
	}

	return *this;
}

List::~List()
{
	clear();
}

void List:: go(const char * URL)
{
	current->data.setName(URL);
	current->data.resetTime();
}

void List::insert()
{
	Tab tab;
	Node * element = new Node(tab);
	element->next = this->current->next;
	element->prev = current;
	this->current->next = element;
	this->current = element;
	this->size++;
}

void List::remove()
{	
	if (current->next == nullptr)
	{
		if (current->prev == nullptr)
		{
			// there is only one element
			delete current;
			init();

		}
		else
		{
			// it's the last element
			Node * node;
			node = current;
			current = current->prev;
			current->next = nullptr;
			delete node;
		}
	}
	else
	{
		Node * node;
		node = current;
		current->prev->next = current->next;
		current->next->prev = current->prev;
		current = current->next;
		delete node;
	}
}