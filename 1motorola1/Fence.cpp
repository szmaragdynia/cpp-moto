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



//--------------public

std::pair <Fence, Fence> Fence::calculateSidesAndArea()
{
	setFenceLength();
	float side_a_float = m_fence_length / 4.0; //parabola's tip coordinate - parabola equation: -2a^2 + a*fence_length; equation describes side a as a function of area
	Fence fence_two;

	if (isInteger(side_a_float))	//if max floating-point area results in integer sides
	{
		m_side_a = static_cast<int>(side_a_float);
		m_side_b = m_fence_length / 2; //resulting from 2a_side+b_side=fence_length, when a_side is at parabola's tip.
		calculateArea();
		return std::make_pair(*this, fence_two);
	}
	else //find floor and ceiling od "side_a" and solve for b. 
	{
		int side_a_first = floor(side_a_float);
		int side_b_first = m_fence_length - 2 * side_a_first;
		int side_a_second = ceil(side_a_float);
		int side_b_second = m_fence_length - 2 * side_a_second;

		if (side_a_first > 0 && side_b_first > 0) //if first solution is possible,set it
		{
			*this = Fence(this->m_fence_length, side_a_first, side_b_first);
			calculateArea();

			if (side_a_second > 0 && side_b_second > 0) //check if another solution exists
			{
				fence_two = Fence(this->m_fence_length, side_a_second, side_b_second);
				fence_two.calculateArea();

				return setFenceWithBiggerArea(fence_two);
			}
		}
		else if (side_a_second > 0 && side_b_second > 0) //if first solution not possible, check if second is possible,zero first and use second solution.
		{
			fence_two = Fence(this->m_fence_length, side_a_second, side_b_second);
			fence_two.calculateArea();

			*this = Fence();

			return std::make_pair(*this, fence_two);
		}

	}

}

bool Fence::isEmpty()
{
	if (m_fence_length == 0)
		return true;
	else
		return false;
}

void Fence::showResults(Fence& fence_two)
{
	cout << "Your optimal fence sides are: \n";

	if (!this->isEmpty())
	{
		cout << "a = " << this->m_side_a << ", b = " << this->m_side_b << std::endl;
		if (!fence_two.isEmpty())
		{
			cout << "a = " << fence_two.m_side_a << ", b = " << fence_two.m_side_b << std::endl;
			cout << "This results in area of " << m_area << " m^2" << std::endl;	//if both not empty, area is the same
		}
		else
			cout << "This results in area of " << m_area << " m^2" << std::endl;
	}
	else if (!fence_two.isEmpty())
	{
		cout << "a = " << fence_two.m_side_a << ", b = " << fence_two.m_side_b << std::endl;
		cout << "This results in area of " << fence_two.getArea() << " m^2" << std::endl;

	}
	else
		cout << "We could not calculate the integer sides out of given fence length." << std::endl;
}



//--------------private

void Fence::setFenceLength()
{
	int fence_length = 0;
	do
	{
		cout << "Enter the length (in meters) of fence available (min. 3m).\n";	//if length < 3, then no positive integer sides possible
		fence_length = getInt();

	} while (fence_length < 3);

	m_fence_length = fence_length;
}

void Fence::calculateArea()
{
	m_area = m_side_a * m_side_b;
}

int Fence::getArea()
{
	return m_area;
}

std::pair <Fence, Fence> Fence::setFenceWithBiggerArea(Fence& fence_two)
{
	if (fence_two.getArea() == this->m_area)	//if areas to both solutions equal
		return std::make_pair(*this, fence_two);
	else if (fence_two.getArea() > this->m_area)	//else zero the smaller one
	{
		*this = Fence();
		return std::make_pair(*this, fence_two);
	}
	else if (fence_two.getArea() < this->m_area)	//else zero the smaller one
	{
		fence_two = Fence();
		return std::make_pair(*this, fence_two);
	}
}


