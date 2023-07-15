#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class person
{
	protected:
	string name;
	float salary,bonus;
	public:
		person()
		{
			salary = 0;
			bonus = 0;
		}
		void virtual set_data(string n,float s){}
		void virtual cal_bonus(float b){}
		void virtual show(){}
};

class account : virtual public person
{
	public:
		void cal_bonus(float b)
		{
			bonus = b;
			//cout<<"The bonus of account class is "<<bonus<<endl;
		}
		void show()
		{
			cout<<"Name is: "<<name<<endl<<"Salary is: "<<salary<<endl<<"Bonus is: "<<bonus<<endl<<"account class";	
		}
		void set_data(string n,float s)
		{
			name = n;
			salary = s;
		}
};

class admin : virtual public person
{
	public:
		void cal_bonus(float b)
		{
			bonus = b;
			//cout<<"The bonus of admin class is "<<bonus<<endl;
		}
		void show()
		{
			cout<<"Name is: "<<name<<endl<<"Salary is: "<<salary<<endl<<"Bonus is: "<<bonus<<endl<<"admin class";	
		}
		void set_data(string n,float s)
		{
			name = n;
			salary = s;
		}
};

class master : public admin, public account
{
	
	public:
		void show()
		{
			cout<<"Name is: "<<name<<endl<<"Salary is: "<<salary<<endl<<"Bonus is: "<<bonus<<endl<<"class master"<<endl;	
		}
		void set_data(string n, float s)
		{
			name =n;
			salary = s;
		}
		void cal_bonus(float b)
		{
			bonus = b;
		}
		
};

int main()
{
	person *ptr;
	master m;
	ptr = &m;
	ptr->set_data("Ammar",78600.98);
	ptr->cal_bonus(1400);
	ptr->show();
}
