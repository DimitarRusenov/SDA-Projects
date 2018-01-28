#include "Tab.h"

Tab::Tab()
{
	name = new char[empty_tab_size];
	strcpy_s(name, empty_tab_size, "about:blank");
	timer = time(0);
};

Tab::Tab(const char * _name)
{
	name = new char[strlen(_name) + 1];
	strcpy_s(name, strlen(_name) + 1, _name);
	timer = time(0);
}

Tab::Tab(const Tab & other)
{
	copyFrom(other);
}

Tab & Tab :: operator = (const Tab & other)
{
	if (this != &other)
	{
		clear();
		copyFrom(other);
	}

	return *this;
}

Tab::~Tab()
{
	clear();
}

void Tab::print() const
{
	int i = 0;
	while (name[i] != '\0')
	{
		std::cout << name[i];
		i++;
	}
	std::cout << " " << timer << std::endl;
}

void Tab::copyFrom(const Tab & other)
{
	if (other.name != nullptr)
	{
		name = new char[strlen(other.name) + 1];
		strcpy_s(name, strlen(other.name) + 1, other.name);
		timer = time(0);
	}
}

void Tab::clear()
{
	delete[] name;
	name = nullptr;
}


void Tab::setName(const char * _name)
{
	clear();
	name = new char[strlen(_name) + 1];
	strcpy_s(name, strlen(_name) + 1, _name);
}

void Tab::resetTime()
{
	timer = time(0);
}