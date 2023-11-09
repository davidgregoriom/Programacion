#include "gente.h"

using namespace std;

int gente::getNum() const{
    return num;
}

void gente::setNum(int value){
    num = value;
}

string gente::getNom() const{
    return nom;
}

void gente::setNom(const string &value){
    nom = value;
}

gente::gente(){

}
