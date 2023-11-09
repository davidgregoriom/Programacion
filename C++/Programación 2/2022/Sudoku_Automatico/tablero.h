#ifndef TABLERO_H
#define TABLERO_H
#include <array>
#include <memory>
#include <vector>

using namespace std;


class Tablero
{
protected:
    array<array<int, 9>, 9> datos;

public:
    Tablero(array<array<int, 9>, 9> datos);
    Tablero();

};

#endif // TABLERO_H
