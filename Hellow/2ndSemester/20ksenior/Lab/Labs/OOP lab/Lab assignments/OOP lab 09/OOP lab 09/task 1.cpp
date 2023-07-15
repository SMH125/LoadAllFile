#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class A
{
	int x;
	public:
		//constructors
		A(int x)
		{
			this->x = x;
		}
		//postfix --
		void operator--(int)
		{
			x=x/4;
		}
		void operator--()
		{
			x=x*4;
		}
		void show()
		{
			cout<<x<<endl;
		}
		void set_x(int x)
		{
			this->x = x;
		}
};

int main()
{
	A a1(6);
	--a1;
	cout<<"Pre increment when value entered is 6: "<<endl;
	a1.show();
	a1.set_x(24);
	a1--;
	cout<<"Post increment when value entered is 6: "<<endl;
	a1.show();
}
