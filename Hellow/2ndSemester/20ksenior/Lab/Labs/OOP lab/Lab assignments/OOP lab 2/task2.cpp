#include <iostream>
#include <string>
//#include <ctype>
using namespace std;

int showchoices();
float feetandinchestometerandcent(float* ptr,float inches);
float metersandcenttofeetandinches(float* ptr, float cent);

int main()
{
    int choice; 
    char exit;
    float feet,inch,meters,cm;    //1 is for feet to meter and 2 is for meter to feet
    while (1)
    {
        choice = showchoices();
        if (choice==1)
        {
            cout<<"Enter the value in feet and inches";
            cin>>feet>>inch;
            if (feet < 0 || inch < 0)
            {
                cout<<"The entered input is wrong"<<endl;
                continue;
            }
            else
            {
                cm= feetandinchestometerandcent(&feet,inch);
                cout<<"The converted value is "<<feet<<" meters and "<<cm<<" centimeters "<<endl;
            }
            
        }
        else if (choice==2) 
        {
            cout<<"Enter the value in meters and centimeters"<<endl;
            cin>>meters>>cm;
            if (meters < 0 || cm < 0)
            {
                cout<<"The entered input is wrong"<<endl;
            }
            else
            {
                inch = metersandcenttofeetandinches(&meters,cm);
                cout<<"The converted value in feet is "<<meters<<" ft and "<<inch<<" inches "<<endl;
            }
            
        }
        else if (choice == 0)
        {
            break;
        }
        else 
        {
            cout<<"Invlaid choice"<<endl;
        }
    }
    
}

int showchoices()
{
    int choice;
    cout << "Press 1 to use the program to convert feet and inches to meters and centimenetrs"<<endl<<"Press 2 to use the program to convert meters and centimeters to feet and inches"<<endl<<"Press 0 to exit the program"<<endl;
    cin>>choice;
    return choice;
}

float feetandinchestometerandcent(float *ptr,float inches)
{
    float cm,meters;
    cm=inches*2.54;
    //return cm;
    meters=*ptr*0.3048;
    *ptr=meters;
    return cm;
}

float  metersandcenttofeetandinches(float* ptr, float cent)
{
    float feet,inches;
    inches= 0.393701 * cent;
    feet = (*ptr) *3.28084;
    *ptr=feet;
    return inches;
    
}
