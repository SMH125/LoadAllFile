#include <iostream>
#include <cmath>
#define pi 3.1416
using namespace std;
float Radius (float x1, float y1, float x2, float y2)
{
    float temp_distance_x,distance,temp_distance_y;
    temp_distance_x=pow((x2-x1),2);
    temp_distance_y = pow ((y2-y1),2);
    distance = pow((temp_distance_x + temp_distance_y),0.5);
    return (distance);
}
float Circumference (float r)
{
    return (2*pi*r);
}
float Area (float r)
{
    return (pi*r*r);
}

int main()
{
    float x1,x2,y1,y2;
    cout<<"Please enter the coordinates of the first point: "<<endl;
    cin>>x1>>y1;
    cout<<"Please enter the coordinates of the second point: "<<endl;
    cin>>x2>>y2;
    float dist;
    dist= Radius(x1,y1,x2,y2);
    cout<<"The distance between the two entered points are: "<<dist<<endl;

    cout<< "Please enter coordinates of the centre of circle: "<<endl;
    cin>>x1>>y1;
    cout<<"Please enter coordinates of the point: "<<endl;
    cin>>x2>>y2;
    float radius,circumference,area;
    radius = Radius(x1,y1,x2,y2);
    cout<<"The radius of the circle according to entered parameters is: "<<radius<<"units"<<endl;
    circumference = Circumference(radius);
    cout<<"The circumference of the circle is: "<<circumference<<"units"<<endl;
    area = Area(radius);
    cout<<"The area of the circle is: "<<area<<"sq units"<<endl;


    

}