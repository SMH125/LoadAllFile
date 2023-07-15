#include <iostream>
#include <string>
#include <iomanip>
#include <conio.h>
void display();
using namespace std;
struct menu{
    string item;
    double price;
};
int main()
{
   menu m[8];
   m[0].item="Plain egg";
   m[0].price=1.45;
   m[1].item="Bacon and egg";
   m[1].price=2.45;
   m[2].item="Muffin";
   m[2].price=0.99;
   m[3].item="French Toast";
   m[3].price=1.99;
   m[4].item="Fruit basket";
   m[4].price=2.49;
   m[5].item="Cereal";
   m[5].price=0.69;
   m[6].item="Coffee";
   m[6].price=0.50;
   m[7].item="Tea";
   m[7].price=0.75;
   int n,choice;
    display();
    cout<<"Enter the number of items you want to order"<<endl;
    cin>>n;
    double arr[n],sum=0;
    int arr2[8]={0};

    for (int i = 0; i < n; i++)
    {
        cout<<"Please select your item number "<<i+1<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
            arr[i]=1.45;
            arr2[i]=1;
            break;
        case 2:
            arr[i]=2.45;
            arr2[i]=1;
            break;
        case 3:
            arr[i]=0.99;
            arr2[i]=1;
            break;
        case 4:
            arr[i]=1.99;
            arr2[i]=1;
            break;
        case 5:
            arr[i]=2.49;
            arr2[i]=1;
            break;
        case 6:
            arr[i]=0.69;
            arr2[i]=1;
            break;
        case 7:
            arr[i]=0.50;
            arr2[i]=1;
            break;
        case 8:
            arr[i]=0.75;
            arr2[i]=1;
            break;
        
        default:
            cout<<"Please enter a valid choice";
            i--;
            break;
        }
        //system("clear");
        //display();
    }
    system("CLS");
    cout<<"WELCOME TO JOHNSON'S RESTAURANT"<<endl<<"=============================="<<endl<<"You Ordered:"<<endl;
    for (int i = 0; i <8 ; i++)
    {
        if (arr2[i]==1)
        {
            cout<<m[i].item<<" $"<<m[i].price<<endl;
        }
       //sum+=arr[i]; 
    }
    for (int i = 0; i < n; i++)
    {
        sum+=arr[i];
    }
    
    double tax,net;
    tax=sum*0.05;
    net=sum+tax;
    cout<<"Tax: $"<<fixed<<setprecision(2)<<tax<<endl;
    cout<<"Amount Due: $"<<fixed<<setprecision(2)<<net<<endl;
    
   
   
}

void display()
{
    cout<<"1. Plain Egg"<<setw(15)<< right <<"$1.45"<<endl;
    cout<<"2. Bacon and Egg"<<setw(15)<< right <<"$2.45"<<endl;
    cout<<"3. Muffin"<<setw(15)<< right <<"$1.99"<<endl;
    cout<<"4. French Toast"<<setw(15)<< right <<"$2.49"<<endl;
    cout<<"5. Fruit Basket"<<setw(15)<< right <<"$2.49"<<endl;
    cout<<"6. Cereal"<<setw(15)<< right <<"$0.69"<<endl;
    cout<<"7. Coffee"<<setw(15)<< right <<"$0.50"<<endl;
    cout<<"8. Tea"<<setw(15)<< right <<"$0.75"<<endl;
}