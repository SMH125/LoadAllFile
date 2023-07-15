#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class A
{
	static int x;
	public:
		A()  //x(5) // default connstructor
		{}
	
	int get_x(){return x;}
};

int A::x= 0;

int main()
{
	A a;
	cout<<a.get_x();
	
}
