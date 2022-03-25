#include <iostream>
#include <cmath>
#include <tuple>
#include <limits>
#include <string>
#include <sstream>

class Fence
{
    public:
    //const dest?...copying constr..?:|
    void showResults();

    private:
		int m_side_a=0;
		int m_side_b=0;
		int m_fence_length = 0;
		int getFenceLength();
		std::tuple <int, int, int, int> calculateFenceSides(); //possible one or two sets of two values
		int calculateArea(int, int); //a*b
        

};