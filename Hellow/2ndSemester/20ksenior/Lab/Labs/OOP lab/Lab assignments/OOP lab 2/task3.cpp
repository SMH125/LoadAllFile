#include <iostream>
using namespace std;
float residential(int minutes);
float premium (int day, int night);
int main()
{
    int account_number,minute;
    char scode;
    cout << "Please enter your account number, service code (Residential or Premium)"<<endl;
    cin >>account_number;
    cin>>scode;
    if (scode=='r' || scode=='R')
    {
        cout <<"Please enter number of minutes: "<<endl;
        cin>>minute;
        float total;
        total = residential (minute);
        cout<<"Your account number is : "<<account_number<<endl<<"Your total time of usage is : "<< minute <<endl<<"Your service code is : "<<scode<<endl<<"Your total bill is : $"<<total<<endl;
        cout<<"Thank you for using our services"<<endl;
    }
    else if (scode=='p' || scode=='P')
    {
        int min_day,min_night;
        cout << "Please enter number of minutes used in day time i.e (between 6 AM and 6 PM)"<<endl;
        cin>>min_day;
        cout<<"Please enter number of minutes used in night time i.e (between 6 PM and 6 AM)"<<endl;
        cin>>min_night;
        minute=min_night+min_day;
        float total;
        total = premium (min_day,min_night);
        cout<<"Your account number is : "<<account_number<<endl<<"Your total time of usage is : "<< minute <<endl<<"Your service code is : "<<scode<<endl<<"Your total bill is : $"<<total<<endl;
        cout<<"Thank you for using our services"<<endl;
    }
    else
    {
        cout<<"Invalid input"<<endl;
    }
    
}

float residential(int minutes)
{
    float total;
    if (minutes <= 50)
    {
        total=10.00;
        return (total);
    }
    else
    {
        float temp,new_time;
        new_time= minutes-50;
        temp=new_time * 0.20;
        total= 10 + temp;
        return (total); 
    }
    
    

}
float premium (int day, int night)
{
    float total;
    int temp_day,temp_night,new_day,new_night;
    if (day <= 75)
    {
        temp_day=0;
    }
    else 
    {
        new_day=day-75;
        temp_day=0.10*new_day;
    }
    if (night <= 100)
    {
        temp_night=0;
    }
    else
    {
        new_night=night-100;
        temp_night=0.05*new_night;
    }
    total = temp_day+temp_night;
    return (total);
    
}
