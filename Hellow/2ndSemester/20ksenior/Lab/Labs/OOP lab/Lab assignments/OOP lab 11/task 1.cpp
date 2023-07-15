#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class employee
{
	protected:
		string name,code;
		employee(string n, string c)
		{
			name = n;
			code = c;
		}
};

class consultant : virtual public employee
{
	protected:
		int yearsofexp;
		consultant (string n, string c,int y) : employee(n,c) 
		{
			yearsofexp = y;
		}
};

class manager : virtual public employee
{
	protected:
		int noofteams;
		manager(string n, string c, int no) : employee(n,c) 
		{
			noofteams = no;
		}
};

class consultantmanager : public consultant, public manager
{
	public:
		consultantmanager(string n, string c,int y, int no) : consultant(n,c,y),manager(n,c,no),employee(n,c)
		{
			
		}
		void display()
		{
			cout<<"The name is: "<<name<<endl<<"Code is: "<<code<<endl<<"Years of experience: "<<yearsofexp<<endl<<"No of teams is: "<<noofteams<<endl;	
		}	
};

int main()
{
	consultantmanager c1("Ali","S-123",17,5);
	c1.display();
	return 0;
}
