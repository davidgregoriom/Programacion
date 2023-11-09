#include <memory>
#include <iostream>

using namespace std;

struct ElementoListaSimple {
   int digit;

   std::shared_ptr<ElementoListaSimple> next = nullptr;

    ElementoListaSimple(int d) : digit{d} {}
};


class ListaSimple {
   public:
       ListaSimple() {
           setInicio(_inicio);
           setFinal(_final);

}
       int size(std::shared_ptr<ElementoListaSimple> lista) {
           if (lista == nullptr) {
               return 0;
           }
           return 1 + size(lista->next);
       }

       void addElemento(int digit) {
           int size();
           // Añade un elemento al final de la lista
           auto elem = std::make_shared<ElementoListaSimple>(ElementoListaSimple{digit});
           if (!_inicio) {
               _inicio = _final = elem;
           }
           else {
               _final = _final->next = elem;
           }
       }

       int retrieveNumber() const {// TODO: Tu código empieza aquí
            shared_ptr<ElementoListaSimple> inter= inicio();
           if(inicio()==nullptr&& final()==nullptr)

           return -1; // La función debe devolver el número representado por la lista
           else{
                while(inter!=nullptr){
                    cout<< inter->digit;
                    inter = inter->next;
                }
           }
       }



       std::shared_ptr<ElementoListaSimple> inicio() const;
       void setInicio(const std::shared_ptr<ElementoListaSimple> &inicio);

       std::shared_ptr<ElementoListaSimple> final() const;
       void setFinal(const std::shared_ptr<ElementoListaSimple> &final);

protected:
       std::shared_ptr<ElementoListaSimple> _inicio = nullptr;
       std::shared_ptr<ElementoListaSimple> _final = nullptr;
};


int main() {
   ListaSimple lista;
   lista.addElemento(4);
   lista.addElemento(5);
   lista.addElemento(1);

   std::cout << "Número almacenado: " << lista.retrieveNumber() << std::endl;
}

std::shared_ptr<ElementoListaSimple> ListaSimple::inicio() const
{
return _inicio;
}

void ListaSimple::setInicio(const std::shared_ptr<ElementoListaSimple> &inicio)
{
_inicio = inicio;
}

std::shared_ptr<ElementoListaSimple> ListaSimple::final() const
{
return _final;
}

void ListaSimple::setFinal(const std::shared_ptr<ElementoListaSimple> &final)
{
_final = final;
}
