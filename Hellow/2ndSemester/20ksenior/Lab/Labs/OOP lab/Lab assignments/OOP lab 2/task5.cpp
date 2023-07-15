#include <iostream>

using namespace std;

float bill (float sal, int time, float old_rate)
{
    float rate=old_rate/60;
    if (sal<=25000)
    {
        if (time <= 30)
        {
            return 0;
        }
        else 
        {
            int new_time;
            new_time=time - 30;
            return (0.4 *(rate) * new_time);
        }
    }
    else
    {
        if (time<=20)
        {
            return 0;
        }
        else
        {
            int new_time;
            new_time=time - 20;
            return (0.7*(rate)*new_time);
        }
    }
}
int main()
{
    int time;
    float sal,total,rate;
    cout<<"Welcome to J&J accounting firm"<<endl<<endl;
    cout<<"Enter your salary, time that you want with the firm (in minutes) "<<endl;
    cin>>sal>>time;
    cout<<"Enter the hourly rate "<<endl;
    cin>>rate;
    total = bill (sal, time, rate);
    cout<<"Your total bill is : $"<<total<<endl;
}