#include <iostream>
#include <array>
#include<string>
using namespace std;
int numero_jugadores = 4 ;
int casillas_ruleta = 37;
int saldo_inicial = 10;

struct jugador {
    string nombre;
    int saldo ;
    int retirado;
};

struct jugador jugadores[4];
/*
como analiza el compilador los arrays

<tipo lo que está hecho el array> <nombre_array< '['<nº_casillas ']' ;

int misnumeros[10];
*/

//array de 4 jugadores

struct apuesta {
    int tipo_apuesta; //numero o color
    int apuesta; //qué número o qué color
    int dinero_apostado; //money
};
struct apuesta apuesta_actual[4];


int main() {
  int i;
  int tipo_apuesta;
  int respuesta;
  int respuesta_apuesta;
  int cantidad_apostada;
  int hay_apuestas_Activas;
  int  numero_ganador;
  int  color_ganador;
  int ganancias_numero;
  int ganancias_color;
  int jugadores_retirados;
    int jugadores_fuera;
    int jugadores_arruinados;
  string esta_apuesta;
  string resultado_apuesta;
  string resultado_retirado;
  string resultado_arruinado;
  string resultado_dinero;
  string color_resultado;
  //inicializamos los jugadores
  for(i = 0; i < 4; i++){
    jugadores[i].nombre = "Jugador " +  to_string(i + 1) ;
    jugadores[i].saldo = saldo_inicial;
    jugadores[i].retirado = 0;
  }


 // numero_jugadores;
 // casillas_ruleta;
  while (true){




    //apostar:
    for (i=0; i < numero_jugadores; i++) {

      //si está retirado, no hacer nada. Así que tiene q estar no retirado

    // cout << "i en el bucle principal " << i << "\n";
        if (jugadores[i].retirado == 0){
        //ver si tiene saldo
        if (jugadores[i].saldo > 0){
          //preguntar si quiere apostar  si quiere retirarse

          apuesta_actual[i].tipo_apuesta = 0;
          apuesta_actual[i].apuesta = 0;
          apuesta_actual[i].dinero_apostado = 0;
          //primero enseñamos el dinero inicial de cada uno
          cout <<jugadores[i].nombre << " tienes " << jugadores[i].saldo << " €\n";

          while (true)
          {
            cout << string (jugadores[i].nombre) + ", ¿desea apostar(1) o retirarse (2)?\n";
            cin >> respuesta;
            if (respuesta != 1 && respuesta != 2) {
              cout << "La respuesta debe ser 1 o 2\n";
            }
            else
            {
              //aqui la respuesta ya es 1 o 2
              if (respuesta == 2)
              {
                // se retira
                jugadores[i].retirado = 1;
              }
              //en cualquier caso, ya sea 1 o 2, se sale del while
              break;
            }

          }

          if (jugadores[i].retirado == 1)  {
            cout << "Adios y gracias por jugar \n";
          }
          else //procesamos la apuesta, que es la respuesta del bucle anterior

          {
            //quiere apostar

            while (true)
            {
              cout << "Apostar a número(1) o a color (2)?\n";
              cin >> tipo_apuesta;
              if (tipo_apuesta != 1 && tipo_apuesta != 2) {
                cout << "La respuesta debe ser 1 o 2\n";
              }
              else
              {
                break;
              }
            }


            if (tipo_apuesta == 1) {
              //numero
              while (true)
              {
                cout << "Apueste por un número entre el 1 y el 36\n";
                cin >> respuesta_apuesta;
                if (respuesta_apuesta < 1 || respuesta_apuesta > 36){
                  cout << "Apuesta no válida\n";
                }
                else
                {
                  break;
                }
              }
            }
            else
            {
              //color
              while (true)
              {
                cout << "Apueste por un color: negro (1) o rojo (2)\n";
                cin >> respuesta_apuesta;
                if (respuesta_apuesta != 1 && respuesta_apuesta != 2) {
                  cout << "Apuesta no válida\n";
                }
                else
                {
                  break;
                }
              }

            }



            while (true)
            {

              cout << "¿Cuánto desea apostar?:\n";
              cin >> cantidad_apostada;
              if (cantidad_apostada > jugadores[i].saldo)
              {
                cout << "No tiene suficiente dinero\n";
              }

              else {
                break;
              }

            }

            //finalmente, guardar la apuesta

            apuesta_actual[i].tipo_apuesta = tipo_apuesta ;//color o número
            apuesta_actual[i].apuesta = respuesta_apuesta;//
            apuesta_actual[i].dinero_apostado = cantidad_apostada;





          }

        }

      }
    }

    //si hay jugadores activos o apuestas activas, sorteo
    //jugador activo es cuando NO está retirado y tiene saldo




    //apuesta activa es cuando dinero_apostado > 0 , por ejemplo
    //comprobar si hay apuestas

    hay_apuestas_Activas = 0;
    for (i=0; i < numero_jugadores; i++) {
      if (apuesta_actual[i].dinero_apostado > 0) {
        hay_apuestas_Activas = 1;
        break;
      }

    }
    //si hay apuestas activas, vamos a hacer el resumen de las ap

    //resumen de las apuestas

    //recorrer las apuestas, y para las que tengan dinero apostado, mostrar la apuesta:
    for (i=0; i < numero_jugadores; i++) {
      if (apuesta_actual[i].dinero_apostado > 0) {
        //ver el tipo de apuesta. Si es a numero, vale directamente apuesta_actual.apuesta, porque ya el el número apostado
        //en caso de tipo_apuesta a color, poner en una cadena el valor 'negro' o 'rojo' en funcion de lo que se haya guardado, que es un 1 o un 2

        if (apuesta_actual[i].tipo_apuesta == 1){
          //apuesta a número, vale la apuesta directamente
          esta_apuesta = to_string (apuesta_actual[i].apuesta);

        }
        else{
          //apuesta a color por lo tanto hay que definir al 1 o al 2 de antes como el color

          if(apuesta_actual[i].apuesta == 1){
            //lo convertimos al negro
            esta_apuesta = "negro";
          }
          else{
            //lo convcertimos al rojo
            esta_apuesta = "rojo";
          }
        }
        cout << jugadores[i].nombre << " ha apostado " << to_string (apuesta_actual[i].dinero_apostado) << " € al " << esta_apuesta << "\n";
      }

    }





    //sorteo
      //randomize




      /* initialize random seed: */
      srand (time(NULL));

      /* generate secret number between 1 and 10: */
      numero_ganador = rand() % 37;
      color_ganador = numero_ganador % 2;



      //vemos si es impar o par para ver el color
      if(numero_ganador == 0){  //caso especial, 0 gana la banca
        cout << "Ha salido 0. El dinero se lo lleva la banca, habeis perdido\n";
        color_ganador = -1 ;
      }
      else  //funcionamiento normal
      {
        if(numero_ganador % 2 == 0){
          color_resultado = " (rojo)";
        }
        else{
          color_resultado = " (negro)";
        }
        cout << "El numero ganador es el " << numero_ganador << color_resultado << "\n";

      }



    //comprobar las apuestas




    //perdidas y ganancias
    //si gana, aumentar el saldo del jugador
    //recorrer las apuestas, y si gana subir dinero
    //si pierde, diminuir el saldo del jugador con la cantidad apostada
    //recorrer las apuestas, y si pierde se queda con su dinero


    //esto se recorre las apuestas de todos los jugadores
    resultado_apuesta = "";
    resultado_retirado = "";
    resultado_arruinado = "";
    resultado_dinero = "";
    for (i = 0 ; i < numero_jugadores; i ++)
    {
      //ver si es una apuesta activa (es decir, si el jugador ha apostado algo de dinero)
      if (apuesta_actual[i].dinero_apostado > 0) {
        //le restamos ya la apuesta que ha realizado
        jugadores[i].saldo = jugadores[i].saldo - apuesta_actual[i].dinero_apostado;

      if(numero_ganador > 0){
          //solo comprueba las apuestas si no ha ganado la banca y no tiene sentido comprobarlas si ha ganado la banca


          //ver el tipo de apuesta
          if(apuesta_actual[i].tipo_apuesta == 1){
            //con esto nos referimos cuando apuesta a numero
            //ver si ha ganado/perdido
            if(numero_ganador == apuesta_actual[i].apuesta){
              //si ha ganado, darle las ganacias, incrementando el saldo
              //incrementamos las ganancias debido a que ha acertado y lo multiplicamos por 35
              ganancias_numero = apuesta_actual[i].dinero_apostado* 35;
              //se lo añadimos a su saldo
              jugadores[i].saldo = ganancias_numero + jugadores[i].saldo;

              resultado_apuesta  = resultado_apuesta + "El jugador nº " + to_string (i + 1) + " ha ganado " + to_string(ganancias_numero) + "\n";
            }
            else
            {
              resultado_apuesta  = resultado_apuesta + "El jugador nº " + to_string (i + 1) + " ha perdido" + "\n";
            }

          }
          //ahora nos vamos a referir que apuesta a color
          else{


            //priemro vemos si la apuesta realizada es negro o rojo
            //negro=impar y rojo = par
            //un  numero es par si su resto es 0 al ser dividido entre 2

            if(color_ganador == 0){
              //esto signifa que es de color rojo
              if(apuesta_actual[i].apuesta == 2){
                //significa que ha ganado y doblamos sus ganancias
                ganancias_color = apuesta_actual[i].dinero_apostado*2;
                jugadores[i].saldo = ganancias_color + jugadores[i].saldo;
                resultado_apuesta  = resultado_apuesta + "El jugador nº " + to_string (i + 1) + " ha ganado " + to_string(ganancias_color) + "\n";
              }
              else
              {
                resultado_apuesta  = resultado_apuesta + "El jugador nº " + to_string (i + 1) + " ha perdido" + "\n";
              }


            }
            else{
              //esto significa que es de color negro
              if(apuesta_actual[i].apuesta == 1){
                //significa que ha ganado el negro y doblamos sus ganancias
                int ganancias_color;
                ganancias_color = apuesta_actual[i].dinero_apostado*2;
                jugadores[i].saldo = ganancias_color + jugadores[i].saldo;
                resultado_apuesta  = resultado_apuesta + "El jugador nº " + to_string (i + 1) + " ha ganado " + to_string(ganancias_color) + ".\n";
              }
              else
              {
                resultado_apuesta  = resultado_apuesta + "El jugador nº " + to_string (i + 1) + " ha perdido.\n";
              }


            }


          }
        }
      }
      //almacenar en otra cadena el estado de cada jugador para enseñarlo después del resumen y antes de preguntar si quieren jugar otra vez
      if(jugadores[i].retirado == 1){
      //esto quiere decir que se ha retirado el jugador
        resultado_retirado = resultado_retirado + "Eljugador nº "
          + to_string(i + 1) + " se ha retirado con "  + to_string(jugadores[i].saldo) + " €.\n";
      }
      //ahora almacenamos aquellos que se han arruinado
        else if(jugadores[i].saldo == 0 ){
          resultado_arruinado = resultado_arruinado + "Eljugador nº " + to_string(i + 1) + " se ha arruinado.\n";

        }
      else{
      //esto quiere decir que aquellos que han jugado y siguen teniendo dinero les aparece el dinero q tienen
        resultado_dinero = resultado_dinero + "Eljugador nº " + to_string(i + 1) + " tiene " + to_string(jugadores[i].saldo) + " €.\n";
        }

    }


    //los mostramos por pantalla
    cout << resultado_apuesta;
    cout << resultado_retirado;
    cout << resultado_arruinado;
    cout << resultado_dinero;


    //ver si hay que seguir jugando o si no, hacer el break del while (true)

    //voy a mirar la suma de los arruinados y los retirados
    //voy a declarar una variable para los jugadores retirados

    //se crea una variabkle para los arruinados que tiene  saldo 0
    jugadores_arruinados = 0;
    jugadores_fuera = 0;
    jugadores_retirados = 0;
    //se usa el for para ver aquellos juagdores que se han arruinados y los retirados
    for (i = 0 ; i < numero_jugadores; i ++){
      if(jugadores[i].saldo == 0){
      //ahqui cada jugador arruinado se va sumando debidpo a que su saldo es 0
        jugadores_arruinados=  jugadores_arruinados+ 1;
      }
      //aqui se ve los jugadores que se han retirado
        if(jugadores[i].retirado == 1){
        //aki hacemos la cuenta de los retirados
        jugadores_retirados = jugadores_retirados + 1;
      }
    }
    //aki se ven los jugadores q se han ido o bien por que se han retirado o porq se han arruinado
    jugadores_fuera = jugadores_retirados + jugadores_arruinados;

    if(jugadores_fuera <4){
      //si no s sigue jugando debido a que hay menos de 4 jugadores
        cout << "Continua la partida\n";

      }
      else{
        cout << "Se ha terminado la partida. Gracias por jugar!\n";
        break;
      }

  }

}
