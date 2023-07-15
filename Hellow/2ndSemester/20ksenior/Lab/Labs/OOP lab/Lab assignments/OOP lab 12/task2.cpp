#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void write_in_file(string &s)
{
    fstream fp;
    fp.open("task2(1).txt",ios::out);
    if(!fp)
    {
        cout<<"File not created"<<endl;
    }
    else{
        fp<<s;
    }
    fp.close();

}
void copy_from_file()
{
    fstream fp1,fp2;
    fp1.open("task2(1).txt",ios::in);
    fp2.open("task2(2).txt",ios::out);
    if (!fp1 || !fp2)
    {
        cout<<"File not found"<<endl;
        exit(0);
    }
    else
    {
        while (!fp1.eof())
        {
            string str;
            fp1>>str;
            fp2<<str<<" ";
        }
        cout<<"Contents copied"<<endl;
        
    }
    fp1.close();
    fp2.close();
}

int main()
{
    string str;
    cout<<"Enter the string"<<endl;
    getline(cin,str);
    write_in_file(str);
    copy_from_file();
}