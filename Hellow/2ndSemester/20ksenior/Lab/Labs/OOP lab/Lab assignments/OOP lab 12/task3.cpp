#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class person
{
    string name;
    int age;
    public:
    //parametrized constructor
    person(string n, int a)
    {
        name = n;
        age = a;
    }
    person(){}
    void show()
    {
        cout<<"Name is "<<name<<endl;
        cout<<"Age is "<<age<<endl;
    }
};

int main()
{
    person person1("Ammar",19);
    fstream fp;
    fp.open("person.dat",ios::out | ios::binary);
    if (!fp)
    {
        cout<<"File not created"<<endl;
    }
    else
    {
        fp.write((char*)&person1,sizeof(person1));
    }
    person person2;
    fp.close();
    fp.open("person.dat",ios::in | ios::binary);
    if(!fp)
    {
        cout<<"File not found"<<endl;
        exit(0);
    }
    else
    {
        fp.read((char*)&person2,sizeof(person2));
    }
    person2.show();
    fp.close();
}