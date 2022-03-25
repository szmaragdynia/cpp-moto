#include <iostream>
#include <cmath>
#include <limits>
#include <string>
#include <sstream>
#include <tuple>

class Fence
{
	public:
		Fence(int fence_length = 0, int side_a = 0, int side_b = 0, int area = 0) : m_fence_length(fence_length), m_side_a(side_a), m_side_b(side_b), m_area(area) {};

		std::tuple <Fence, Fence> calculateSidesAndArea(); //possible one or two sets of two values
		bool isEmpty();
		void showResults(Fence& fence_two);
	
	private:
		int m_fence_length;
		int m_side_a;
		int m_side_b;
		int m_area;

		void setFenceLength();
		void calculateArea(); //a*b
		int getArea();
		std::tuple <Fence, Fence> setFenceWithBiggerArea(Fence& fence_two);
	
		
};