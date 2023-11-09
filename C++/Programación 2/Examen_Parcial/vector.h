#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <vector>
#include <array>
#include <istream>
#include <ostream>
#include <math.h>
#include <string>


using namespace  std;
class Vector
{
    friend Vector operator+(Vector const & v1, Vector const & v2);
        friend Vector operator-(Vector const & v1, Vector const & v2);
        friend Vector operator*(Vector const & v1, Vector const & v2);
    friend ostream & operator <<(ostream & os,Vector const & a);
    friend ostream & operator ==(ostream & os,Vector const & a);
    friend istream & operator >>(istream & is, Vector & a);
public:
    Vector();
    Vector(float a , float b, float c);
    //vector<array<float, 3> > getVectcoord(int row,int col);
    //void setVectcoord(int row,int col, float value);
    //void getModule(const vector<array<float,3>> & modulo);

    float getX() const;
    void setX(float value);

    float getY() const;
    void setY(float value);

    float getZ() const;
    void setZ(float value);

    float getModule(Vector const & a);

private:
    float  x,y,z;
};
    Vector operator+(Vector const & v1, Vector const & v2);
    Vector operator-(Vector const & v1, Vector const & v2);
     Vector operator*(Vector const & v1, Vector const & v2);

ostream & operator <<(ostream & os, Vector const & a);
ostream & operator ==(ostream & os, Vector const & a);
istream & operator >>(istream & is, Vector & a);
#endif // VECTOR_H
