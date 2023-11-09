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

struct apuesta {
    int tipo_apuesta; //numero o color
    int apuesta; //qué número o qué color
    int dinero_apostado; //money
};


struct apuesta apuesta_actual[4];
//numero ganador
int sorteo_ruleta()
{
    //creamos el nuemro aleatoria de laa ruleta
    return  rand() % 37;
}
int funcion_saldo_banca(struct jugador array_jugadores[], int saldo_inicial_total){
  int i;
  int saldo_banca = 200;
  int saldo_final_jugadores = 0;
  //voy a hacer una resta en la que el dinero de la banca valga el dinero de los jugadores totales - el dinero q se va cada uno
  for(i=0; i< numero_jugadores; i++){
    saldo_final_jugadores = saldo_final_jugadores +
      array_jugadores[i].saldo;
  }

saldo_banca = saldo_banca + saldo_inicial_total - saldo_final_jugadores;

 return saldo_banca ;
}

//color ganador
int color_ganador_funcion(int num_gana){
     //devuelve el resto del numero ganador
     int color_ganador;
      if(num_gana == 0){  //caso especial, 0 gana la banca
        color_ganador = -1 ;
      }
      else{
        color_ganador = num_gana %2;
      }
      return color_ganador;
}
//ganancias
int ganancias_funcion (int tipo_apuesta, int dinero_apostado){
//tipo_apuesta es 1 numero 2 color
  if(tipo_apuesta == 1){
   return dinero_apostado*35;
  }
  else{
    return dinero_apostado*2;
  }
}
int inicializa_jugadores (struct jugador array_jugadores[])
{
  int i ;
  for(i = 0; i < 4; i++){
    array_jugadores[i].nombre = "Jugador  " +  to_string(i + 1) ;
    array_jugadores[i].saldo = saldo_inicial;
    array_jugadores[i].retirado = 0;
  }
return 1;
}
//apostar
int apuesta_funcion (struct apuesta array_apuesta[], struct jugador array_jugadores[])
{
  int i;
  int respuesta;
  int tipo_apuesta;
  int respuesta_apuesta;
  int cantidad_apostada;
 for (i=0; i < numero_jugadores; i++) {
    //reset a la información de la apuesta de este jugador
      array_apuesta[i].tipo_apuesta = 0 ;//color o número
      array_apuesta[i].apuesta = 0;//
      array_apuesta[i].dinero_apostado = 0;
    // cout << "i en el bucle principal " << i << "\n";
//si está retirado O ARRUINADO , no hacer nada. Así que tiene q estar no retirado
        if (array_jugadores[i].retirado == 0 && array_jugadores[i].saldo > 0){
          //preguntar si quiere apostar  si quiere retirarse

          //primero enseñamos el dinero inicial de cada uno
          cout <<array_jugadores[i].nombre << " tienes " << array_jugadores[i].saldo << " €\n" << "-------------------------\n";

          while (true)
          {
            cout << string (array_jugadores[i].nombre) + ", ¿desea apostar(1) o retirarse (2)?\n";
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
                array_jugadores[i].retirado = 1;
              }
              //en cualquier caso, ya sea 1 o 2, se sale del while
              break;
            }
          }
          if (array_jugadores[i].retirado == 1)  {
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
              if (cantidad_apostada > array_jugadores[i].saldo)
              {
                cout << "No tiene suficiente dinero\n";
              }
              else {
                break;
              }
            }
            //finalmente, guardar la apuesta
            array_apuesta[i].tipo_apuesta = tipo_apuesta ;
            //color o número
            array_apuesta[i].apuesta = respuesta_apuesta;
            array_apuesta[i].dinero_apostado = cantidad_apostada;
          }
      }
    }
    return 1;
}

int resumen_apuesta_funcion(struct apuesta array_apuesta[], struct jugador array_jugadores[])
{
  int i;
  string esta_apuesta;
  for (i=0; i < numero_jugadores; i++) {
      if (array_apuesta[i].dinero_apostado > 0) {
        //ver el tipo de apuesta. Si es a numero, vale directamente apuesta_actual.apuesta, porque ya el el número apostado
        //en caso de tipo_apuesta a color, poner en una cadena el valor 'negro' o 'rojo' en funcion de lo que se haya guardado, que es un 1 o un 2
        if (array_apuesta[i].tipo_apuesta == 1){
          //apuesta a número, vale la apuesta directamente
          esta_apuesta = to_string (array_apuesta[i].apuesta);
        }
        else{
          //apuesta a color por lo tanto hay que definir al 1 o al 2 de antes como el color

          if(array_apuesta[i].apuesta == 1){
            //lo convertimos al negro
            esta_apuesta = "negro";
          }
          else{
            //lo convcertimos al rojo
            esta_apuesta = "rojo";
          }
        }
        cout << array_jugadores[i].nombre << " ha apostado " << to_string (array_apuesta[i].dinero_apostado) << " € al " << esta_apuesta << "\n";
      }
    }
 return 1;
}
int apuestas_activas_funcion(struct apuesta array_apuesta[])
{
  int hay_apuestas_Activas;
  int i;
    hay_apuestas_Activas = 0;
    for (i=0; i < numero_jugadores; i++) {
      if (apuesta_actual[i].dinero_apostado > 0) {
        hay_apuestas_Activas = 1;
        break;
      }
    }
    return hay_apuestas_Activas;
}
int mostrar_numero_ganador(struct apuesta array_apuesta[], struct jugador array_jugadores[],int numero_ganador , int color_ganador )
{
  int i;
  string color_resultado;
   if(numero_ganador == 0){  //caso especial, 0 gana la banca
        cout << "Ha salido 0. El dinero se lo lleva la banca, habeis perdido\n";
   }
      else  //funcionamiento normal
      {
        if(color_ganador == 0){
          color_resultado = " (rojo)";
        }
        else{
          color_resultado = " (negro)";
        }
        cout << "El numero ganador es el " << numero_ganador << color_resultado << "\n";
      }
      return 1;
}
int sumar_ganancias_funcion(struct jugador array_jugadores[] ,struct apuesta array_apuestas[],int numero_ganador, int color_ganador){
  int i;
  int ganancias_color;
  int ganancias_numero;
  string resultado_apuesta;
  string resultado_retirado;
  string resultado_arruinado;
  string resultado_dinero;
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
              ganancias_numero = ganancias_funcion(apuesta_actual[i].tipo_apuesta, apuesta_actual[i].dinero_apostado);
              //se lo añadimos a su saldo
              jugadores[i].saldo = ganancias_numero + jugadores[i].saldo;
              resultado_apuesta  = resultado_apuesta + "El jugador nº " + to_string (i + 1) + " ha ganado " + to_string(ganancias_numero) + "\n";
            }
            else
            {
              resultado_apuesta  = resultado_apuesta + "El jugador nº " + to_string (i + 1) + " ha perdido lo apostado" + "\n";
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
                ganancias_color = ganancias_funcion(apuesta_actual[i].tipo_apuesta, apuesta_actual[i].dinero_apostado);
                jugadores[i].saldo = ganancias_color + jugadores[i].saldo;
                resultado_apuesta  = resultado_apuesta + "El jugador nº " + to_string (i + 1) + " ha ganado " + to_string(ganancias_color) + "\n";
              }
              else
              {
                resultado_apuesta  = resultado_apuesta + "El jugador nº " + to_string (i + 1) + " ha perdido lo apostado" + "\n";
              }
            }
            else{
              //esto significa que es de color negro
              if(apuesta_actual[i].apuesta == 1){
                //significa que ha ganado el negro y doblamos sus ganancias
                ganancias_color = ganancias_funcion(apuesta_actual[i].tipo_apuesta, apuesta_actual[i].dinero_apostado);

                jugadores[i].saldo = ganancias_color + jugadores[i].saldo;
                resultado_apuesta  = resultado_apuesta + "El jugador nº " + to_string (i + 1) + " ha ganado " + to_string(ganancias_color) + ".\n";
              }
              else
              {
                resultado_apuesta  = resultado_apuesta + "El jugador nº " + to_string (i + 1) + " ha perdido lo apostado.\n";
              }
            }
          }
        }
      }
      //almacenar en otra cadena el estado de cada jugador para enseñarlo después del resumen y antes de preguntar si quieren jugar otra vez
      if(jugadores[i].retirado == 1){
      //esto quiere decir que se ha retirado el jugador
        resultado_retirado = resultado_retirado + "El jugador nº "
          + to_string(i + 1) + " se ha retirado con "  + to_string(jugadores[i].saldo) + " €.\n";
      }
      //ahora almacenamos aquellos que se han arruinado
      else if(jugadores[i].saldo == 0 ){
          resultado_arruinado = resultado_arruinado + "El jugador nº " + to_string(i + 1) + " se ha arruinado.\n";
        }
      else{
      //esto quiere decir que aquellos que han jugado y siguen teniendo dinero les aparece el dinero q tienen
        resultado_dinero = resultado_dinero + "El jugador nº " + to_string(i + 1) + " tiene " + to_string(jugadores[i].saldo) + " €.\n";
        }
    }
    //los mostramos por pantalla
    cout << resultado_apuesta;
    cout << resultado_retirado;
    cout << resultado_arruinado;
    cout << resultado_dinero;

    return 1;
}
int seguir_jugando_funcion(struct jugador array_jugadores[]  )
{
  int i;
  int jugadores_fuera;
  int jugadores_retirados;
  int jugadores_arruinados;
  int continua;

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
        continua = 1;
      }
      else{
        cout << "Se ha terminado la partida. Gracias por jugar!\n";
        continua = 0;
      }
      return continua;
}
int main() {
  int hay_que_continuar = 0;
  int hay_apuestas_Activas = 0;
  int  numero_ganador = 0;
  int  color_ganador = 0;
  int saldo_final_banca ;
  int ganancias_banca;
  string resultado_apuesta;
  string resultado_retirado;
  string resultado_arruinado;
  string resultado_dinero;
  srand (time(NULL));
  //inicializamos los jugadores
inicializa_jugadores (jugadores) ;
 // numero_jugadores;
 // casillas_ruleta;
  while (true){
  apuesta_funcion(apuesta_actual , jugadores);
//apostar:
    //si hay jugadores activos o apuestas activas, sorteo
    //jugador activo es cuando NO está retirado y tiene saldo
    //apuesta activa es cuando dinero_apostado > 0 , por ejemplo
    //comprobar si hay apuestas
    hay_apuestas_Activas = apuestas_activas_funcion(apuesta_actual);
    //si hay apuestas activas, vamos a hacer el resumen de las ap
    //resumen de las apuestas
    //recorrer las apuestas, y para las que tengan dinero apostado, mostrar la apuesta:
    resumen_apuesta_funcion(apuesta_actual , jugadores);
    //sorteo
      //randomize
      numero_ganador = sorteo_ruleta();
      color_ganador = color_ganador_funcion(numero_ganador);
      //vemos si es impar o par para ver el color
      mostrar_numero_ganador(apuesta_actual, jugadores, numero_ganador,color_ganador );
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
    sumar_ganancias_funcion(jugadores , apuesta_actual,numero_ganador,color_ganador  );
    saldo_final_banca = funcion_saldo_banca (jugadores,numero_jugadores * saldo_inicial ) ;
    if (saldo_final_banca == 0){
     // si el saldo de la banca es cero se acaba la partida
     cout << "Se ha acabado la partida ya que la banca no tiene más dinero.\n" << "Gracias por jugar!\n";
     break;
    }
    hay_que_continuar = seguir_jugando_funcion(jugadores);
    if (hay_que_continuar == 1){

    }
    else{
      // aqui muestro por pantalla el dinero con el que ha acabado la banca
     saldo_final_banca =   funcion_saldo_banca (jugadores,numero_jugadores * saldo_inicial );
     cout << "La banca ha acabado con " << saldo_final_banca << " €\n";
      break;
    }

  }
}
