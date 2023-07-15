#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class Employee 
{
    string f_name,l_name;
    double salary;
    public:
        void setdata(string name1, string name2,double sal)
        {
            f_name=name1;
            l_name=name2;
            if (sal<0)
            {
                salary = 0.0;
            }
            else
            {
                salary = sal;
            }
        }
        void show()
        {
            cout<<"First Name: "<<f_name<<endl;
            cout<<"Last Name: "<<l_name<<endl;
            cout<<"Monthly Salary: $"<<salary;
        }
        double return_salary()
        {return salary;}

};

int main()
{
    Employee e1,e2;
    //string firstname,lastname;
    double sal1,sal2;
    e1.setdata("Ammar","Siddiqui",-12345.998);
    e2.setdata("Ali","Uddin",4567.990);
    e1.show();
    //e2.show();
    sal1=e1.return_salary();
    sal2=e2.return_salary();
    cout<<endl<<"Yearly Salary of the employe is $"<<sal1*12;
    cout<<endl<<"After 10% increment the new salary of the employee is: $"<<(sal1*12)  + (0.1*sal1)<<endl<<endl;
    e2.show();
    cout<<endl<<"Yearly Salary of the employe is $"<<sal2*12;
    cout<<endl<<"After 10% increment the new salary of th employee is: $"<<(sal2*12)  + (0.1*sal2)<<endl;
}
