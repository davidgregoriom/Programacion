#ifndef MATRIX_H
#define MATRIX_H

#include <array>
#include <ostream>
#include <istream>
#include <memory>
using namespace std;

class Matrix
{
    friend ostream & operator <<(ostream & os,Matrix const & a);
    friend istream & operator >>(istream & is, Matrix & a);
public:
    Matrix();
    Matrix(array<float,9> const & p);
    float get(int row,int col) const;
    void set(int row,int col, float value) ;
    void print() const ;
    float determinant() const;
private:
   array<array<float,3>,3> data;
};

ostream & operator <<(ostream & os, Matrix const & a);
istream & operator >>(istream & is, Matrix & a);
shared_ptr<Matrix> add(shared_ptr <Matrix> a, shared_ptr <Matrix> b);

Matrix operator+ (Matrix const & a, Matrix const &b);

#endif // MATRIX_H
