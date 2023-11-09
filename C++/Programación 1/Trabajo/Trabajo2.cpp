#include <iostream>
#include <array>


using namespace std;

struct Jugador{
    int Dinero = 10;
    int ApuestaNumero= 0;
    bool ApuestaColor = 0;
    int Opcion = 0;
    int DineroApostado;
    bool tipoApuesta = true;
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
    cin>>i;
    return i;
}
Ruleta apostar(Ruleta r){
    if(){
    r.Primero.ApuestaNumero=
    }else{
    r.Primero.ApuestaColor=
    }
    if(){
       r.Segundo.ApuestaNumero=
    }else{
    r.Segundo.ApuestaColor=
    }
    if(){
     r.Tercero.ApuestaNumero=
    }else{
    r.Tercero.ApuestaColor=
    }
    if(){
    r.Cuarto.ApuestaNumero=
    }else{
    r.Cuarto.ApuestaColor=
    }
  return r;
}
if(r.Primero.tipoApuesta==true){
    r.Primero.ApuestaNumero=
    }else{
    r.Primero.ApuestaColor=
    }
int menu2(){
    cout<<"Que vas a apostar\n";
    cout<<"1.Apuesto a un numero\n";
    cout<<"2.Apuesto a un color\n";
    cin>>j;
    return j;
}
int funcion_apuesta_numero( int & dinero1, int & cantidad1,int   & opcion1){
    cout<<"Introduzca su apuesta:\n";
    cin >>cantidad1;
    if(cantidad1>=0 & cantidad1<=dinero1){
        dinero1=dinero1-cantidad1;
        cout<<"Introduzca su opcion(numero del 1 al 36):\n";
        cin >>opcion1 ;
        if(opcion1<=36 & opcion1>=1){
            cout << "Suerte\n";
        }else{
            cout<<"Vuelva otra vez a introducirlo\n";
            cin>> opcion1;

        }
    }else{
        cout<<"No tienes tanto dinero chavalote\n";
        cout<<"Vuelve a introducir tu cantidad\n";
        cin>> cantidad1;

    }

    return opcion1 &dinero1 &cantidad1;



}
int funcion_apuesta_color(int & dinero1,int  & cantidad1, bool & opcion1){
    cout<<"Introduzca su apuesta:\n";
    cin >>cantidad1;
    if(cantidad1>=0 & cantidad1<=dinero1){
        dinero1=dinero1-cantidad1;
        cout<<"Introduzca su opcion(rojo o negro):\n";
        cin >>opcion1 ;
        if(opcion1=='rojo'|'negro'){
            cout << "Suerte\n";
        }else{
            cout<<"Vuelva otra vez a introducirlo\n";
            cin>> opcion1;

        }
    }else{
        cout<<"No tienes tanto dinero chavalote\n";
        cout<<"Vuelve a introducir tu cantidad\n";
        cin>> cantidad1;
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
    ruleta = apostar(ruleta);
    int gano;
    int gananciadelaBanca=0;
    int numero_suerte=numero_ruleta();
    array<char,4>loqueeligen{0,0,0,0};
    int i =0,j=0;
    double Ruleta;
    while(i!=4){
        i=menu1();
        cin>>i;
        switch(i){
        case 1:
            j=menu2();
            cin>>j;
            switch(j){
            case 1:
                Ruleta=funcion_apuesta_numero(ruleta.Primero.Dinero,ruleta.Primero.DineroApostado,ruleta.Primero.ApuestaNumero);
                if(ruleta.Primero.ApuestaNumero==numero_suerte){
                    gano=funcion_ganado(ruleta.Primero.DineroApostado,ruleta.Primero.ApuestaNumero,ruleta.Primero.Dinero);
                }else{
                    gananciadelaBanca=ganancia_banca(ruleta.Primero.DineroApostado,gananciadelaBanca);
                }
                break;
            case 2:
                Ruleta=funcion_apuesta_color(ruleta.Primero.Dinero,ruleta.Primero.DineroApostado,ruleta.Primero.ApuestaColor);
                if(ruleta.Primero.ApuestaColor==numero_suerte){
                    gano=funcion_ganado(ruleta.Primero.DineroApostado,ruleta.Primero.ApuestaNumero,ruleta.Primero.Dinero);
                }else{
                    gananciadelaBanca=ganancia_banca(ruleta.Primero.DineroApostado,gananciadelaBanca);
                }
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
            cout<< "Tienes de saldo: " <<ruleta.Primero.Dinero<< "€ \n";
            break;
        case 3:
            cout<<"Te retiras en esta partida\n";
            break;

        case 4:

            cout<< "Tienes de saldo: " <<ruleta.Primero.Dinero<< "€ \n";
            cout<< "Retiras esa catidad\n";
            cout<< "la maquina ha ganado hasta ahora "<<gananciadelaBanca<<"€ \n";

            break;

        default:
            i=menu1();
            cin>>i;
        }
    }
}
