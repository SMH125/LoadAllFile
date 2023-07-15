#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    int count=0;
    int i=0,n;
    cout<<"Enter number of lines you want to enter"<<endl;
    cin>>n;
    fstream fp;
    fp.open("story.txt",ios::out);
    if (!fp)
    {
        cout<<"File not found"<<endl;
        exit(0);
    }
    else
    {
        string str;
        while (i<n)
        {
            fflush(stdin);
            getline(cin,str);
            fp<<str;
            i++;
            if (i!=n)
            {
                fp<<endl;
            }
            
        }

    }
    fp.close();
    fp.open("story.txt",ios::in);
    if(!fp)
    {
        cout<<"File not found"<<endl;
        exit(0);
    }
    else
    {
        while (!fp.eof())
        {
            string str;
            getline(fp,str);
            //cout<<str<<endl;
            if (str[0]!='A')
            {
                count++;
            }
                
        }
        
    }
    cout<<"Number of lines that does not start with 'A' are: "<<count<<endl;
    
}