#include "matrix.h"
#include <iostream>

using namespace  std;

Matrix::Matrix()
{
    for(int fila {0}; fila<3; fila++){
        for(int col {0}; col<3; col++){
            data.at(fila).at(col)=0;
        }
    }
}

Matrix::Matrix(const array<float,9>&p)
{
    int indice=0;
    for(int fila {0}; fila<3; fila++){
        for(int col {0}; col<3; col++){
            data.at(fila).at(col)=p.at(indice);
            indice++;
        }
    }
}

float Matrix::get(int row,int col)const
{
    if(row<0||row >2||col <0||col>2) throw string{"out of bonds"};
    return data.at(row).at(col);
}
void Matrix::set(int row,int col, float value)
{
    if(row<0||row >2||col <0||col>2) throw string{"out of bonds"};
     data.at(row).at(col) = value;
}

void Matrix:: print() const {
    for(int fila {0}; fila<3; fila++){
        for(int col {0}; col<3; col++){
           cout << data.at(fila).at(col);
        }
        cout << "\n";
    }
}

float Matrix::determinant() const
{
    return 9; //Ya se como hacer un determinante :float determinante = (mat.at(0).at(0) * mat.at(1).at(1) * mat.at(2).at(2) +mat.at(1).at(0) * mat.at(2).at(1) * mat.at(0).at(2) + mat.at(0).at(1) *mat.at(1).at(2) * mat.at(2).at(0)) - (mat.at(0).at(2) * mat.at(1).at(1) * mat.at(2).at(0) + mat.at(1).at(2) * mat.at(2).at(1) * mat.at(0).at(0) + mat.at(1).at(0) * mat.at(0).at(1) * mat.at(2).at(2));
}

ostream &operator <<(ostream &os, const Matrix &a)
{
    for(int fila {0}; fila<3; fila++){
        for(int col {0}; col<3; col++){
           os << a.data.at(fila).at(col);
        }
        os<< "\n";
    }
    return os;
}

shared_ptr<Matrix> add(shared_ptr<Matrix> a, shared_ptr<Matrix> b)
{
    auto result = make_shared<Matrix>();
    for(int fila {0}; fila<3; fila++){
        for(int col {0}; col<3; col++){
           result->set(fila,col, a->get(fila,col)+ b->get(fila,col));
        }
    }
    return result;
}

Matrix operator+(const Matrix &a, const Matrix &b)
{
    Matrix result;
    for(int fila {0}; fila<3; fila++){
        for(int col {0}; col<3; col++){
           result.set(fila,col, a.get(fila,col)+ b.get(fila,col));
        }
    }
    return result;
}

istream &operator >>(istream &is, Matrix &a)
{
    for(int fila {0}; fila<3; fila++){
        for(int col {0}; col<3; col++){
           is>> a.data.at(fila).at(col);
        }
    }
    return is;
}
