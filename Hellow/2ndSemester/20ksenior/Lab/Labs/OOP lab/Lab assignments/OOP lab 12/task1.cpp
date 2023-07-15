#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void write_in_file()
{
    string str;
    fstream fp;
    fp.open("task1.txt",ios::out);
    if(!fp)
    {
        cout<<"File not created"<<endl;
        exit(0);
    }
    else
    {
        cout<<"Enter the string"<<endl;
        getline(cin,str);
        fp<<str<<" "<<str.length();

    }

}
void read_from_file()
{
    fstream fp;
    fp.open("task1.txt",ios::in);
    if(!fp)
    {
        cout<<"File not found"<<endl;
        exit(0);
    }
    else
    {
        while(!fp.eof())
        {
            string str;
            fp>>str;
            cout<<str<<" ";
        }
        
    }
}
int main()
{
    write_in_file();
    read_from_file();
}