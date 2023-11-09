#include <iostream>
#include "queue.h"
#include "tipodato.h"
#include <array>
#include <vector>

using namespace std;
int tiempo_nuevo_cliente_min = 20;
int tiempo_nuevo_cliente_max = 60;
int tiempoPagarmin = 30;
int tiempoPagarMax = 90;
int ClientesActivarCaja = 8;
int ClientesDesactivarCaja = 2;
int cajas_iniciales = 5;

int tiempo_simulacion = 2000; //segundos simulados
int rango_tiempo_nuevo_cliente = tiempo_nuevo_cliente_max - tiempo_nuevo_cliente_min;
int rango_tiempo_pagar = tiempoPagarMax - tiempoPagarmin;
struct str_log {
    int tiempo;
    int esperando;
    int atendidos;
};
//str_log log_sistema[20];
struct str_caja {
    queue cola;
    int cliente_actual;
    int tiempo_entrada;
    int tiempo_salida;
};
//str_caja array_cajas[20];
vector <str_log> log_sistema{};
vector<str_caja> array_cajas{};

int f_tiempo_nuevo_cliente()
 /* aleatorio entre tiempoNuevoClienteDesde y tiempoNuevoClienteHasta*/
 {
    return tiempo_nuevo_cliente_min + rand() % rango_tiempo_nuevo_cliente;
 }

int f_calcular_tiempo_en_pagar()//Numero aleratorio entre tiempo_pagar_min y tiempo_pagar_max
{
return tiempoPagarmin + rand() % rango_tiempo_pagar;
}

array <queue,20> array_colas;
void f_cliente_nuevo_a_cola(array <queue,20> array_colas, int cliente_id, int modo_aleatorio)
{
    int numero_de_colas = array_colas.size();
    int cola_elegida = -1;
    int size_minimo = -1;

    if (numero_de_colas == 1)  //va a esa cola
    {
        cola_elegida = 0;

    } else

    {
    if (modo_aleatorio == 1 )
        { //rand
            cola_elegida = rand() % numero_de_colas;
        }
        else  //cola mas corta
        { //cola mas corta
            for (int k=0;k<numero_de_colas; k++)
            {
                int este_size ;
                este_size =  array_colas[k].size();
                //si este_size es 0, nos podemos salir ya
                if (este_size== 0)
                    break;
                else
                    if(k == 0){
                        size_minimo =este_size;
                        cola_elegida = 0;
                    }
                        else if(este_size < size_minimo )
                        {
                            cola_elegida = k;
                            size_minimo= este_size;
                        }
                        else{

                        }
            }
        }
        // cola_alegida es donde hay que meter a cliente_id
    }
    array_colas[cola_elegida].push(cliente_id);

}
void f_comprobar_entradas_a_caja( int t ,int cajas_actuales)
{
    int cliente_id;
    int tarda;

for (int i=0; i<cajas_actuales; i++)
{
    //ver si la caja está libre en este momento y si es asi, mandar un cliente desde la caja
    if (array_cajas[i].cliente_actual == 0 )//no hay nadie
    {	//ver si hay alguien esperando y atenderlo
        if (array_cajas[i].cola.size() > 0)
        {
        //pedirle el cliente a la cola
        cliente_id = array_cajas[i].cola.front().getTipoDato();
        array_cajas[i].cola.pop();
        array_cajas[i].cliente_actual = cliente_id;
        array_cajas[i].tiempo_entrada = t;
        tarda = f_calcular_tiempo_en_pagar();
        array_cajas[i].tiempo_salida = t + tarda;


        }
    }
}
}
int f_comprobar_salidas_de_caja(int tiempo_actual) //recorrer las cajas y ver si el tiempo actual es el tiempo de salida
{
    int clientes_out = 0;
    for (int i= 0; i < cajas_iniciales; i++)
    {
    if (array_cajas[i].tiempo_salida == tiempo_actual)
        {
        array_cajas[i].cliente_actual = 0;
        array_cajas[i].tiempo_entrada= 0;
        array_cajas[i].tiempo_salida= 0	;
        clientes_out ++;

        }
    }
    return clientes_out;
}
int f_esperando_en_colas(array <queue,20> array_colas ,int numero_colas)
{
    int cont_total;
cont_total = 0;
for (int j=0;j<numero_colas;j++)
{
    int a;
    a = array_colas[j].size();
    cont_total += a;

}
return cont_total;
}
void f_log_sistema( vector <str_log> log_sistema,int t,int total_atendidos ,int esperando_ahora)
{


    str_log log = { t,esperando_ahora, total_atendidos};
    log_sistema.push_back(log);
    /*

    log_sistema[t].tiempo = t;
    log_sistema[t].esperando = esperando_ahora;
    log_sistema[t].atendidos = total_atendidos;
    */
}
void f_crear_cajas(vector <str_caja>array_cajas ,int cajas_actuales, int numero_colas){
    str_caja cajas;
            cajas.cliente_actual = 0;
            cajas.tiempo_entrada = 0;
            cajas.tiempo_salida = 0;
            if(numero_colas== 1){
            for(int i; i < cajas_actuales; i ++){
                array_cajas.push_back(cajas);
            }
            queue cola;

            }
            else{
                for(int i; i < cajas_actuales; i ++){
                    array_cajas.push_back(cajas);
                    queue cola[i];
                }

            }
}
/*
  IMPORTANTE---------------------------------------------------------------------------------------------------------------------------------------------
meter una caja nueva en el sistema de cola unica de las cajas
con lo cual meter una caja
meter una caja mas en el array de cajas
solo ucuando el modo_aleatoriooo sea el 2 ya que solo es en caso de cola unica
funcion fuer del main
if dentro del main con el modo_aleatoriooo
  IMPORTANTE-----------------------------------------------------------------------------------------------------------------------------------------------
  */

int main()
{

    cout << "Quiere que los clientes se muevan a cajas aleatorias o no? Elija uno de los dos numeros." << endl;
    cout << "1. Si" << endl;
    cout << "2. No" << endl;
    int modoo_aleatorio;
    cin >> modoo_aleatorio;
    cout << "Con cuantas cajas quieres empezar?" << endl;
    int cajas_actuales;
    cin >> cajas_actuales;
    cout << "El sistema es de cola_unica o hay varias colas?" << endl;
    cout << "1. Cola unica" << endl;
    cout << "2. Varias colas" << endl;
    int numero_colas;
    cin >> numero_colas;
    if(numero_colas == 1){
        numero_colas = 1;
    }
    if(numero_colas == 2){
        numero_colas = cajas_actuales;
    }

    f_crear_cajas(array_cajas, cajas_actuales,numero_colas);


    for ( int i= 0; i < cajas_iniciales; i++)
    {
        array_cajas[i].cola = array_colas[0];
        array_cajas[i].cliente_actual = 0;

    }
    int tiempo_nuevo_cliente = 0;
    int cliente_id  = 0;
    //Configuracion de las cajas y las colas
    int clientes_atendidos_ahora = 0;
    int total_atendidos = 0;
    int esperando_ahora = 0;

    tiempo_nuevo_cliente = f_tiempo_nuevo_cliente();

    for (int t=0;t< tiempo_simulacion; t++)
    {
        if (tiempo_nuevo_cliente == t) //si es el momento en el que llega otro cliente
        {
            cliente_id ++;
            //meterlo en la cola que sea
            f_cliente_nuevo_a_cola(array_colas,cliente_id,modoo_aleatorio) ;
            //ver cuando llega el siguiente cliente
            tiempo_nuevo_cliente = f_tiempo_nuevo_cliente() + t ;//para generar el siguiente cliente
        }



        f_comprobar_entradas_a_caja( t,cajas_actuales);

        clientes_atendidos_ahora = f_comprobar_salidas_de_caja(t);
        total_atendidos +=clientes_atendidos_ahora;

        //en cada momento, almacenar los clientes ya atendidos y en espera

        esperando_ahora = f_esperando_en_colas(array_colas, numero_colas);


        f_log_sistema(log_sistema,  t,total_atendidos ,esperando_ahora) ;





    }

}
