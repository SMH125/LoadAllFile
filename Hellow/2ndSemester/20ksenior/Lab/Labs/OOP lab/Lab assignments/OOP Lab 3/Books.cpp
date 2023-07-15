#include <iostream>
#include <string>
using namespace std;

class Book
{
	string 	book_name,author,publisher;
	int isbn;
	public:
		//setter functions
		void setData(string b_name, string a, string p,int isb)
		{
			book_name = b_name;
			author =  a;
			publisher = p;
			isbn = isb;
		}
		
		int return_isbn()
		{return isbn;}
		void show()
		{
			cout << "Name of book is: "<<book_name<<endl;
			cout << "Author is: "<<author<<endl;
			cout << "Publisher is: "<<publisher<<endl;
			cout << "ISBN number is: "<<isbn<<endl<<endl<<endl;
		}
};

int main()
{
	string b_name,author,publisher;
	int isbn,match_isbn;
	int n;
	cout << "Enter number of books"<<endl;
	cin>>n;
	Book Book[n];
	for (int i=0; i<n ; i++)
	{
		cout<<"Enter book name, author, publisher and isbn number for book "<<i+1<<endl;
		//cin>>b_name>>author>>publisher>>isbn;
		fflush(stdin);
		getline(cin,b_name);
		fflush(stdin);
		getline(cin,author);
		fflush(stdin);
		getline(cin,publisher);
		fflush(stdin);
		cin>>isbn;
		Book[i].setData(b_name,author,publisher,isbn);
	}
	system("CLS");
	cout << "Enter the isbn number of the book you want to search"<<endl;
	cin>>match_isbn;
	for (int i=0;i<n;i++)
	{
		isbn = Book[i].return_isbn();
		if (isbn == match_isbn)
		{
			cout <<"Details of book are as follows: "<<endl;
			Book[i].show();
		}
	}
}
