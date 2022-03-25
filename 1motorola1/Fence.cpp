#include <iostream>
#include <cmath>
#include <tuple>
#include <limits>
#include <string>
#include <sstream>
#include "Fence.hpp"
#include "Utilities.hpp"

using std::cout;
using std::cin;
using std::string;



std::tuple <int,int,int,int> Fence::calculateFenceSides()
{
	m_fence_length = getFenceLength();
	float side_a_float = m_fence_length /4.0; //parabola's tip coordinate - parabola equation: -2a^2 + a*fence_length

	if( isInteger(side_a_float) )
	{
		m_side_a = static_cast<int>(side_a_float);
		m_side_b = m_fence_length /2; //resulting from 2a_side+b_side=fence_length, when a_side is at parabola's tip.
		return std::make_tuple(m_side_a, m_side_b, 0, 0);
	}
	else //find floor and ceiling "side_a" integers and solve for b. 
	{
		int side_a_first = floor(side_a_float);
		int side_b_first = m_fence_length - 2*side_a_first;
		int side_a_second = ceil(side_a_float);
		int side_b_second = m_fence_length - 2*side_a_second;

		if (side_a_first > 0 && side_b_first > 0)
		{
			m_side_a = side_a_first;
			m_side_b = side_b_first;

			if (side_a_second > 0 && side_b_second > 0)
			{
				Fence fence_two;
				fence_two.m_fence_length = this->m_fence_length;	//lepiej konstruktorem

			}
		}
		return std::make_tuple(side_a_first, side_b_first, side_a_second, side_b_second);
	}

}

int Fence::getFenceLength()
{
	int fence_length = 0;
	do
	{
		cout << "Enter the length (in meters) of fence available (min. 3m).\n";	//if length < 3, then no positive integer sides possible
		fence_length = getInt();
		
	}while (fence_length < 3); //zrob mozliwosc wyjscia stad + tez 10 podejsc (TODO EXCEPTION) - bo tez inaczej przejdzie dalej
								//moze mozna te petle zmergowac nie wiem
	
	return fence_length;
}

int Fence::calculateArea(int side_a, int side_b)
{
	return side_a*side_b;
}


void Fence::showResults()
{
	int side_a_first, side_b_first, side_a_second, side_b_second;
	std::tie(side_a_first, side_b_first, side_a_second, side_b_second) = calculateFenceSides();
	int optimal_area = 0;

	cout << "Your optimal fence sides are: \n";
	if (side_a_first > 0 && side_b_first > 0)
	{
		cout << "a = " << side_a_first << ", b = " << side_b_first << std::endl;
		optimal_area = calculateArea(side_a_first, side_b_first);
	}
	if(side_a_second > 0 && side_b_second > 0)
	{
		cout << "a = " << side_a_second << ", b = " << side_b_second <<std::endl;
		optimal_area = calculateArea(side_a_second, side_b_second);
	}
	cout << "Optimal area is " << optimal_area << "m^2";
}