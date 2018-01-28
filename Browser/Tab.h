#ifndef _TAB_
#define _TAB_

#include <iostream>
#include <ctime>

const unsigned empty_tab_size = 12;

class Tab
{
private:
	char * name;
	time_t timer;

public:
	Tab();
	Tab(const char * _name);
	Tab(const Tab & other);
	Tab & operator = (const Tab & other);
	~Tab();

private:
	void copyFrom(const Tab &);
	void clear();

public:
	void setName(const char * name);
	void print() const;
	void resetTime();
};

#endif // _LINKED_LIST_