//
// Created by David Arévalo on 7/7/22.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

//Bubble Sort --> Mejor Complejidad O(n). Peor Complejidad O(n^2)
void bubbleSort(vector<int> & vec){
    for(int i = 0; i < vec.size() - 1; i++){
        for(int j = 0; j < vec.size() - 1; j++){
            if(vec[j] > vec[j + 1]){
                swap(vec[j], vec[j + 1]);
            }
        }
    }
}

//QuickSort --> Complejidad habitual O(n log n). En el peor de los casos O(n^2)
/*
 * Se elige un elemento del vector llamado pivote. Resituamos el resto de elementos a cada lado del pivote,
 * un lado queden todos los menores que él, y al otro los mayores. La lista queda separada en dos sublistas,
 * una formada por los elementos a la izquierda del pivote, y otra por los elementos a su derecha.
 * Se repite este proceso de manera recursiva hasta que esten ordenados.
 */
int partition(vector<int> & vec, int left_index, int right_index){
    auto pivote = vec.at(left_index);
    int i = left_index;
    int j = right_index;
    while(true){
        while(vec.at(i) <= pivote && i < j){
            i++;
        }
        while(vec.at(j) > pivote){
            j--;
        }
        if(i >= j){
            break;
        }
        swap(vec.at(i), vec.at(j));
    }
    swap(vec.at(left_index), vec.at(j));
    return j;
}
void quickSort(vector<int> & vec, int left_index, int right_index){
    if(left_index >= right_index){
        return;
    }
    else{
        int pivote = partition(vec, left_index, right_index);
        quickSort(vec, left_index, pivote - 1);
        quickSort(vec, pivote + 1, right_index);
    }
}
//Selection Sort --> Complejidad O(n^2)
/*
 * Se busca el mínimo elemento de la lista, se intercambia con el primero, se busca el siguiente minimo en el
 * resto de la lista y se vuelve a intercambiar con el segundo, y asi sucesivamente.e
 */
void selectionSort(vector<int> & vec){
    for(int i = 0; i < vec.size(); i++){
        int inMin = i;
        for(int j = i + 1; j < vec.size(); j++){
            if(vec[j] < vec[inMin]){
                inMin = j;
            }
        }
        swap(vec[i], vec[inMin]);
    }
};

//Merge Sort --> Complejidad O(n log n)
/*
 * Se comprueba si el tamaño de la lista es 0 o 1 pra saber si esta ya ordenada. Si no, se divide la lista
 * desordenada en dos sublistas, se ordena cada sublista recursivamente, y luego se juantan ambas listas.
 */
vector<int> merge(vector<int> const & left, vector<int> const & right){
    auto left_it = 0;
    auto right_it = 0;
    vector<int> vec;
    while(left.size() != left_it && right.size() != right_it){
        if(left[left_it] < right[right_it]){
            vec.push_back(left[left_it]);
            left_it++;
        }
        else{
            vec.push_back(right[right_it]);
            right_it++;
        }
    }
    for(int i = 0; i < left_it; i++){
        vec.push_back(left[i]);
    }
    for(int i = 0; i < right_it; i++){
        vec.push_back(right[i]);
    }
    return vec;
}
vector<int> mergeSort(vector<int> const & vec){
    if(vec.size() == 1){
        return vec;
    }
    else{
        auto middle = vec.size() / 2;
        vector<int> left{vec.begin(), vec.begin() + middle};
        vector<int> right{vec.begin() + middle, vec.begin()};

        left = mergeSort(left);
        right = mergeSort(right);

        return merge(left, right);
    }
}











