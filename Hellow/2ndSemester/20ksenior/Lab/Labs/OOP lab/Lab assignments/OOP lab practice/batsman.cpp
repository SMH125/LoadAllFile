#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class batsman
{
	int id,runs,innings;
	float average;
	string name;
	public:
		static int total_innings;
		batsman(int innings,int runs)
		{
			this->runs = runs;
			this->innings =  innings;
			total_innings = innings;
		}
		batsman(){runs = 0; innings = 0;}
		static void add();
		
		void show()
		{
			//add();
			cout<<"Name is "<<name<<endl;
			cout<<"ID is: "<<id<<endl;
			cout<<"innings played: "<<innings<<endl;
			cout<<"Total innings: "<<total_innings<<endl;
			
		}
		void show_average()
		{
			calculate();
			cout<<"average is: "<<average<<endl;
		}
		void calculate()
		{
			average = runs/innings;
		}
		void input()
		{
			cout<<"Enter name: "<<endl;
			getline(cin,name);
			cout<<"Enter ID: "<<endl;
			cin>>id;
			//cout<<"Enter "
		}
		
static void calc_inn(batsman b){
	total_innings +=b.innings ;
	
}
};
//void batsman::add()
//{
//	total_innings+=batsman::innings;
//}
int batsman::total_innings=0;
//int batsman::total_innings2=0;
int main()
{
	batsman b1(6,200);
	b1.input();
	//b1.show();
	b1.show_average();
	batsman b2;
	b2 = b1;
	//b2.input();
	b2.show();
	b2.show_average();
	b1.calc_inn(b2);
	
	b1.show();	
}
