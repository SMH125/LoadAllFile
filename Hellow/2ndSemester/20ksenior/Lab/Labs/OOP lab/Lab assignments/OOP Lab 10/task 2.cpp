#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//abstract class
class car
{
	protected:
	string model;
	float price;
	public:
		void set_model(string m)
		{
			model = m;
		}
		// pure virtual func
		void virtual set_price(float p)=0;
		void show()
		{
			cout<<"The model is: "<<model<<endl;
			cout <<"The price is: "<<price<<endl;
		}
};

class color : public car
{
	public:
		void set_price(float p)
		{
			price = p;
		}
};

class company : public car
{
	public:
		void set_price(float p)
		{
			price = p;
		}
};

int main()
{
	color c1;
	company cm1;
	c1.set_model("2002");
	c1.set_price(45679.98);
	c1.show();
	cm1.set_model("2012");
	cm1.set_price(45678.09);
	cm1.show();
}
