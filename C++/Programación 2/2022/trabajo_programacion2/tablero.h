#ifndef TABLERO_H
#define TABLERO_H
#include <array>

using namespace std;


class Tablero
{
protected:
    array<array<int, 9>, 9> datos;
public:
    Tablero();
};

#endif // TABLERO_H
