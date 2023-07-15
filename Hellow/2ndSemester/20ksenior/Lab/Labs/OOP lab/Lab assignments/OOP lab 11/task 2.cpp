#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class vehicle
{
	protected:
		string type,make,color;
		int model,year,miles;
		vehicle(string t, string m, string c, int model, int years, int miles)
		{
			type = t;
			make = m;
			color = c;
			this->model = model;
			this->year = year;
			this->miles = miles;
		}
};

class gasvehicle : virtual public vehicle
{
	protected:
		int fueltank;
		gasvehicle(int f,string t, string m, string c, int model, int year, int miles) : vehicle(t,m,c,model,years,miles)
		{
			fueltank = f;
		}
};

class electricvehicle : virtual public vehicle
{
	protected:
		int energystorage;
		electricvehicle(int e, string t, string m, string c, int model, int years, int miles) : vehicle(t,m,c,model,years,miles)
		{
			energystorage = e;
		}
};

class heavyvehicle : public gasvehicle, public electricvehicle
{
		protected:
			int max_weight,wheels,length;
			heavyvehicle(int e, int f, string t,string m,string c, int model, int years, int miles) : electricvehicle(e,t,m,c,model,years,miles),gasvehicle(f,t,m,c,model,years,miles),vehicle(t,m,c,model,years,miles)
			{
				
			}
			//setters
			set_data(int m, int w, int l)
			{
				max_weight = m;
				wheels = w;
				length = l;
			}
};

class highperformance : public gasvehicle
{
	protected:
	int hp,tspeed;
	highperformance(int h, int ts, int f, string t, string c, string m, int model, int years, int miles) : gasvehicle(f,t,m,c,model,years,miles)
	{
		hp = h;
		tspeed = ts;	
	}	
};
class sportscar : public highperformance
{
	protected:
	string gbox,drive;
	sportscar(string g, string d, int h, int t, int f, str)
};
