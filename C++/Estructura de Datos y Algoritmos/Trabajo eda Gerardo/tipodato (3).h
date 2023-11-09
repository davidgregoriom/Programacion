#ifndef TIPODATO_H
#define TIPODATO_H
#include <iostream>
using namespace std;

class TipoDato
{

public:
    TipoDato( int cliente_id);
    int getTipoDato();

private:
int cliente_id;

};



#endif // TIPODATO_H




/*
class TipoData{
public:
 typedef struct {int llegada} Data;
 TipoData::Data GetData();
};
*/
