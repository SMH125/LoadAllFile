#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
struct date
{
	int day,year;
	string month;
};
class sales
{
	protected:
	float sales[3];
	
	void get_data()
	{
		for (int i = 0; i<3 ; i++)
		{
			cout<<"Enter the sales of month "<<i+1<<endl;
			cin>>sales[i];
		}
	}
	void put_data()
	{
		cout<<"The sales of three months are as follows: "<<endl;
		for (int i = 0; i<3 ; i++)
		{
			cout<<"Month "<<i+1<<" : "<<sales[i]<<endl;
		}
	}
	
};
class publication
{
	protected:
	string title;
	float price;
	void get_data()
	{
		cout<<"Enter title: "<<endl;
		getline(cin,title);
		//fflush(stdin);
		cout<<"Enter price: "<<endl;
		cin>>price;
	}
	void put_data()
	{
		fflush(stdin);
		cout<<"Title is: "<<title<<endl;
		cout<<"Price is: Rs "<<price<<endl;
	}
};
class publication2 : public publication
{
	protected:
		date d;
		
		void get_data()
		{
			publication::get_data();
			cout<<"Enter the date of publish: "<<endl;
			cin>>d.day;
			cout<<"Enter the month of publish: "<<endl;
			fflush(stdin);
			getline(cin,d.month);
			cout<<"Enter the year of publish: "<<endl;
			cin>>d.year;
		}
		void put_data()
		{
			publication::put_data();
			cout<<"Date of publish is: "<<d.day<<" "<<d.month<<" "<<d.year<<endl;
			
		}
};
class disc : public publication2 , public sales
{
	string type;
	public:
	void get_data()
	{
		publication2::get_data();
		cout<<"Enter the type of the disc (CD or DVD): "<<endl;
		fflush(stdin);
		getline(cin,type);
		sales::get_data();	
		
	}	
	void put_data()
	{
		publication2::put_data();
		cout<<"The type of disc is: "<<type<<endl;	
		sales::put_data();
		cout<<endl<<endl;
	}	
};
class book : public publication2, public sales
{
	int page_count;
	public:
		void get_data()
		{
			publication2::get_data();
			cout<<"Enter the number of pages: "<<endl;
			cin>>page_count;
			sales::get_data();	
		}
		void put_data()
		{
			publication2::put_data();
			cout<<"The number of pages are: "<<page_count<<" pages"<<endl<<endl;	
			sales::put_data();
		}	
};

class tape : public publication2 , public sales
{
	float p_time;
	public:
		void get_data()
		{
			publication2::get_data();
			cout<<"Enter the playing time of the tape (in minutes): "<<endl;
			cin>>p_time;
			sales::get_data();
		}
		void put_data()
		{
			publication2::put_data();
			cout<<"The playing time is: "<<p_time<<" minutes"<<endl<<endl;	
			sales::put_data();
		}	
};

int main()
{
	tape obj1;
	disc obj2;
	book obj3;
	obj1.get_data();
	obj1.put_data();
	obj2.get_data();
	obj2.put_data();
	obj3.get_data();
	obj3.put_data();
}
