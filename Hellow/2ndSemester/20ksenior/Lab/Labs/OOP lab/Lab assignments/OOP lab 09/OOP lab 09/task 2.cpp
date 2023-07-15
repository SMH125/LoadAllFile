#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class shape
{
	float length,height,area;
	public:
		shape(){}
		shape(float l, float h)
		{
			length = l;
			height = h;
		}
		float get_area()
		{
			area = length * height;
			return area;
		}
		shape operator+(shape s1)
		{
			shape s;
			s.length = s1.length + length;
			s.height = s1.height + height;
			//s.area = s1.area + area;
			return (s);
		}
		void operator=(shape s1)
		{
			length = s1.length;
			height = s1.height;
			area = s1.area;
		}
};


int main()
{
	shape shape1(4.67,5.44),shape2(11.45,5.66),shape3;
	shape3 = shape1 + shape2;
	cout<<"Added area of both the objects is: "<<shape3.get_area()<<endl;
}
