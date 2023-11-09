//
// Created by David Arévalo on 12/7/22.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 * Define una función recursiva que sirva para invertir un numero
 * (pasado por parámetro en formado decimal como entero), sin usar strings.
 */
int fun(int num){
    int inv = 0;
    while( num != 0){
        inv *= 10;
        inv += num % 10;
        num /= 10;
    }
    return inv;
}



/*
 * Dado el siguiente código de una TAD no lineal, explicar qué hace esta función, línea por línea.
 * Incluye dibujos del TAD con los elementos necesarios para explicarlo.
 * [¿Qué TAD es? ¿Cómo se llamaría esta función? Justifica la respuesta]

           Node * TAD::func(const int key, Node * node) {
            if(key < node->getKey()){
                if(node->getLeft()){
                    return func (key, node->getLeft()); }else{
                    node->setLeft(new Node{key});
                    return node->getLeft();
                }
            }else{
                if(node->getRight()){
                    return func(key, node->getRight()); }else{
                    node->setRight(new Node{key});
                    return node->getRight();
                }
            }
        }
*/
/*
 * El TAD es un arbol binario. La funcion introduce nuevos nodos al arbol.
 */



/*
 *TADs lineales: qué tipos existen y cuáles son sus diferencias. Incluye dibujos.
 */
/*
 * Listas: Coleccion de elementos que tienen una posicion asignada (puede haber repetidos).
 * Pueden ser enlazadas simples o doblemente enlazadas.
 *
 * Pilas: Contenedor de objetos que son insertados y eliminados de acuerdo con el
 * principio de que el último en entrar es el primero en salir.
 *
 * Colas: Es similar a la lista, con la diferencia de que es una estructura de datos
 * FIFO, es decir, primero en entrar es el primero en salir, mientras que una lista es
 * una estructura de datos LIFO, es decir, ultimo en entrar, primero en salir.
 */



/*
 * ¿Que hace el siguiente codigo?¿Que tipo de algoritmo es?¿Cual es su complejidad temporal?
 * Indicar qué tipo de notación se utiliza, y el significado de la misma.
 */
void func (vector<int> & a) {
    for (int i = 0; i < a.size() - 1; i++) {
        int vectMin = i;
        for (int j = i + 1; j < a.size(); j++) {
            if(a[j] < a[vectMin]) {
                vectMin = j;
            }
        }
        int temp = a[i];
        a[i] = a[vectMin]; a[vectMin] = temp;
    }
}
/*
 * La funcion recibe un vector de enteros pasado por referencia como parametro, el cual se recorre
 * con un bucle 'for'. Se crea una variable entera igual al valor de 'i'. Si el valor del vector
 * 'a' en la posicion 'j' es menor al valor del vector 'a' en la posicion 'inMin', este ultimo es
 * igual a 'j'.
 * Es el algoritmo Selection Sort.
 * Su complejidad es O(n^2)
 */



/*
 * TADs no lineales: qué tipos existen y cuáles son sus diferencias.
 */
/*
 * Arbol: Es un TAD que consta de un nodo raiz y de un conjunto de subarboles formados por nodos
 * padres e hijas.
 *
 * Arbol Binario: Es un árbol que, o bien está vacío, o bien consta de un nodo raíz con dos
 * subárboles binarios, denominados derecho e izquierdo.
 *
 * Monticulo: Es un árbol binario completo cuyos nodos almacenan elementos comparables, donde
 * cualquier nodo es menor que sus descendientes.
 */
