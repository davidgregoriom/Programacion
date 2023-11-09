#include <iostream>
#include <vector>
#ifndef ARTICULOS_H
#define ARTICULOS_H

using namespace std;

class articulos
{
private:
    string titulo,autor;
    vector<string>otro_autores;
public:
    articulos();
    articulos(const string & titulo_,const string &autor_, const vector<string>& otros_autores_);
};

#endif // ARTICULOS_H
