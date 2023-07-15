#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
void reverse_array(int* arr,int n)
{
    
    int rev_array[n];
    for (int i = 0,j = n-1; i < n; i++,j--)
    {
        rev_array[i] = (arr[j]);
    }
    for (int i = 0; i < n; i++)
    {
        (arr[i]) = rev_array[i];
    }
    
    
}
int main()
{
    int n;
    cout<<"Please enter the number of elements you want to enter in your array"<<endl;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"The elements in array are: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<"\t";
    }
    reverse_array(arr,n);
    cout<<endl<<"The reverse elements in array are:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<"\t";
    }
    
    
    
}