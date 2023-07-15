#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class student
{
	string name;
	int roll_no,marks[4];
	float t_marks;
	public:
		void input()
		{
			cout<<"Enter the name of the student "<<endl;
			getline(cin,name);
			cout<<"Enter the roll number: "<<endl;
			cin>>roll_no;
			cout<<"Enter total marks: "<<endl;
			cin>>t_marks;
			for (int i=0 ; i < 4 ; i++)
			{
				cout<<"Enter the marks of subject "<<i+1<<endl;
				cin>>marks[i];
			}
			
		}
		float calculate_percentage()
		{
			float sum;
			for (int i=0 ;i < 4 ; i++)
			{
				sum+=marks[i];
			}
			float percentage;
			percentage =(sum/t_marks)*100;
			//cout<<percentage<<endl<<endl;
			return (percentage);
		}
		void show()
		{
			cout<<"Name of student is: "<<name<<endl<<"Roll number is: "<<roll_no<<endl<<"Percentage is: "<<calculate_percentage()<<"%"<<endl<<endl;;
		}
};

void user_input(student* s)
{
	s->input();
	s->show();
}
int main()
{
	student s1;
	user_input(&s1);
}
