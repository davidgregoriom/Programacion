#include <iostream>
#include <bolsa.h>

using namespace std;

int main()
{
        Bolsa bolsa1;
        Jugador jugador1;
        Jugador jugador2;









        int apuesta1 ;
        cout << "Jugador 1 introduce apuesta entre 10-50: " << endl;
        cin >> apuesta1;jugador1.setNumero_apostado(apuesta1);

        int apuesta2;
        cout << "Jugador 2 introduce apuesta entre 10-50: " << endl;
        cin >> apuesta2;jugador2.setNumero_apostado(apuesta2);


        cout << "empezamos\n";

        int decision=0;
        int contador=0;
        int jugando;
        while(contador >20){
            contador++;
            if(contador%2==1){

                switch(decision){
                case 1:
                    jugando=1;
                    jugador1.jugada(jugando);

                case 2:
                    jugando=0;
                    jugador1.jugada(jugando);

                }
            }else if(contador%2==0){
                switch(decision){
                case 1:
                    jugando=1;
                    jugador1.jugada(jugando);

                case 2:
                    jugando=0;
                    jugador1.jugada(jugando);

                }
            }else{
                contador=21;
            }

        }
        cout << "ha ganado:\n";

        /*
        for(int i=0; i<10; i++){




        cout << "Turno del jugador uno, saca bola: " << endl;
        cout << "Usted ha sacado la bola numero " << endl;
        //  cout << bolsa1.pop_sacarBola() << endl;


        cout << "Turno del jugador 2, saca bola: " << endl;
        cout << "Usted ha sacado la bola numero " << endl;
        }
        */
}
