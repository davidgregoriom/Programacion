#include <iostream>
#include <array>


using namespace std;

struct Jugador{
    int Dinero = 10;
    int ApuestaNumero= 0;
    bool ApuestaColor = 0;
    int Opcion = 0;

};

struct Ruleta{
    Jugador Primero;
    Jugador Segundo;
    Jugador Tercero;
    Jugador Cuarto;
};

Jugador p1{
};
Jugador p2{
};
Jugador p3{
};
Jugador p4{
};
Jugador B{
};

Ruleta ruleta{
    p1,
    p2,
    p3,
    p4,
};




int menu1(){
    cout<<"Que quiere hacer?\n";
    cout<<"Elige tu opcion\n";
    cout<<"1.Apuesta\n";
    cout<<"2.Mirar Dinero\n";
    cout<<"3.Retirarse\n";
    cout<<"4.Retirar Dinero y ver las ganancias de la maquina\n";
}
int menu2(){
    cout<<"Que vas a apostar\n";
    cout<<"1.Apuesto a un numero\n";
    cout<<"2.Apuesto a un color\n";
}

int funcion_apuesta_numero( int & dinero1, int & cantidad1,int   & opcion1){
    if(cantidad1>=0 & cantidad1<=dinero1){
        cout<<"Introduzca su apuesta:\n";
        cin >>cantidad1;
        cout<<"Introduzca su opcion(numero del 1 al 36):\n";
        cin >>opcion1 ;
        if(opcion1<=36 & opcion1>=1){
            cout << "Suerte\n";
        }else{
            cout<<"Vuelva otra vez a introducirlo\n";
            cin>> opcion1;

        }
    }else if(cantidad1> dinero1){
        cout<<"No tienes tanto dinero chavalote";

    }else{

    return opcion1 |dinero1 |cantidad1;


    }
}
int funcion_apuesta_color(int & dinero1,int  & cantidad1, bool & opcion1){

    if(cantidad1>=0 & cantidad1<=dinero1){
        cout<<"Introduzca su opcion(rojo o negro):\n";
        cin >>opcion1 ;
        if(opcion1=='rojo'|'negro'){
            cout << "Suerte\n";
        }else{
            cout<<"Vuelva otra vez a introducirlo\n";
            cin>> opcion1;

        }
    }else if(cantidad1> dinero1){
        cout<<"No tienes tanto dinero chavalote";

    }else{


    }
}

int numero_ruleta(){
    int random;
    srand(time(NULL));
    random = rand() % 36 + 0;
    return random;

}



int funcion_ganado(int  & apostado, int & opct, int & el_dinero){

  if(opct<=36 |opct>=1 ){
    apostado = 35*apostado;
    el_dinero = apostado + el_dinero;
    cout << "Felicidades!";
  }else{
    apostado = 2*apostado;
    el_dinero=apostado+el_dinero;
  }
  return el_dinero;
}
int ganancia_banca(int & apostado,int & ganabanca){
   ganabanca= ganabanca+ apostado;
   apostado=0;
}

int main(){
    int numero_suerte=numero_ruleta();
    array<char,4>loqueeligen{0,0,0,0};
    int i =0,j=0;
    double Ruleta;
        i=menu1();
        cin>>i;
        switch(i){
        case 1:
            j=menu2();
            cin>>j;
            switch(j){
            case 1:
                Ruleta=funcion_apuesta_numero(ruleta.Primero.Dinero,ruleta.Primero.Opcion,ruleta.Primero.ApuestaNumero);
                break;
            case 2:
                Ruleta=funcion_apuesta_color(ruleta.Primero.Dinero,ruleta.Primero.Opcion,ruleta.Primero.ApuestaColor);
                break;
            default:
                j=menu2();
                cin>>j;
                break;
            }

            i=menu1();
            cin>>i;
            break;
        case 2:
            cout<<
            break;
        case 3:

            break;

        case 4:
            cout <<ruleta.Primero.Dinero;

            break;

        default:
            i=menu1();
            cin>>i;
            break;
        }




}
