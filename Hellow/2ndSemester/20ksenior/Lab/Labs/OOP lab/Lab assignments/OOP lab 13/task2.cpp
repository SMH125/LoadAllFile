#include <iostream>
#include <string>
using namespace std;
template <class T>

class array
{
    T *arr;
    int pos,no_of_elements;
    public:
        array(int n)
        {
            arr = new T[n];
            input(n);
            no_of_elements = n;
        }
        void input(int n)
        {
            cout<<"Enter values"<<endl;
            for (int i = 0; i < (n); i++)
            {
                cin>>arr[i];
            }
            
        }
        bool search(T arg)
        {
            for (int i = 0; i < no_of_elements; i++)
            {
                if (arr[i]==arg)
                {
                    pos = i;
                    return (true);
                }    
            }
            return(false);
            
        }
        int get_pos(){return (pos+1);}
};

int main()
{
    //array(5);
    array <int>obj(5);
    cout<<"Enter the value you wish to search"<<endl;
    int n1;
    cin>>n1;
    if(obj.search(n1))
    {
        cout<<"The element you searched is: "<<n1<<" and the position is: "<<obj.get_pos()<<endl;
    }
    else
    {
        cout<<"Element not found"<<endl;
    }
    
}