#include "completo.h"

Complejo::Complejo(float _x,float _y, float _z){
    vectorComplejo.push_back(_x);
    vectorComplejo.push_back(_y);
    vectorComplejo.push_back(_z);
}

void Complejo::set_x(float _x){
    vectorComplejo.at(0)=_x;
}
void Complejo::set_y(float _y){
    vectorComplejo.at(1)=_y;
}
void Complejo::set_z(float _z){
    vectorComplejo.at(2)=_z;
}

float Complejo::get_x(){
    return vectorComplejo.at(0);
}
float Complejo::get_y(){
    return vectorComplejo.at(1);
}
float Complejo::get_z(){
    return vectorComplejo.at(2);
}
