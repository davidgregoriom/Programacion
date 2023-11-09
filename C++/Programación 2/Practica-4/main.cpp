#include <iostream>
#include "db.h"
#include <string>
using namespace std;

int main()
{

  Pair<string,string> Nombre1= {"nombre","Julian"};
  Pair<string,string> apellido1= {"apellido","Santurche"};
  Pair<string,string> telefono1= {"telefono", "32323232"};


  Pair<string,string> Nombre2= {"nombre","Alberto"};
  Pair<string,string> apellido2= {"apellido","Valero"};
  Pair<string,string> telefono2= {"telefono", "12345644"};


  Pair<string,string> Nombre3= {"nombre","Julian"};
  Pair<string,string> apellido3= {"apellido","Romeva"};
  Pair<string,string> telefono3= {"telefono", "12345644"};
  Pair<string,string> DNI= {"DNI","23232334J"};


  Pair<string,string> Nombre4= {"nombre","Lucrecia"};
  Pair<string,string> apellido4= {"apellido","Aveces"};
  Pair<string,string> correo4= {"email","lalucre@gmail.com"};

/*
  shared_ptr<Data<Pair<string,string>,Pair<string,string>,Pair<string,string>> Data1= make_shared{Nombre1,apellido1,telefono1};
  shared_ptr<Data<Pair<string,string>,Pair<string,string>,Pair<string,string>> Data2= make_shared{Nombre2,apellido2,telefono2};
  shared_ptr<Data<Pair<string,string>,Pair<string,string>,Pair<string,string>,Pair<string,string>> Data2= make_shared{Nombre3,apellido3,telefono3,DNI};
  shared_ptr<Data<Pair<string,string>,Pair<string,string>,Pair<string,string>> Data2= make_shared{Nombre4,apellido4,telefono4};

  NS COMO CONTINUARRRRRRR


    return 0;
    */
}
