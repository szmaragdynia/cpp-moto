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
    if ( !chooseAction() )
		return 0;
	Fence fence_one;
	Fence fence_two;

	std::tie(fence_one, fence_two) = fence_one.calculateSidesAndArea();
	
	fence_one.showResults(fence_two);
	
	
}

bool chooseAction()
{
	cout << "Hello. ";
	
	string action;
	for(int i = 0; i < 10; i++)	//in case of inf loop
	{
		cout << "Please, write \"RUN\" to run the algorithm. Type \"EXIT\" to exit program: ";
		getline(cin, action);
		cin.clear(); //in case of eof  input
		
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
	}; 
	cout << "Too many failed attempts. Exiting.";
	return false;
}


