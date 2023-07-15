#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class shape
{
	public:
		float virtual getArea()=0;
};

class triangle : public shape
{
	float base,alt;
	public:
		triangle(float b, float a)
		{
			base = b;
			alt = a;
		}
		triangle(){}
		float getArea()
		{
			return (0.5*base*alt);
		}
};

class rectangle
{
	float width,height;
	public:
		rectangle(float w, float h)
		{
			width = w;
			height = h;
		}
		rectangle(){}
		float getArea()
		{
			return (width*height);
		}
};

int main()
{
	triangle t1(55.6,11.5);
	rectangle r1(33.44,45.55);
	cout<<"The area of triangle is: "<<t1.getArea()<<" sq meters"<<endl;
	cout<<"The area of rectangle is: "<<r1.getArea()<<" sq meters"<<endl;
}
