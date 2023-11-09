#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <iostream>
#include <vector>
#include <memory>
#include "publicacion.h"
#include "libro.h"
#include "articulo.h"


using namespace std;

class Biblioteca{
private:
    vector<shared_ptr<Publicacion>>biblio;
public:
    void anadir(const shared_ptr<Articulo> & b){
        biblio.push_back(b);
    }
    void anadir(const shared_ptr<Libro> & b){
        biblio.push_back(b);
    }
    void borrar(const string &titulo,const string & autor){
        for(int i{0};i<biblio.size();i++){
            if(biblio.at(i)->getTitulo()==titulo && biblio.at(i)->getAutor()==autor){
                biblio.erase(biblio.begin()+i);
            }
        }
    }
    shared_ptr<Publicacion> buscar(const string & titulo,const string & autor){
        for(int i=0;i<biblio.size();i++){
            if(biblio.at(i)->getTitulo()==titulo && biblio.at(i)->getAutor()==autor){
                return biblio.at(i);
            }else{
                cout << "no esta";
            }
        }
        if(biblio.size()==0){
            cout<<"agenda vacia";
        }
    }
    void listar(const string &titulo,const string &autor){
        if(buscar(titulo,autor)==true){

        }

    }
    vector<shared_ptr<Publicacion> > getBiblio() const{
        return biblio;
    }
};
ostream & operator <<(ostream & os, const Biblioteca&b){
    for(auto elem:b.getBiblio()){
        os<<elem<<endl;
    }
    if(b.getBiblio().size()==0){
        os<<"biblioteca vacia ";
    }
    return os;
}

ostream & operator <<(ostream & os,const shared_ptr<Publicacion>&b){
    os<<b->getAutor()<<endl;
    os<<b->getTitulo()<<endl;
    if(b->WhoAmI()=="Libro"){
        Libro *L=dynamic_cast<Libro*>(b.get());
        if(L!=nullptr){
            os<<L->editorial<<endl;
        }
    }else if(b->WhoAmI()=="Articulo"){
        Articulo *A=dynamic_cast<Articulo*>(b.get());
        if(A!=nullptr){
            os<<A->otros_autores<<endl;
        }
    }

    return os;
}

#endif // BIBLIOTECA_H
