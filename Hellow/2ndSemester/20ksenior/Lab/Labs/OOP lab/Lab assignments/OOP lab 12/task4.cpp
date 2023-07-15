#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class participant
{
    string name;
    int id,score;
    public:
        void input()
        {
            fflush(stdin);
            cout<<"Enter name of the player "<<endl;
            getline(cin,name);
            cout<<"Enter id "<<endl;
            cin>>id;
            cout<<"Enter score"<<endl;
            cin>>score;
           
        }
        int get_id(){return id;}
        int get_score(){return score;}
        void show()
        {
            cout<<"Name is "<<name<<endl<<"id is: "<<id<<endl<<"score is: "<<score<<endl;
        }
        
};
void write_in_file(participant &p1, participant &p2)
{
      fstream fp;
        fp.open("participant.dat",ios::out | ios::binary);
        if(!fp)
        {
            cout<<"File not found"<<endl;
            exit(0);
        }
        else
        {
            fp.write((char*)&p1,sizeof(p1));
            fp.write((char*)&p2,sizeof(p2));
        }
}
void read_from_file()
{
    fstream fp;
    participant p1,p2;
    fp.open("participant.dat",ios::in | ios::binary);
    if (!fp)
    {
        cout<<"File not found"<<endl;
        exit(0);
    }
    else
    {
        fp.read((char*)&p1,sizeof(p1));
        fp.read((char*)&p2,sizeof(p2));
    }
    //cout<<"Reading from file"<<endl;
    //p1.show();
    //p2.show();
    int id,max=0;
    cout<<"Enter ID"<<endl;
    cin>>id;
    if(id==p1.get_id())
    {
        p1.show();
    }
    else if(id==p2.get_id())
    {
        p2.show();
    }
    else
    {
        cout<<"The inputted id does not match any participant"<<endl;
    }
    if(max<p1.get_score())
    {
        max = p1.get_score();
    }
    if (max<p2.get_score())
    {
        max = p2.get_score();
    }
    cout<<"Maximum score is: "<<max<<endl;
}
int main()
{
    participant p1,p2;
    p1.input();
    p2.input();
    write_in_file(p1,p2);
    read_from_file();
}