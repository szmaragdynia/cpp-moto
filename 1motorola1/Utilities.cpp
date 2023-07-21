#include <iostream>
#include <string>
#include <sstream>

using std::cout;
using std::cin;
using std::string;

int getInt()
{
	string input = "";
	int input_int = 0;
	bool is_convert_ok = false;
	while (!is_convert_ok)
	{
		cout << "Please enter: ";
		getline(std::cin, input);
		cin.clear();	//in case of eof

		std::stringstream convert_stream(input);
		if(convert_stream >> input_int) //trying to read int if it's at the first place
		{
			string leftovers;
			getline(convert_stream, leftovers);	//reading anything after int
			if(leftovers == "")
			{
				is_convert_ok = true; //it was empty; user input consisted only of an int number
				return input_int;
			}
			else
			{
				cout << "Invalid input type. Accepting only integers.\n";
			}
		} 
		else //there was not an int in the first place
		{
			cout << "Invalid input type. Accepting only integers.\n";
		}
	}
}

bool isInteger(float value)
{
	return trunc(value) == value;
}