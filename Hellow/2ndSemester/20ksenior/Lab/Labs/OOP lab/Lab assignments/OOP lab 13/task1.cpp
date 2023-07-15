#include <iostream>
#include <string>

using namespace std;
template <class X>

void swap_numbers(X *n1, X *n2)
{
    X temp;
    temp = *n1;
    *n1 = *n2;
    *n2  = temp;
}

int main()
{
    int n1,n2;
    cout<<"Enter two integer values"<<endl;
    cin>>n1>>n2;
    swap_numbers(&n1,&n2);
    cout<<"After swapping: "<<endl<<n1<<"  "<<n2<<endl;
    char c1,c2;
    cout<<"Enter two character values"<<endl;
    cin>>c1>>c2;
    swap_numbers(&c1,&c2);
    cout<<"After swapping: "<<endl<<c1<<"  "<<c2<<endl;
    float f1,f2;
    cout<<"Enter two float values"<<endl;
    cin>>f1>>f2;
    swap_numbers(&f1,&f2);
    cout<<"After swapping: "<<endl<<f1<<"  "<<f2<<endl;
}