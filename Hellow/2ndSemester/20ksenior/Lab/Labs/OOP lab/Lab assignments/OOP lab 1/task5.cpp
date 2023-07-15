#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct player{
    string name;
    int home_runs,hits;
};
void name(player* ptr);
void home_runs(player* ptr);
void hits(player* ptr);
int main()
{
    player p[10];
    for (int i = 0; i < 10; i++)
    {
        cout<<"Enter details of player:"<<i+1<<endl;
        cout<<"Enter name"<<endl;
        fflush(stdin);
        getline(cin,p[i].name);
        cout<<"Enter home runs and hits:"<<endl;
        cin>>p[i].home_runs>>p[i].hits;
    }
    while (1)
    {
        int choice,n;
        cout<<"Please select which player information you want to change (0-9)"<<endl;
        cin>>choice;
        cout<<"Please select what do you want to change of the player"<<endl<<"1. Name\n2. Home runs\n3.Hits"<<endl;
        cin>>n;
        switch (n)
        {
        case 1:
            name (&p[choice]);
            break;
        case 2:
            home_runs(&p[choice]);
            break;
        case 3:
            hits(&p[choice]);
            break;
        default:
            cout<<"Enter a valid option"<<endl;
            break;
        }
        cout<<"Press 0 if you don't want to change more"<<endl;
        cin>>n;
        if (n==0)
        {
            break;
        }
    }
    system("CLS");
    cout<<"DETAILS ARE:"<<endl;
    for (int i = 0; i < 10; i++)
    {
        cout<<"Name is:"<<p[i].name<<endl<<"Home runs are:"<<p[i].home_runs<<endl<<"Hits are:"<<p[i].hits<<endl;
    }
    
    
    

}

void name(player* ptr)
{
    cout<<"Name is: "<<ptr->name;
    cout<<"\nEnter the new name: ";
    fflush(stdin);
    getline(cin,ptr->name);
}

void home_runs(player* ptr)
{
    int newruns;
    cout<<"Home runs are: "<<ptr->home_runs<<endl;
    cout<<"Enter new home runs\n";
    cin>>newruns;
    ptr->home_runs=newruns;
}
void hits(player* ptr)
{
    int nhits;
    cout<<"Number of hits are: "<<ptr->hits;
    cout<<"\nEnter new number of hits:"<<endl;
    cin>>nhits;
    ptr->hits=nhits;
}