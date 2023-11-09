#include <iostream>
#include "cola.h"
#include "gente.h"

using namespace std;

int main(){
  cola col(5); //Tamaño de la cola

  col.push_back(612345678, "Virginia"); //Añadimos nombres con sus respectivos numeros de telefono
  col.push_back(612344378, "Antonio");
  col.push_back(698344378, "Fernando");

  cout << "Atendiendo a: "; col.pop_front(); cout << endl; //Deberá mostrarse el nombre de la persona y su teléfono.

  col.push_back(643215678, "Manolo");
  col.push_back(687644378, "Federica");
  col.push_back(698346543, "Estefania");
  //col.push_back(698346565, "Estefano");  //Lista llena, lanza excepción

  cout << "El proximo en ser atendido sera: "; col.peekt(); cout << endl;

  cout << col.getSize() + 1 << " llamadas quedan por atender" << endl << endl; //Para ver cuántas llamadas quedan por atender

  col.print(); cout << endl; //Me permite ver el número de llamadas en espera, indicando el nombre de las personas.

  while(col.isEmpty() == false){ //Atendemos a todos los que queden
    cout << "Atendiendo a: "; col.pop_front(); cout << endl; //Deberá mostrarse el nombre de la persona y su teléfono.
    cout << col.getSize() + 1 << " llamadas quedan por atender" << endl << endl;
  }

  //cout << "Atendiendo a: "; col.pop_front(); cout<<endl; //Lista ya vacía, para comprobar la excepcion

  return 0;
}
