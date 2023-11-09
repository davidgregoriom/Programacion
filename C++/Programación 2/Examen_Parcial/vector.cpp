#include <iostream>
#include "vector.h"


Vector::Vector(): x{0}, y{0},z{0}{};

Vector::Vector( float x,float y,float z): x{x},y {y}, z{z}{}

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

float Vector::getModule(const Vector &a)
{
    return sqrt ((a.getX()*a.getX())+(a.getY()*a.getY())+(a.getZ()*a.getZ()));
}


//vector<array<float, 3> > Vector::getVectcoord(int row,int col)
//{
//if(row<0||row >2||col <0||col>2) throw string{"out of bonds"};
    //return vectcoord.at(row).at(col);
//}

//void Vector::setVectcoord(int row,int col,float value)
//{
    //if(row<0||row >2||col <0||col>2) throw string{"out of bonds"};
     //vectcoord.at(row).at(col) = value;
//}

//void Vector::getModule(



Vector operator+(Vector const & v1, Vector const & v2){
    Vector result{v1.x+v2.x, v1.y+v2.y, v1.z+v2.z};
    return result;
}

Vector operator-(Vector const & v1, Vector const & v2){
    Vector result{v1.x-v2.x, v1.y-v2.y, v1.z-v2.z};
    return result;
}

Vector operator*(Vector const & v1, Vector const & v2){
    Vector result{v1.x*v2.x, v1.y*v2.y, v1.z*v2.z};
    return result;
}

ostream &operator <<(ostream &os, const Vector &a)
{

}

ostream &operator ==(ostream &os, const Vector &a)
{

}

istream &operator >>(istream &is, Vector &a)
{

}
