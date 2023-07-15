#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

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

class book : public publication
{
	int page_count;
	public:
		void get_data()
		{
			publication::get_data();
			cout<<"Enter the number of pages: "<<endl;
			cin>>page_count;	
		}
		void put_data()
		{
			publication::put_data();
			cout<<"The number of pages are: "<<page_count<<" pages"<<endl<<endl;	
		}	
};

class tape : public publication
{
	float p_time;
	public:
		void get_data()
		{
			publication::get_data();
			cout<<"Enter the playing time of the tape (in minutes): "<<endl;
			cin>>p_time;
		}
		void put_data()
		{
			publication::put_data();
			cout<<"The playing time is: "<<p_time<<" minutes"<<endl<<endl;	
		}	
};

int main()
{
	tape t;
	t.get_data();
	t.put_data();
	book b;
	b.get_data();
	b.put_data();
	
}
