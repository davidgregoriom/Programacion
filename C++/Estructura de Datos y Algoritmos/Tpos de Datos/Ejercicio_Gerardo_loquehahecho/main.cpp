#include <iostream>
#include <string>

using namespace std;

class colegio{
  public:
    string nombre;
    int nota;
  private:
    int numero_examenes_realizados1;
  public:
  int numero_examenes(){
     return numero_examenes_realizados1;
 }
  void numero_examenes_nuevos(int numero_nuevo_examenes){
       numero_examenes_realizados1 = numero_nuevo_examenes;
  }
    colegio(){
      nombre = "maria";
      nota = 0;
      numero_examenes_realizados1 = 50;
    }
};

int main() {
  auto c = colegio();
  cout << c.nombre<< "\n";
  cout << c.nota << endl;
  auto d = c.numero_examenes();
  cout << d << endl;
  c.numero_examenes_nuevos(200);
  cout << c.numero_examenes();
}
