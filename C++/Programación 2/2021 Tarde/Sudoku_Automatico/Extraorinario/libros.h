#include <iostream>
#ifndef LIBROS_H
#define LIBROS_H

using namespace std;

class libros
{
private:
    string titulo,autor,editorial;

public:
    libros();
    libros(const string & titulo_,const string & autor_,const string & editorial_);
};

#endif // LIBROS_H
