//                                    INCLUDING LIBRARIES                                                         //
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <conio.h>

using namespace std;
// Global function to check if the string is a complete integer or not
bool is_int(string s)
{
    for (int i=0 ;i<s.length();i++)
    {
        if(isdigit(s[i])==false)
        {
            return(false);
        }
        
    }
    return(true);
}
// Creating class for OOP approach
class File_encryption
{
    string s;       // attribute string to read and write data from/into file
    public:
    void input()        //Function to take input
    {
        cout<<"Enter the text"<<endl;
        getline(cin,s);
    }
    void write_in_file()        //Function to write conntents in file "input.txt"
    {
        ofstream fp;
        fp.open("input.txt",ios::out);      //opening file in write mode
        if(!fp)
        {
            cout<<"File not created"<<endl;
            exit(0);
        }
        else{
        fp << s;
        }
        fp.close();     //closing file
    }
    void encrypt_file()
    {
        char alphabets[26],ch='A';      //declaring and initializing an array of Capital English Alphabets (A-Z)
        for (int i = 0; i < 26; i++)
        {
            alphabets[i]=ch;
            ch++;
        }
        int arr2[26];                   //declaring and initializing an integer array (1-26) in correspondence with alphabets array
        for (int i = 0; i < 26; i++)
        {
            arr2[i] = i+1;
        }
        fflush(stdin);
        string s;
        ofstream fp1;
        ifstream fp2;
        fp1.open("k200177.txt",ios::out);       //opening file (k20017.txt) in writing mode
        fp2.open("input.txt",ios::in);          //opening file in (input.txt) reading mode
        if (!fp1 || !fp2)
        {
            cout<<"File not found"<<endl;
            exit(0);
        }
        else
        {
            while(!fp2.eof())
            {
                fp2>>s;
                if(is_int(s))           //checking if the string read is a complete integer or not
                {
                    stringstream ss;            //using stringstream library to change string into integer
                    int n;
                    ss << s;
                    ss>>n;
                    if (n<1 || n>26)        // Applying checks according to the given prompt
                    {
                    fp1<<'Z';
                    }
                    else
                    {
                        for (int j = 0; j < 26; j++)
                        {
                            if(n==arr2[j])
                            {
                                fp1<<alphabets[j];          //writing in file the correspondent element from alphabets array
                            }
                        }
                    }
                    
                    
                }
                else
                {
                    int result = 0,check=0;         //If the string is not a complete integer then checking if it contains any number
                    for (int i = 0; i < s.length(); i++)
                    {
                        if(isdigit(s[i])==true)
                        {
                            check=1;            //to check if the "if" block has been called or not
                            result = result*10 + (s[i]-48);     //to enter the digits of string into the integer with the help of ascii code
                        }
                    }
                    if(check==1)
                    {
                        if(result<1 || result >26)      //applying check according to prompt
                        {
                            fp1<<'Z';
                        }
                        else 
                        {
                            for (int j = 0; j < 26; j++)
                            {
                                if(result==arr2[j])
                                {
                                    fp1<<alphabets[j];  //getting the alphabet from the correspondent integer array
                                }
                            }
                            
                        }
                    }
                    
                }
             }
        }
        fp1.close();    //closing files
        fp2.close();
    }
    void read_from_file()
    {
        ifstream fp;
        fp.open("k200177.txt",ios::in);     //opening file in read mode
        if (!fp)
        {
            cout<<"File not found"<<endl;
            exit(0);
        }
        else{
            while (!fp.eof())
            {
                fp>>s;      //saving the string from file into the local attribute of the class
            }
            
        }
        fp.close();
    }
    void show()
    {

        cout<<"The content in file is:"<<endl<<s<<endl;     //displaying the contents saved in string
    }
};





int main()
{
    File_encryption obj;
    obj.input();
    obj.write_in_file();
    obj.encrypt_file();
    obj.read_from_file();
    obj.show();
}

