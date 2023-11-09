#ifndef MATRIZ_H
#define MATRIZ_H
#include <array>
#include <iostream>
#include <memory>

using namespace std;

class Matriz3x3{
public:
    Matriz3x3();
    Matriz3x3(array<float,9> v);
    void print() const;
    int determinant() const;


    shared_ptr<Matriz3x3>add(shared_ptr<Matriz3x3>a,shared_ptr<Matriz3x3>b);

    int getMat(int row,int col) ;
    void setMat(int row ,int col,int value);

private:
    array<array<float,3>,3>mat;

};

#endif // MATRIZ_H
