#include <iostream>
using namespace std;

int main()
{
    string name;
    float marks[5];
    float sum=0,avg;
    cout<<"Enter the name of student\n";
    getline(cin,name);
    for (int i = 0; i < 5; i++)
    {
        cout<<"Enter marks for test"<<i+1<<":";
        cin>>marks[i];
    }
    for (int i = 0; i < 5; i++)
    {
        sum+=marks[i];
    }
    avg=sum/5;
    cout<<"Name of student: "<<name<<endl;
    cout<<"Test scores\n";
    for (int i = 0; i < 5 ; i++)
    {
        cout<<marks[i]<<"\t";
    }
    cout<<"Average is: "<<avg;
    
    

    
}