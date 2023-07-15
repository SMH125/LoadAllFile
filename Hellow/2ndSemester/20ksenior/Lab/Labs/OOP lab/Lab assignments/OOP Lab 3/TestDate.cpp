#include <iostream>
#include <string>

using namespace std;
class date {
    int  month,day,year;
    public:
    void setdata(int m,int d, int y)
    {
        month=m;day=d;year=y;
    }
    int return_day()
    {return day;}
    int return_month()
    {return month;}
    int return_year()
    {return year;}
};

int main()
{
    int m,d,y;
    date d1;
    d1.setdata(02,25,2021);
    m = d1.return_month();
    d = d1.return_day();
    y = d1.return_year();
    cout<<d<<'/'<<m<<'/'<<y<<endl;



}