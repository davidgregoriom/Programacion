#include <iostream>

using namespace std;

class DiaAnio{
private:
    int dia,mes;
public:
    DiaAnio(const int & dia_,const int  &mes_){
        dia=dia_;
        mes=mes_;
    }
    //Igualdad en las fechas
    bool igual(const DiaAnio& d){
        if(dia==d.dia && mes == d.mes){
            return true;
        }else{
            return false;
        }
    }
    void visualizar(){
        cout<<"Muestro los datos: "<< endl;
        cout<<"Dia :"<<dia<<endl<<"Mes: "<<mes << endl;
    }
};

int main(){
    DiaAnio* hoy;
    DiaAnio* cumple;
    int d,m;

    cout << "Introduce fecha de hoy: ";
    cin >> d >> m;
    hoy=new DiaAnio(d,m);

    cout << "Introduce fecha de tu cumpleaños: ";
    cin >> d >> m;
    cumple= new DiaAnio(d,m);

    //fecha de hoy
    hoy->visualizar();
    cout << endl;

    //fecha de cumpleaños
    cumple->visualizar();
    cout <<endl;

    if(hoy->igual(*cumple)){
        cout <<"feliz cumpleaños"<< endl;
    }
    else{
        cout <<":("<<endl;
    }
    system("pause");
    return 0;
}
