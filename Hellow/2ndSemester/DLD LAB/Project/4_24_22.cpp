#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string.h>
#include <conio.h>
#include <unistd.h>
#include <regex>
#include <cstdio>
#include <stdio.h>
using namespace std;
// The class is decleared to uses each other in each orther
class User; // user is the base class of all
class Customer;
class Driver;
//class Car; // Drived class of Car
class Admin;
// Calling function from user menu
int ccustomer();
int ddriver();
//int ccar();
int aadmin();
// Main Calling Function
int manu();
void usermanue();
int Selection();
// Get name Logic
string getname(void)
{
    string n;
    cout << "Name       : ";
    getline(cin, n);
    // cout<<n.length();
    int ns = n.length();
    int i = 0;
    while (!(ns >= 3))
    {
        cout << "\nName must be of 3 character";
        cin.ignore();
        getline(cin, n);
        ns = n.length();
    }
    // n=nam;
    return n;
}
// Get password logic
string getpass(void)
{
    int j = 0, k = 1; // j is 1 then loop of password will end
    string p;
    char pass[50];
    int i = 0;
    char character;
    // cin.ignore();
    while (!(j == 1))
    {
        cout << "\nPassword     : ";
        while (1)
        {

            character = getch();
            if (character == '\r')
            {
                pass[i] = '\0';
                break;
            }
            else if (character == '\b')
            {
                if (i > 0)
                {
                    cout << "\b \b";
                    i--;
                }
            }
            else
            {
                pass[i] = character;
                cout << "*";
                i++;
            }
        }
        string password = pass;
        int length = password.length();
        bool lowercase = false, uppercase = false, digit = false, specialcharacter = false;
        for (int i = 0; i < length; i++)
        {
            if (islower(password[i]))
            {
                lowercase = true;
            };
            if (isupper(password[i]))
            {
                uppercase = true;
            }
            if (isdigit(password[i]))
            {
                digit = true;
            }
        }
        size_t specialchar = password.find_first_of("!@#$%&");
        if (specialchar != string::npos)
            specialcharacter = true;
        if (lowercase == 1 && uppercase == 1 && digit == 1 && specialcharacter == 1)
        {
            j = 1;
            p = pass;
        }
        else
        {
            cout << "Your password must be have at least: " << endl;
            cout << "8 characters long" << endl;
            cout << "1 uppercase & 1 lowercase character" << endl;
            cout << "1 number" << endl;
        }
    }
    return p;
}
// Get Email logic
string getemail()
{
    char em[50];
    string Em;
    int j = 0;
    while (!(j == 1))
    {
        cout << "\nEmail        : ";
        cin.getline(em, 49);
        const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
        if (regex_match(em, pattern))
        {
            j++;
            break;
        }
        else
        {
            cout << "\nEmail should contain @ and .";
            // getch();
        }
    }
    Em = em;
    return Em;
}
// Get Gender logic
string getgender()
{
    char Gen[10];
    string g;
    int i = 0;
    string gen;
    while ((i != 1))
    {
        // cin.ignore();
        cout << "\nGender     : ";
        cin.getline(Gen, 9);
        gen = Gen;
        if (gen == "Female" || gen == "F" || gen == "f")
        {
            gen = "Female";
            i = 1;
        }
        else if (gen == "Male" || gen == "M" || gen == "m")
        {
            gen = "Male";
            i = 1;
        }
        else if (gen == "Others")
        {
            i = 1;
        }
        else
        {
            cout << "Choose between Man, Women or Others " << endl;
        }
    }
    g = gen;
    return g;
}
// Get Phone Logic
string getphon()
{
    string phons;
    int j = 0;
    while ((j != 1))
    {
        cout << "\nPhone        : ";
        getline(cin, phons);
        int length = phons.length();
        if (length == 11)
        {
            for (int i = 0; i < 2; i++)
            {

                if (phons[i] == '0' && phons[i + 1] == '3')
                {
                    j = 1;
                    break;
                }
            }
        }
        else
        {
            cout << "\nNumber should contain 03 and have length of 11";
        }
    }
    // pp=phons;
    return phons;
}
// Genrated the user name autmatically using email before @
string getusername(string e)
{
    int i;
    char username[20];
    string un;
    for (i = 0; i <= e.length(); i++)
    {
        if (e[i] == '@')
        {
            username[i] = '\0';
            break;
        }
        else
        {
            username[i] = e[i];
        }
    }
    return username;
}
// Get Address Function
string getaddress()
{
    char add[200];
    string adr;
    cout << "\nAddress      : ";
    cin.getline(add, 199);
    adr = add;
    return adr;
}
// Base Class
class User
{
protected:
    int userid; // gerrate by the program
    char Name[50];
    char Email[50];
    char Gender[10];
    char phonenumber[20];
    char Address[200];
    char password[50];
    char username[20]; // genrate by the program
public:
     int usercount;
    User(string A, string B, string C, string D, string E, string F, string G, int a);
    string SetName();
    int SetUserId();
    string SetEmail();
    string SetUserName();
    string Setgender();
    string Setphonenumber();
    string Setpassword();
    string Setadddress();
    // Here f is the selection varble for opening and closing of file
    virtual void AddUser() = 0;
    virtual void showUser() = 0;
    virtual void showAllUserData() = 0;
    virtual void ViewAllUser() = 0;
    virtual int SaveUser() = 0;
    virtual void deleteUser(char* t) = 0;
    virtual void updateUser(char* t) = 0;
    virtual void searchUser(char* t) = 0;
};
// Calling Member Data member calling Function and Conversion from string to Character Array
string User::SetName()
{ // Conversion from string to char array
    string s = getname();
    char n[s.size() + 1];
    // string myWord = "myWord";
    // char myArray[myWord.size()+1];//as 1 char space for null is also required
    // strcpy(myArray, myWord.c_str());

    strcpy(n, s.c_str());
    strcpy(Name, n);
    return Name;
}
int User::SetUserId()
{
    srand(time(NULL));
    userid = 1000 + (rand() % 9001);
    return userid;
}
string User::SetEmail()
{
    string em = getemail();
    char e[em.size() + 1];
    strcpy(e, em.c_str());
    strcpy(Email, e);
    return Email;
}
string User::SetUserName()
{
    string une = getusername(Email);
    char e[une.size() + 1];
    strcpy(e, une.c_str());
    strcpy(username, e);
    /// string getusername(string em);
    return username;
}
string User::Setgender()
{
    string sg = getgender();
    char g[sg.size() + 1];
    strcpy(g, sg.c_str());
    strcpy(Gender, g);
    return Gender;
}
string User::Setphonenumber()
{
    string pn = getphon();
    char ph[pn.size() + 1];
    strcpy(ph, pn.c_str());
    strcpy(phonenumber, ph);
    return phonenumber;
}
string User::Setpassword()
{
    string pa = getpass();
    char p[pa.size() + 1];
    strcpy(p, pa.c_str());
    strcpy(password, p);
    return password;
}
string User::Setadddress()
{
    string a = getaddress();
    char ad[a.size() + 1];
    strcpy(ad, a.c_str());
    strcpy(Address, ad);
    return Address;
}
//int User::usercount = 0;
// User Constructor
User::User(string A, string B, string C, string D, string E, string F, string G, int a)
{
    strcpy(Name, "NoName");
    strcpy(Email, "None");
    strcpy(Gender, "None");
    strcpy(phonenumber, "00000000000");
    strcpy(Address, "None");
    strcpy(password, "00000");
    strcpy(username, "NOUserName");
  //  userid = 00;
    usercount++;
}
class Customer : public User
{
private:
    /* data */
public:
    Customer();
    void AddUser();
    void showUser();
    void showAllUserData();
    void ViewAllUser();
    int SaveUser();
    void deleteUser(char* t);
    void updateUser(char* t);
    void searchUser(char* t);
    //  Customer();
};
// Additional Function of User
// Customer Constructor
Customer::Customer() : User("NoName", "None", "None", "00000000000", "None", "00000", "NOUserName", 00) {}
// File store this detail before storing data by taking inputs from the users
void Customer:: AddUser()
 {
    cout << "Enter your Details: \n";
    SetUserId();
    SetName();
    Setadddress();
    Setphonenumber();
    Setgender();
    SetEmail();
    SetUserName();
    Setpassword();
    showUser();
}
void Customer::showUser(){
        cout << "\nName         : " << Name << endl;
        cout << "Email        : " << Email << endl;
        cout << "Gender       : " << Gender << endl;
        cout << "PhoneNumber  : " << phonenumber << endl;
        cout << "Address      : " << Address << endl;
        cout << "Password     : " << password << endl;
        cout << "User Id      : " << userid << endl;
        cout << "User Name    : " << username << endl;
}
void Customer::showAllUserData(){
    cout<<userid<<" "<<username<<" "<<Name<<" "<<Email<<" "<<Gender<<" "<<phonenumber<<" "<<Address<<" "<<password;
} 
int Customer::SaveUser(){
    ofstream fout;
    if (Name=="NoName" && username=="NOUserName")
    {
        cout<<"User data is not intialized: ";
        return(0);
    }
    else
    {
        ofstream fout;
        fout.open("SUser.dat",ios::app|ios::binary);
        fout.write((char*)this,sizeof(*this));
        fout.close();
        return(1);
    }
    
}
void Customer::ViewAllUser(){
    ifstream fin;
    fin.open("SUser.dat",ios::in|ios::binary);
    if (!fin)
    {
        cout<<"\nFile Not Found";
    }
    else
    {
        fin.read((char*)this,sizeof(*this));
        while (!fin.eof())
        {
            cout << "\n";
            showAllUserData();
            fin.read((char *)this, sizeof(*this));
        }
        fin.close();
        
    }
    
}
void Customer::deleteUser(char *t){
    ifstream fin;  // read file
    ofstream fout; // write file
    fin.open("SUser.dat", ios::in|ios::binary);
    if (!fin)
    {
        cout << "\nFile Not found";
    }
    else
    {
        fout.open("tempfile.dat", ios::out|ios::binary);
        fin.read((char *)this, sizeof(*this));
        while (!fin.eof())
        {
            if (strcmp(password, t))
            {
                fout.write((char *)this, sizeof(*this));
            }
            fin.read((char *)this, sizeof(*this));
        }
        fin.close();
        fout.close();
        remove("SUser.dat");
        rename("tempfile.dat", "SUser.dat");
    }

}
void Customer::updateUser(char *t)
{
    fstream file;
    file.open("SUser.dat", ios::ate | ios::in | ios::out|ios::binary);
    file.seekg(0); // read poniter value zero
    file.read((char *)this, sizeof(*this));
    while (!file.eof())
    {
        if (!strcmp(password, t)) // if data matched this if loop start
        {
            AddUser();
            int t=file.tellp();int s=sizeof(*this);file.seekp(t-s);
            file.write((char *)this, sizeof(*this));
        }
        file.read((char *)this, sizeof(*this));
    }
    file.close();
}
void Customer::searchUser(char *t)
{
    int counter = 0;
    ifstream fin;
    fin.open("SUser.dat", ios::in|ios::binary);
    if (!fin)
    {
        cout << "\nFile not found ";
    }
    else
    {
        fin.read((char *)this, sizeof(*this));
        while (!fin.eof())
        {
            if (!strcmp(password, t))
            {
                showUser();
                counter++;
            }
            fin.read((char *)this, sizeof(*this));
        }
        if (counter == 0)
        {
            cout << "\nRecord not found: ";
        }
        fin.close();
    }
}// //Driver Class
class Driver : public User
{
private:
    /* data */
public:
    Driver(/* args */);
    void AddUser();
    void showUser();
    void showAllUserData();
    void ViewAllUser();
    int SaveUser();
    void deleteUser(char *t);
    void updateUser(char *t);
    void searchUser(char *t);
    //~Driver();
};
// Additional Function of User
// Driver Constructor
Driver::Driver() : User("NoName", "None", "None", "00000000000", "None", "00000", "NOUserName", 00) {}
// File store this detail before storing data by taking inputs from the users
void Driver:: AddUser()
 {
    cout << "Enter your Details: \n";
    SetUserId();
    SetName();
    Setadddress();
    Setphonenumber();
    Setgender();
    SetEmail();
    SetUserName();
    Setpassword();
    showUser();
}
void Driver::showUser(){
        cout << "\nName         : " << Name << endl;
        cout << "Email        : " << Email << endl;
        cout << "Gender       : " << Gender << endl;
        cout << "PhoneNumber  : " << phonenumber << endl;
        cout << "Address      : " << Address << endl;
        cout << "Password     : " << password << endl;
        cout << "User Id      : " << userid << endl;
        cout << "User Name    : " << username << endl;
}
void Driver::showAllUserData(){
    cout<<userid<<" "<<username<<" "<<Name<<" "<<Email<<" "<<Gender<<" "<<phonenumber<<" "<<Address<<" "<<password;
} 
int Driver::SaveUser(){
    ofstream fout;
    if (Name=="NoName" && username=="NOUserName")
    {
        cout<<"User data is not intialized: ";
        return(0);
    }
    else
    {
        ofstream fout;
        fout.open("DUser.dat",ios::app|ios::binary);
        fout.write((char*)this,sizeof(*this));
        fout.close();
        return(1);
    }
    
}
void Driver::ViewAllUser(){
    ifstream fin;
    fin.open("DUser.dat",ios::in|ios::binary);
    if (!fin)
    {
        cout<<"\nFile Not Found";
    }
    else
    {
        fin.read((char*)this,sizeof(*this));
        while (!fin.eof())
        {
            cout << "\n";
            showAllUserData();
            fin.read((char *)this, sizeof(*this));
        }
        fin.close();
        
    }
    
}
void Driver::deleteUser(char *t){
    ifstream fin;  // read file
    ofstream fout; // write file
    fin.open("DUser.dat", ios::in|ios::binary);
    if (!fin)
    {
        cout << "\nFile Not found";
    }
    else
    {
        fout.open("tempfile.dat", ios::out|ios::binary);
        fin.read((char *)this, sizeof(*this));
        while (!fin.eof())
        {
            if (strcmp(password, t))
            {
                fout.write((char *)this, sizeof(*this));
            }
            fin.read((char *)this, sizeof(*this));
        }
        fin.close();
        fout.close();
        remove("DUser.dat");
        rename("tempfile.dat", "DUser.dat");
    }

}
void Driver::updateUser(char *t)
{
    fstream file;
    file.open("DUser.dat", ios::ate | ios::in | ios::out|ios::binary);
    file.seekg(0); // read poniter value zero
    file.read((char *)this, sizeof(*this));
    while (!file.eof())
    {
        if (!strcmp(password, t)) // if data matched this if loop start
        {
            AddUser();
            int t=file.tellp();int s=sizeof(*this);file.seekp(t-s);
            file.write((char *)this, sizeof(*this));
        }
        file.read((char *)this, sizeof(*this));
    }
    file.close();
}
void Driver::searchUser(char *t)
{
    int counter = 0;
    ifstream fin;
    fin.open("DUser.dat", ios::in|ios::bin);
    if (!fin)
    {
        cout << "\nFile not found ";
    }
    else
    {
        fin.read((char *)this, sizeof(*this));
        while (!fin.eof())
        {
            if (!strcmp(password, t))
            {
                showUser();
                counter++;
            }
            fin.read((char *)this, sizeof(*this));
        }
        if (counter == 0)
        {
            cout << "\nRecord not found: ";
        }
        fin.close();
    }
}
class Admin : public User
{
string name;
	string email;
	int age;
	char gender;
	string ID;
	string Password;
	string designation;
	
	public:
		void menu(){
			int choice;
			while(choice!=8){
			system("cls");
			cout<<"1. Search User Info"<<endl<<"2. Search Car info"<<endl<<"3. Search Driver info"<<endl;
			cout<<"4. Delete User info"<<endl<<"5. Delete Car info"<<endl<<"6. Delete Driver info"<<endl;
			cout<<"7. View your information: "<<endl<<"8. Logout"<<endl;
			cin>>choice;
			switch (choice){
				case 1:
					system("cls");
					cout<<"Press 1 to display details for all users"<<endl<<"Press 2 to search with user ID"<<endl;
					cout<<"Press 3 to exit"<<endl;
					cin>>choice;
					if(choice=1){
						
					}
						//Display all users;
					else if (choice==2){
						
					}
						//Search User using ID
					else if (choice==3){
						//exit
					}
					else{
						cout<<"Choice not recognised....."<<endl;
						choice = 0;
						getch();
					}
					break;
					
				case 2:
					system("cls");
					//Display details for all cars
					break;
					
				case 3:
					system("cls");
					cout<<"Press 1 to display details for all Drivers"<<endl<<"Press 2 to search with Driver ID"<<endl;
					cout<<"Press 3 to exit"<<endl;
					cin>>choice;
					if(choice=1){
						//Display all Drivers
					}
					else if (choice==2){
						//Search Driver using ID
					}
					else if (choice==3){
						//exit
					}
					else{
						cout<<"Choice not recognised....."<<endl;
						choice = 0;
						getch();
					}
					break;
					
				case 4:
					//delete user function
					break;
				case 5:
					//delete car function
					break;
				case 6:
					//delete driver function
					break;
				case 7:
					//Viewing Admin Information
					
					break;
				case 8:
					choice = 8;
					break;
					//loging out from admin
				default:
					cout<<"Your choice is invalid...."<<endl;
					choice = 0;
			}
		}

	}//END of Menu Function
	
	void SetData(string id,string pass){
		cout<<"Enter your Email ID: "<<endl;
		cin>>email;
		ID = id;
		Password = pass;
		name = id;
		gender = 'M';
		age = 19;
		designation = "Admin";
	}
	
	void checkAdmin(){
			string u;
            string pass;
            cout<<"Enter your username: ";
            getline(cin,u);
            if (u=="Abdul Muqeet"){
            	cout<<"Welcome Admin "<<u<<endl<<"Enter your password: ";
            	getline(cin,pass);
            	if (pass=="123@456"){
            		SetData(u,pass);
            		menu();
            	}
            	else 
            		cout<<"Wrong Password Entered....."<<endl;
            		getch();
			}
			else if (u=="Talha Shahid"){
            	cout<<"Welcome Admin "<<u<<endl<<"Enter your password: ";
            	getline(cin,pass);
            	if (pass=="Talha12@"){
            		SetData(u,pass);
            		menu();
            	}
            	else 
            		cout<<"Wrong Password Entered....."<<endl;
            		getch();
            }
            else if (u=="Muhammed Huzaifa"){
            	cout<<"Welcome Admin "<<u<<endl<<"Enter your password: ";
            	getline(cin,pass);
            	if (pass=="4948"){
            		SetData(u,pass);
            		menu();
            	}
            	else{
            		cout<<"Wrong Password Entered....."<<endl;
            		getch();
				}
            }
            else{
            	cout<<"Username not recognized...."<<endl;
            	getch();
			}
	}
    
    Admin();
    void showUser();
    void showAllUserData();
    void ViewAllUser();
    int SaveUser();
    void deleteUser(char *t);
    void updateUser(char *t);
    void searchUser(char *t);
    //  ~Admin();
};
// Additional Function of User
// Admin Constructor
Admin::Admin() : User("NoName", "None", "None", "00000000000", "None", "00000", "NOUserName", 00) {}
// File store this detail before storing data by taking inputs from the users
void Admin::showUser(){
        cout << "\nName         : " << name << endl;
        cout << "User Name    : " << ID << endl;
        cout << "Password     : " << password << endl;
        cout << "Email        : " << email    << endl;
        cout << "Designation  : " << designation << endl;
        cout << "Gender       : " << gender << endl;
}
void Admin::showAllUserData(){
    cout<<username<<" "<<password<<" "<<Name<<" "<<email<<" "<<designation<<" "<<gender<<" "<<endl;
} 
int Admin::SaveUser(){
    ofstream fout;
    if (Name=="NoName" && username=="NOUserName")
    {
        cout<<"User data is not intialized: ";
        return(0);
    }
    else
    {
        ofstream fout;
        fout.open("AUser.dat",ios::app|ios::binary);
        fout.write((char*)this,sizeof(*this));
        fout.close();
        return(1);
    }
    
}
void Admin::ViewAllUser(){
    ifstream fin;
    fin.open("AUser.dat",ios::in|ios::binary);
    if (!fin)
    {
        cout<<"\nFile Not Found";
    }
    else
    {
        fin.read((char*)this,sizeof(*this));
        while (!fin.eof())
        {
            cout << "\n";
            showAllUserData();
            fin.read((char *)this, sizeof(*this));
        }
        fin.close();
        
    }
    
}
void Admin::deleteUser(char *t){
    ifstream fin;  // read file
    ofstream fout; // write file
    fin.open("AUser.txt", ios::in);
    if (!fin)
    {
        cout << "\nFile Not found";
    }
    else
    {
        fout.open("tempfile.dat", ios::out|ios::binary);
        fin.read((char *)this, sizeof(*this));
        while (!fin.eof())
        {
            if (strcmp(password, t))
            {
                fout.write((char *)this, sizeof(*this));
            }
            fin.read((char *)this, sizeof(*this));
        }
        fin.close();
        fout.close();
        remove("AUser.dat");
        rename("tempfile.dat", "AUser.dat");
    }

}
void Admin::updateUser(char *t)
{
    fstream file;
    file.open("AUser.dat", ios::ate | ios::in | ios::out);
    file.seekg(0); // read poniter value zero
    file.read((char *)this, sizeof(*this));
    while (!file.eof())
    {
        if (!strcmp(password, t)) // if data matched this if loop start
        {
            AddUser();
            int t=file.tellp();int s=sizeof(*this);file.seekp(t-s);
            file.write((char *)this, sizeof(*this));
        }
        file.read((char *)this, sizeof(*this));
    }
    file.close();
}
void Admin::searchUser(char *t)
{
    int counter = 0;
    ifstream fin;
    fin.open("AUser.dat", ios::in|ios::binary);
    if (!fin)
    {
        cout << "\nFile not found ";
    }
    else
    {
        fin.read((char *)this, sizeof(*this));
        while (!fin.eof())
        {
            if (!strcmp(password, t))
            {
                showUser();
                counter++;
            }
            fin.read((char *)this, sizeof(*this));
        }
        if (counter == 0)
        {
            cout << "\nRecord not found: ";
        }
        fin.close();
    }
}
//Class Car
// class Car:public Driver
// {
// private:
//     int NoOfSeates;
//     string NoPlate;
// public:
//     Car(/* args */){
//         NoOfSeates=0;
//         NoPlate="XXXXX";
//     }

//     //filling Function
//     void AddUser(int f);
//     void showUser(int f);
//     void showAllUserData(int f);
//     void ViewAllUser(int f);
//     int SaveUser(int f);
//     void deleteUser(char *t, int ud, int f);
//     void updateUser(char *t, int ud, int f);
//     void searchUser(char *t, int ud, int f);
//     //  ~Car();
// };
// //Filling Of Car
// void Car::AddUser(int f)
// {
//     cout << "Enter your Details: \n";
//     // SetUserId();
//     // SetName();
//     // Setadddress();
//     // Setphonenumber();
//     // Setgender();
//     // SetEmail();
//     // SetUserName();
//     // Setpassword();
//     NoOfSeates=123;
//     NoPlate="XXXXX4";
//     cout<<"\n";
//     // Add Inherited Class Fuction hear
//     //
//     showUser(f);
// }
// void Car::showUser(int f)
// {
//     // cout << "\nName         : " << Name << endl;
//     // cout << "Email        : " << Email << endl;
//     // cout << "Gender       : " << Gender << endl;
//     // cout << "PhoneNumber  : " << phonenumber << endl;
//     // cout << "Address      : " << Address << endl;
//     // cout << "Password     : " << password << endl;
//     // cout << "User Id      : " << userid << endl;
//     // cout << "User Name    : " << username << endl;
//     cout<<"No Of Seats      : "<<NoOfSeates<<endl;
//     cout<<"No Plate         : "<<NoPlate<<endl;
//     // Display inherited class Data member hear
// }
// void Car::showAllUserData(int f)
// {
//     // cout << userid << " " << username << " " << Name << " " << Email << " " << Gender << " " << phonenumber << " " << Address << " " << password;
        
//         cout<<NoOfSeates<<" "<<NoPlate<<" ";
// }
// // Additional Function of User
// // Car Constructor
// //Car::Car() : User("NoName", "None", "None", "00000000000", "None", "00000", "NOUserName", 00) {}
// // File store this detail before storing data by taking inputs from the users
// // void Car:: AddUser()
// //  {
// //     cout << "Enter your Details: \n";
// //     SetUserId();
// //     SetName();
// //     Setadddress();
// //     Setphonenumber();
// //     Setgender();
// //     SetEmail();
// //     SetUserName();
// //     Setpassword();
// //     showUser();
// // }
// // void Car::showUser(){
// //         // cout << "\nName         : " << Name << endl;
// //         // cout << "Email        : " << Email << endl;
// //         // cout << "Gender       : " << Gender << endl;
// //         // cout << "PhoneNumber  : " << phonenumber << endl;
// //         // cout << "Address      : " << Address << endl;
// //         // cout << "Password     : " << password << endl;
// //         // cout << "User Id      : " << userid << endl;
// //         // cout << "User Name    : " << username << endl;
// // }
// // void Car::showAllUserData(){
// //     //cout<<userid<<" "<<username<<" "<<Name<<" "<<Email<<" "<<Gender<<" "<<phonenumber<<" "<<Address<<" "<<password;
// //     cout<<NoPlate<<" "<<no<<" "
// // } 
// int Car::SaveUser(){
//     ofstream fout;
//     if (NoPlate=="XXXX4")
//     {
//         cout<<"User data is not intialized: ";
//         return(0);
//     }
//     else
//     {
//         ofstream fout;
//         fout.open("CUser.txt",ios::app|ios::binary);
//         fout.write((char*)this,sizeof(*this));
//         fout.close();
//         return(1);
//     }
    
// }
// void Car::ViewAllUser(){
//     ifstream fin;
//     fin.open("CUser.txt",ios::in);
//     if (!fin)
//     {
//         cout<<"\nFile Not Found";
//     }
//     else
//     {
//         fin.read((char*)this,sizeof(*this));
//         while (!fin.eof())
//         {
//             cout << "\n";
//             showAllUserData();
//             fin.read((char *)this, sizeof(*this));
//         }
//         fin.close();
        
//     }
    
// }
// void Car::deleteUser(char *t){
//     ifstream fin;  // read file
//     ofstream fout; // write file
//     fin.open("CUser.txt", ios::in);
//     if (!fin)
//     {
//         cout << "\nFile Not found";
//     }
//     else
//     {
//         fout.open("tempfile.dat", ios::out);
//         fin.read((char *)this, sizeof(*this));
//         while (!fin.eof())
//         {
//             if (strcmp(password, t))
//             {
//                 fout.write((char *)this, sizeof(*this));
//             }
//             fin.read((char *)this, sizeof(*this));
//         }
//         fin.close();
//         fout.close();
//         remove("CUser.txt");
//         rename("tempfile.dat", "SaveUser.txt");
//     }

// }
// void Car::updateUser(char *t)
// {
//     fstream file;
//     file.open("CUser.txt", ios::ate | ios::in | ios::out);
//     file.seekg(0); // read poniter value zero
//     file.read((char *)this, sizeof(*this));
//     while (!file.eof())
//     {
//         if (!strcmp(password, t)) // if data matched this if loop start
//         {
//             AddUser();
//             int t=file.tellp();int s=sizeof(*this);file.seekp(t-s);
//             file.write((char *)this, sizeof(*this));
//         }
//         file.read((char *)this, sizeof(*this));
//     }
//     file.close();
// }
// void Car::searchUser(char *t)
// {
//     int counter = 0;
//     ifstream fin;
//     fin.open("CUser.txt", ios::in);
//     if (!fin)
//     {
//         cout << "\nFile not found ";
//     }
//     else
//     {
//         fin.read((char *)this, sizeof(*this));
//         while (!fin.eof())
//         {
//             if (!strcmp(password, t))
//             {
//                 showUser();
//                 counter++;
//             }
//             fin.read((char *)this, sizeof(*this));
//         }
//         if (counter == 0)
//         {
//             cout << "\nRecord not found: ";
//         }
//         fin.close();
//     }
// }
////////////////////////////////////////////////
//Global Calling Fuction
int menu()
{
    system("CLS");
    int choice;
    cout << "\nUser Management System: ";
    cout << "\n1. Insert New record ";
    cout << "\n2. View all record ";
    cout << "\n3. Search record ";
    cout << "\n4. Delete record ";
    cout << "\n5. Update record ";
    cout << "\n6. Exit ";
    cout << "\nEnter your choice ";
    cin >> choice;
    return (choice);
}
// Selection between User Admin Driver
int Selection()
{
    system("CLS");
    int selection;
    //        system("CLS");
    cout << "Choose \n1.User\n2.Driver\n3.Admin\n4.Car\n5.For Exit";
    cin >> selection;
    return (selection);
}
// This is the function for User class add work delete and update works
void usermanue()
{
    int i;
    int t = 0;
    // Wow c;
    system("CLS");
    while (1)
    {

        switch (Selection())
        {
        case 1:
            cin.ignore();
            cout << "User: ";
            i = ccustomer();
            // getch();
            break;
        case 2: // Driver and Cars:
            cin.ignore();
            cout<<"Driver: ";
           i = ddriver();
            // i = w();
            break;
        case 3: // Admin
            Admin A;
			cin.ignore();
            cout<<"Admin: ";
            A.checkAdmin();
            
            break;
        case 4: // Admin
            cin.ignore();
            cout<<"Car: ";
         //s   i = ccar();
            break;
        case 5:
            cout << "Thankyou for using Application:";
            getch();
            exit(0);
            break;
        default:
            string a;
            cout << "Your enter the invalid choice: " << endl;
            cout << "Enter any key to continue..." << endl;
            // cin.sync();
            // cin>>a;
            // cin.sync();
            if (t == 0)
            {
                break;
            }
        }
    }
}
// char* ssp(){
//     int i=0;
//     char password[20];
//     while (i==5)
//     {
//         if(strlen(password)>=8){
//             i==5;
//             return password; 
//         }
//         else {
//             cout<<"Enter password";
//             getch();
//         }
//     }
    
// }
//void usermanue();
int ccustomer()
{
    Customer c1;
    char password[20];
    //int ud;
    int i = 4;
    // int f=ff;
    while (i < 5)
    {
         system("cls");
        cout << "Customer\n ";
        switch (menu())
        {
        case 1:
        //    cin.ignore();
            c1.AddUser();
            c1.SaveUser();
            cout << "\nRecord Inserted";
            break;
        case 2:
            c1.ViewAllUser();
            break;
        case 3:
              cout << "\nEnter password :";
            cin.ignore();
            cin.getline(password,49);
            // cin.ignore();
            c1.searchUser(password);
            break;
        case 4:
            cout << "\nEnter password : ";
            //cout << "Userid: ";
            cin.ignore();
            cin.getline(password,49);
            c1.deleteUser(password);
            break;
        case 5:
            cout << "\nEnter password :";
            cin.ignore();
            cin.getline(password,49);
            c1.updateUser(password);
            break;
        case 6:
            cout << "\nDo you want to go back:";
            i = 7;
            getch();
            // void usermanue();
            break;
        default:
            cout << "\nYou Enter the invalid choice ";
            break;
        }
        getch();
    }
    if (i == 7)
    {
        void usermanue();
    }
    return 1;
}
// //Driver Class Main Calling Fuction
int ddriver()
{
    Driver c1;
    char password[20];
    //int ud;
    int i = 4;
    // int f=ff;
    while (i < 5)
    {
         system("cls");
        cout << "Customer\n ";
        switch (menu())
        {
        case 1:
        //    cin.ignore();
            c1.AddUser();
            c1.SaveUser();
            cout << "\nRecord Inserted";
            break;
        case 2:
            c1.ViewAllUser();
            break;
        case 3:
              cout << "\nEnter password :";
            cin.ignore();
            cin.getline(password,49);
            // cin.ignore();
            c1.searchUser(password);
            break;
        case 4:
            cout << "\nEnter password : ";
            //cout << "Userid: ";
            cin.ignore();
            cin.getline(password,49);
            c1.deleteUser(password);
            break;
        case 5:
            cout << "\nEnter password :";
            cin.ignore();
            cin.getline(password,49);
            c1.updateUser(password);
            break;
        case 6:
            cout << "\nDo you want to go back:";
            i = 7;
            getch();
            // void usermanue();
            break;
        default:
            cout << "\nYou Enter the invalid choice ";
            break;
        }
        getch();
    }
    if (i == 7)
    {
        void usermanue();
    }
    return 1;
}
// //Admin Main Class Calling Fuction
//int aadmin()
//{
//    Admin c1;
////Customer c1;
//    char password[20];
//    //int ud;
//    int i = 4;
//    // int f=ff;
//    while (i < 5)
//    {
//         system("cls");
//        cout << "Customer\n ";
//        switch (menu())
//        {
//        case 1:
//        //    cin.ignore();
//            c1.AddUser();
//            c1.SaveUser();
//            cout << "\nRecord Inserted";
//            break;
//        case 2:
//            c1.ViewAllUser();
//            break;
//        case 3:
//              cout << "\nEnter password :";
//            cin.ignore();
//            cin.getline(password,49);
//            // cin.ignore();
//            c1.searchUser(password);
//            break;
//        case 4:
//            cout << "\nEnter password : ";
//            //cout << "Userid: ";
//            cin.ignore();
//            cin.getline(password,49);
//            c1.deleteUser(password);
//            break;
//        case 5:
//            cout << "\nEnter password :";
//            cin.ignore();
//            cin.getline(password,49);
//            c1.updateUser(password);
//            break;
//        case 6:
//            cout << "\nDo you want to go back:";
//            i = 7;
//            getch();
//            // void usermanue();
//            break;
//        default:
//            cout << "\nYou Enter the invalid choice ";
//            break;
//        }
//        getch();
//    }
//    if (i == 7)
//    {
//        void usermanue();
//    }
//    return 1;
// }
// //Car Class Calling Function 
// int ccar()
// {
//     Car c1;
//     char password[20];
//     //int ud;
//     int i = 4;
//     // int f=ff;
//     while (i < 5)
//     {
//          system("cls");
//         cout << "Customer\n ";
//         switch (menu())
//         {
//         case 1:
//         //    cin.ignore();
//             c1.AddUser();
//             c1.SaveUser();
//             cout << "\nRecord Inserted";
//             break;
//         case 2:
//             c1.ViewAllUser();
//             break;
//         case 3:
//               cout << "\nEnter password :";
//             cin.ignore();
//             cin.getline(password,49);
//             // cin.ignore();
//             c1.searchUser(password);
//             break;
//         case 4:
//             cout << "\nEnter password : ";
//             //cout << "Userid: ";
//             cin.ignore();
//             cin.getline(password,49);
//             c1.deleteUser(password);
//             break;
//         case 5:
//             cout << "\nEnter password :";
//             cin.ignore();
//             cin.getline(password,49);
//             c1.updateUser(password);
//             break;
//         case 6:
//             cout << "\nDo you want to go back:";
//             i = 7;
//             getch();
//             // void usermanue();
//             break;
//         default:
//             cout << "\nYou Enter the invalid choice ";
//             break;
//         }
//         getch();
//     }
//     if (i == 7)
//     {
//         void usermanue();
//     }
//     return 1;
// }
int main()
{
    usermanue();
    return 0;
}
