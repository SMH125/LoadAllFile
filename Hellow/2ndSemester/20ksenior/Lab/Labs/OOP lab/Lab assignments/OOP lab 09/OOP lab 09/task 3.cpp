#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class perimeter
{
	float height,length;
	public:
		friend class print;
		//void show_values(perimeter &);
		perimeter(float h, float k)
		{
			height = h;
			length = k;
		}
};

class print
{
	public:
		void show_values(perimeter &p)
		{
			cout<<"The perimeter is: "<<(p.height+p.length)<<endl;
		}
		
};


int main()
{
	perimeter p1(55.66,45.6);
	print p;
	p.show_values(p1);
}
