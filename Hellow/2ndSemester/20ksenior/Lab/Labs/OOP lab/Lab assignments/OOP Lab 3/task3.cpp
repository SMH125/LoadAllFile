#include <iostream>
#include <string>
using namespace std;
class Glass {
    public:
    int liquidlevel;
    Glass()
    {
        liquidlevel = 200;
    }
    void Drink(int mm)
    {
        if (mm<200)
        {
            refill();
        }
    }
    void refill()
    {
        liquidlevel=200;
    }
};

int main()
{
    Glass g1;
    int i=1;
    while (1)
    {
        int amount;
        cout<<"Dear costumer "<<i<<endl<<"Enter the amount of liquid you've consumed (in millimeters)"<<endl;
        cin>>amount;
        g1.Drink(amount);
        char ch;
        cout<<"Enter E or e if you want to exit"<<endl;
        fflush(stdin);
        cin>>ch;
        if (ch=='e'||ch=='E')
        break;
        i++;
    }
    
}