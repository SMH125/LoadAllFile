#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <conio.h>
using namespace std;
int main()
{
    string movie;
    cout<<"Enter name of movie"<<endl;
    fflush(stdin);
    getline(cin,movie);
    int adult,child;
    float adult_price,child_price,percentage,gross;
    cout<<"Enter number of adults,children"<<endl;
    cin>>adult>>child;
    cout<<"Enter price of tickets of adults,children"<<endl;
    cin>>adult_price>>child_price;
    cout<<"Enter percentage you want to donate to charity (without the % sign)"<<endl;
    cin>>percentage;
    int sum=adult+child;
    gross=(adult*adult_price)+(child*child_price);
    float donated,net;
    donated=gross*(percentage/100);
    net=gross-donated;
    cout<<"Movie Name:.........................."<<movie<<endl;
    cout<<"Number of tickets sale:.........................."<<setw(15)<<right<<sum<<endl;
    cout<<"Gross Amount:.........................."<<setw(15)<<right<<"$ "<<gross<<endl;
    cout<<"Percentage of Gross Amount Donated:.........................."<<setw(15)<<right<<percentage<<"%"<<endl;
    cout<<"Amount Donated:.........................."<<setw(15)<<right<<"$ "<<donated<<endl;
    cout<<"Net sale:.........................."<<setw(15)<<right<<"$ "<<net<<endl;


}
