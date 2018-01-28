#include <iostream>
#include <Windows.h>
#include "Tab.h"
#include "LinkedList.h"

using namespace std;

const unsigned int MAX_LENGTH = 128;

const char * commands[] =
{
	"GO", "INSERT", "BACK", "FORWARD", "REMOVE", "PRINT"
};

//This function returns an integer of command to be executed in main()
// GO - 0; INSERT - 1; BACK - 2; FORWARD - 3; REMOVE - 4; PRINT - 5
int getCommand(char * source)
{
	short value = -1;
	char temp_buffer[12];
	unsigned short i = 0;
	while (source[i] != ' ' && source[i] != '\0')
	{
		temp_buffer[i] = source[i];
		i++;
	}
	temp_buffer[i] = '\0';
	if (!(strcmp(temp_buffer, commands[0])))
	{
		value = 0;
	}
	else if ((!(strcmp(temp_buffer, commands[1]))))
	{
		value = 1;
	}
	else if ((!(strcmp(temp_buffer, commands[2]))))
	{
		value = 2;
	}
	else if ((!(strcmp(temp_buffer, commands[3]))))
	{
		value = 3;
	}
	else if ((!(strcmp(temp_buffer, commands[4]))))
	{
		value = 4;
	}
	else if ((!(strcmp(temp_buffer, commands[5]))))
	{
		value = 5;
	}

	return value;
}

void get_URL(char * buffer, char * source)
{
	while (*source != '\0')
	{
		*buffer = *source;
		source++;
		buffer++;
	}
	*buffer = '\0';
}

int main()
{
	List a;
	short ret = -1;
	char URL_buffer[MAX_LENGTH];
	char command[MAX_LENGTH];
	while (true)
	{
		cin.getline(command, MAX_LENGTH);
		if (command[0] == '$' && command[1] == ' ')
		{
			ret = getCommand(&command[2]);
		}
		// GO - 0; INSERT - 1; BACK - 2; FORWARD - 3; REMOVE - 4; PRINT - 5
		switch (ret)
		{
		case 0:
			// $ GO <- the length of this is 4, the 5th element is supposed to be the beginning of the URL
			get_URL(URL_buffer, (&command[5]));
			a.go(URL_buffer);
			break;
		case 1:
			a.insert();

			//if there is URL after the INSERT command
			//$ INSERT <- length of this is 8, the 9th is supposed to be the beginning of the URL
			if (strlen(command) > 9)
			{
				get_URL(URL_buffer, (&command[9]));
				a.go(URL_buffer);
			}
			break;
		case 2:
			a.back();
			break;
		case 3:
			a.forward();
			break;
		case 4:
			a.remove();
			break;
		case 5:
			a.print();
			break;
		default:
			break;
		}
		ret = -1;
	}

	return 0;
}