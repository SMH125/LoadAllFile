#include <iostream>
using namespace std;
float residential (int);
float business (int,int);
void display_residential(float,int);
void display_business(float, int);
int  main(void)
{
    float total;
    int account_number,p_channels,b_customers;
    char ccode;
    cout<<"Please enter your account number, customer code "<<endl;
    cin>>account_number>>ccode;
    if (ccode=='r' || ccode=='R')
    {
        cout<<"Enter number of prime channels you want to subscribe"<<endl;
        cin>>p_channels;
        total = residential(p_channels);
        display_residential(total,account_number);
    }
    else if (ccode == 'b' || ccode=='B')
    {
        cout<<"Enter number of business customers, nuber of premium channels "<<endl;
        cin>>b_customers;
        cin>>p_channels;
        total = business(b_customers,p_channels);
        display_business(total,account_number);
    }
    else
    {
        cout<<"Invalid input"<<endl;
    }
    return 0;
    
}

float residential (int channels)
{  
    float temp,total;
    temp=channels*7.50;
    total = 4.50+20.50+temp;
    return total; 
}
float business (int customers, int channels)
{
    float temp,new_customers,total;
    if (customers<=10)
    {
        temp=75*customers;
        float connection_bill;
        connection_bill=channels*50.00;
        total=connection_bill + temp + 15.00;
    }
    else
    {
        new_customers=customers-10;
        float temp2;
        temp=75*10;
        temp2=80*new_customers;
        float channel_bill;
        channel_bill=channels * 50.00;
        total=temp+temp2+channel_bill+15.00;
        return total;

    }
    
}
void display_residential(float total,int acc)
{
    cout<<"Bill processing fee: $4.50"<<endl<<"Basic service fee: $20.50"<<endl<<"Premium channels:$ 7.50 per channel"<<endl;
    cout<<"Your total bill is amounted to: $"<<total<<endl;
    cout<<"Your account number is: "<<acc<<endl;
}
void display_business(float total, int acc)
{   
    cout<<"Bill processing fee: $15.00"<<endl<<"Basic Service fee: $75.00 for first 10 conections and $5.00 for each additional connection"<<endl << "Premium channels: $50.00 per channel for any number of connections"<<endl;
    cout<<"Your total bill is ammounted to: $"<<total<<endl<<"Your account number is: "<<acc<<endl; 
}