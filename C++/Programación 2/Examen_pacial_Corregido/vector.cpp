#include "vector.h"
#include <vector>
#include <iostream>
#include <math.h>

using namespace  std;

Vector::Vector(): x{0},y{0},z{0}{

}

Vector::Vector(float x, float y , float z): x{x},y{y},z{z}{

}

float Vector::getX() const
{
    return x;
}

void Vector::setX(float value)
{
    x = value;
}

float Vector::getY() const
{
    return y;
}

void Vector::setY(float value)
{
    y = value;
}

float Vector::getZ() const
{
    return z;
}

void Vector::setZ(float value)
{
    z = value;
}
float Vector::getModule(){
    float mod=sqrt(x*x+y*y+z*z);
    return mod;
}
Vector operator+(Vector const & v1,Vector const & v2){
    Vector v;
    v.setX(v1.x+v2.x);
    v.setY(v1.y+v2.y);
    v.setZ(v1.z+v2.z);
    return v;
}
Vector operator-(Vector const & v1,Vector const & v2){
    Vector v;
    v.setX(v1.x-v2.x);
    v.setY(v1.y-v2.y);
    v.setZ(v1.z-v2.z);
    return v;
}
float operator*(Vector const & v1,Vector const & v2){
    float v=v1.x*v2.x+v1.y*v2.y+v1.z*v2.z;
    return v;
}
std::ostream & operator<<(std::ostream & os,Vector const & v){
    std::cout<<"["<<v.x<<","<<v.y<<","<<v.z<<"] \n";
    return os;
}
std::istream & operator>>(std::istream & is,Vector & v){
    is>>v.x>>v.y>>v.z;
    return is;
}
bool operator==(Vector const & v1,Vector const & v2){
    if(v1.x==v2.x && v1.y==v2.y && v1.z==v2.z)return true;
    return false;
}
