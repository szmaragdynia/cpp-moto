#include <iostream>
#include <cmath>
#include <tuple>
#include <limits>
#include <string>
#include <sstream>
#include "Fence.hpp"

using std::cout;
using std::cin;
using std::string;

bool chooseAction(); //Present choices

int main()
{
    if ( !chooseAction() )//raczej zmienic na wyjatki; jezu ale brzydkie; TODO EXCEPTION
		return 0;
	Fence fence;

	fence.showResults();
	
}

bool chooseAction()
{
	cout << "Hello. ";
	
	string action;
	for(int i = 0; i < 10; i++)	//in case of inf loop
	{
		cout << "Please, write \"RUN\" to run the algorithm. Type \"EXIT\" to exit program: ";
		getline(cin, action);
		cin.clear(); //in case of eof 
		
		if (action == "RUN")
		{
			return true;
		}
		else if (action == "EXIT")
		{
			cout << "Exiting";
			return false;
		}
		else
		{
			cout << "Bad argument. " << 9 - i << " attempts remaining\n";
		}
	}; //??TODO EXCEPTION - bo inaczej przechodzi dalej! + zrob mozliwosc wyjscia; a moze zrobic zamiast bool to enumy..?
	cout << "Too many failed attempts. Exiting.";
	return false;
}


