#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class movie 
{
		string MPAA_rating,name;
		int no_of_ratings;
		float r1,r2,r3,r4,r5;
		float avg;
		public:
			// Parametrized constructor
			movie (string movie, string rating)
			{
				name = movie;
				MPAA_rating = rating;
				r1=0;r2=0;r3=0;r4=0;r5=0;avg=0;
				no_of_ratings = 0;
			}
			// Default constructor
			movie ()
			{}
		//setter functions
			void set_name_rating(string movie, string rating)
			{
				name = movie;
				MPAA_rating = rating; 
			}
			void add_rating(int n)
			{
				if (n>=1 && n<=5)
				{
					no_of_ratings++;
					if (n==1)
					r1++;
					if (n==2)
					r2++;
					if (n==3)
					r3++;
					if (n==4)
					r4++;
					if (n==5)
					r5++;
					float temp;
					temp = (r1*1)+(r2*2)+(r3*3)+(r4*4)+(r5*5);
					avg = temp/no_of_ratings;
				}
				else
				cout<<"Invalid input"<<endl;
			}
			
			void show()
			{
				cout << "Name of movie is "<<name<<endl;
				cout <<"Rating of movie is "<<MPAA_rating<<endl;
				cout <<"Average rating of movie (out of 5) is: "<<setprecision(3)<<avg<<endl<<endl;
			}
			//getter functions
			float get_avg()
			{return avg;}
			string get_MPAA_rating ()
			{return MPAA_rating;}
			string get_name()
			{return name;}
		
};
// Global initilization of objects using paramterized constructor. Can also be added by user
movie m1("DDLJ","pg-13"),m2("PK","r"),m3("Dark","G");
void user_input()
{
	// code for user input name of movie, rating:
	/*
		string name,rating;
		cout << "Enter the name of the movie<<endl;
		fflush(stdin);
		getline(cin,name);
		cout << "Enter the rating for the movie"<<endl;
		fflush(stdin);
		getline(cin,rating);
		movie m1;
		m1.set_name_rating(name,rating);
	*/
	string name,m_name1,m_name2,m_name3;
	string MPAA1,MPAA2,MPAA3;
	m_name1 = m1.get_name();m_name2 = m2.get_name();m_name3 = m3.get_name();
	MPAA1 = m1.get_MPAA_rating(); MPAA2 = m2.get_MPAA_rating(); MPAA3 = m3.get_MPAA_rating(); 
	int rating;
	while(1)
	{
		system("CLS");
	
	cout << "List of movies are: "<<endl;
	cout << m_name1<<endl<<m_name2<<endl<<m_name3<<endl;
	cout << "Enter the name of the movie you want to rate"<<endl;
	cin>>name;
	if (name == m_name1)
	{
		cout<<"Rate the movie on a scale of 1 to 5"<<endl;
		cin>>rating;
		m1.add_rating(rating);	
	}
	else if (name == m_name2)
	{
		cout <<"Rate the movie on a scale of 1 to 5 "<<endl;
		cin>>rating;
		m2.add_rating(rating);
	}
	else if (name == m_name3)
	{
		cout <<"Rate the movie on a scale of 1 to 5 "<<endl;
		cin>>rating;
		m3.add_rating(rating);
	}
	else
	{
		cout<<"The name of the movie does not exist in our records. Please try next time"<<endl;
	}
	char ch;
	cout <<"Press e or E if you want to exit or any other key to continue"<<endl;
	fflush(stdin);
	cin>>ch;
	if (ch=='e'||ch=='E')
	{
		break;
	}
	
	}
}
int main()
{
	user_input();
	m1.show();
	m2.show();
	m3.show();
	return 0;	

}
