#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    int hours,minutes,seconds,time;
    cout<<"Enter the time (in seconds)"<<endl;
    cin>>time;
    hours = time/3600;
    time = time-(hours*3600);
    minutes = time/60;
    time = time-(minutes*60);
    seconds = time;
    cout<<"The time is: "<<hours<<"hrs: "<<minutes<<"min: "<<seconds<<"sec."<<endl;
}
