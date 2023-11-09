#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
class Vector
{
        friend Vector operator+ (Vector const & v1,Vector const & v2);
        friend Vector operator- (Vector const & v1,Vector const & v2);
        friend float operator* (Vector const & v1,Vector const & v2);
        friend std::ostream & operator<<(std::ostream & os,Vector const & v);
        friend std::istream & operator>>(std::istream & is,Vector & v);
        friend bool operator==(Vector const & v1,Vector const & v2);
public:
    Vector();
    Vector(float x,float y, float z);
    float getX() const;
    void setX(float value);

    float getY() const;
    void setY(float value);

    float getZ() const;
    void setZ(float value);
    float getModule();

private:
    float x,y,z;
};

#endif // VECTOR_H
