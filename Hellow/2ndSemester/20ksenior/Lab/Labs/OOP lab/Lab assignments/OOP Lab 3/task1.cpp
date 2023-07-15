#include <iostream>
#include <string>
using namespace std;
class User 
{
    public:
        int age;
        string  name;
        void setdata(int a, string n)
        {
            name=n;
            age=a;
        }
        void show()
        {
            cout <<"My name is "<<name<<" and I'm "<<age<<" years old"<<endl;
        }
};

int main()
{
    User u1;
    u1.setdata(24,"Teo");
    u1.show();
}