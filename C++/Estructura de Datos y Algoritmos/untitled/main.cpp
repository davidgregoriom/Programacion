#include <iostream>
#include <vector>
#include <ctime>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <algorithm>


using namespace std;


void bubble_sort(std::vector<int>& elements) {
  for (int i=0; i<elements.size()-1; i++) {  // 'n-1' iterations
    for (int k=0; k<elements.size()-1; k++) {  // 'n-1' iterations
      if (elements[k] > elements[k+1]) { // compare adyacent values
        std::swap(elements[k], elements[k+1]);
      }
    }
  }
}





void selection_sort(std::vector<int>& elements) {
  for (int i=0; i<elements.size(); i++) {  // 'n' iterations
    // Search for the minimum element in the right (unordered) section
    int indexMin = i;
    for (int k=i+1; k<elements.size(); k++) {  // 'n-i' iterations
      if (elements[k] < elements[indexMin]) { // keep index of min element
        indexMin = k;
      }
    }
    // Swap current element with the min
    std::swap(elements[i], elements[indexMin]);
  }
}



std::vector<int> merge(const std::vector<int>& lhs,
                       const std::vector<int>& rhs)
{
    std::vector<int> ret;
    auto left_iterator = 0;
    auto right_iterator = 0;

    // Iterate the two vectors at the same time, adding the lowest element
    while (left_iterator != lhs.size() && right_iterator != rhs.size()) {
        if (lhs[left_iterator] < rhs[right_iterator]) {
            ret.push_back(lhs[left_iterator]);
            left_iterator++;
        }
        else {
            ret.push_back(rhs[right_iterator]);
            right_iterator++;
        }
    }

    // Add remaining elements
    for (int i=left_iterator; i<lhs.size(); i++) {
        ret.push_back(lhs[i]);
    }
    for (int i=right_iterator; i<rhs.size(); i++) {
        ret.push_back(rhs[i]);
    }
    return ret;
}


std::vector<int> merge_sort(const std::vector<int>& elements) {
    // Check for base/trivial case
    if (elements.size() <= 1) {
        return elements;
    }
    else {
        // Split the vector in two
        auto middle = elements.size()/2;
        std::vector<int> left{elements.begin(), elements.begin() + middle};
        std::vector<int> right{elements.begin() + middle, elements.end()};

        // Apply merge_sort to each of them
        left = merge_sort(left);
        right = merge_sort(right);

        // Merge those two (already) ordered vectors
        return merge(left, right);
    }
}





// A function to compute the partition
int partition(std::vector<int>& elements, int left_index, int right_index)
{
    auto pivot = elements.at(left_index);
    int i = left_index, j = right_index;

    while(true) {
        while( elements.at(i) <= pivot && i < j ) ++i;
        while( elements.at(j) > pivot ) --j;
        if( i >= j ) break;
        std::swap(elements.at(i), elements.at(j));
    }
    std::swap(elements.at(left_index), elements.at(j));
    return j;
}


// Quick-sort algorithm
void quick_sort(std::vector<int>& elements, int left_index, int right_index) {
    // Check for base/trivial case
    if (left_index >= right_index) {
        //return;
    }
    else {
        // Compute the pivot
        int pivot_index = partition(elements, left_index, right_index);

        // Apply quick-sort to both sides (pivot is already in place)
        quick_sort(elements, left_index, pivot_index-1);
        quick_sort(elements, pivot_index+1, right_index);
    }
}

std::vector <int> insertion_Sort (std::vector<int>& elements) {
    int pos;
    int change; // Cambio de los numeros

    for (int i = 0; i <= elements.size() - 1; i++) {  // 'n-1' iterations
        pos = i;
        change = elements.at(i);

        while (pos > 0 && elements.at(pos - 1) > change) {
            elements.at(pos) = elements.at(pos - 1);
            pos--;
        }
        elements.at(pos) = change;
    }
    return elements;
}


// shellsort implementation
void shellsort(std::vector<float> elements, float num) {
    for (int gap = num/2; gap > 0; gap /= 2) {
      for (int i = gap; i < num; i += 1) {
        int temp  = elements.at(i);
        int j = 0;
        for (j = i; j >= gap && elements.at(j - gap) > temp; j -= gap) {
          elements.at(j) = elements.at(j - gap);
          elements.at(j) = temp;
        }
      }
    }
}




int main() {






    /*
    std::vector<int> elementsInsertion_SortOrdenadoInversamente = {4,2,3,1,5};

    for (auto elem: elementsInsertion_SortOrdenadoInversamente) {
        std::cout << elem << ", ";
    }

    insertion_Sort (elementsInsertion_SortOrdenadoInversamente);
    std::cout << "\n";

    for (auto elem: elementsInsertion_SortOrdenadoInversamente) {
        std::cout << elem << ", ";
    }
    */

    // AQUI ACABA. PERO NO ENTIENDO NADA DEL CODIGO



    //std::cout << "METODO DE LA BURBUJA:\n\n";
 //TODO ESTO ES LOS 4 APARTADOS CON EL METODO DE LA BURBUJA

    unsigned t0,t1;
        t0=clock();
        std::cout << "VECTOR ORDENADO INVERSAMENTE\n\n";
        std::vector<int> elementsBubble_SortVectorOrdenadoInversamente = {100,99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,83,82,81,80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65,64,63,62,61,60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};

        std::cout << "Vector inicial: ";
        for(auto elem: elementsBubble_SortVectorOrdenadoInversamente) {
            std::cout << elem << ", ";
        }
        std::cout << "\n\n";
        bubble_sort(elementsBubble_SortVectorOrdenadoInversamente);
        std::cout << "\nOrden final: ";
        for(auto elem: elementsBubble_SortVectorOrdenadoInversamente){
            std::cout << elem << ", ";
        }

        std::cout << "\n\n";
        t1=clock();
        double time_Bubble_SortVectorOrdenadoInversamente = (double(t1-t0)/CLOCKS_PER_SEC);
        std::cout << "Tiempo transcurrido del metodo de la burbuja en un vector ordenado inversamente: " << time_Bubble_SortVectorOrdenadoInversamente << " segundos\n" << "\n";

        std::cout << "-----------------------------------------------------------------------------------------\n\n\n";


        unsigned t2,t3;
            t2=clock();
            std::cout << "UN VECTOR CON TODOS SUS NUMEROS IGUALES\n\n";

        std::vector<int> elementsBubble_SortVectorNumerosIguales = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

        std::cout << "Orden inicial: ";
        for(auto elem: elementsBubble_SortVectorNumerosIguales) {
            std::cout << elem << ", ";
        }

        std::cout << "\n\n";
        bubble_sort(elementsBubble_SortVectorNumerosIguales);
        std::cout << "\nOrden final: ";
        for(auto elem: elementsBubble_SortVectorNumerosIguales){
            cout << elem << ", ";
        }

        std::cout << "\n\n";
        t3=clock();
        double time_Bubble_SortVectorNumerosIguales = (double(t3-t2)/CLOCKS_PER_SEC);
        std::cout << "Tiempo transcurrido del metodo de la burbuja en un vector con todos los numeros iguales: " << time_Bubble_SortVectorNumerosIguales << " segundos\n" << "\n";



        std::cout << "-----------------------------------------------------------------------------------------\n\n\n";




        unsigned t4,t5;
            t4=clock();
            std::cout << "UN VECTOR YA ORDENADO\n\n";

        std::vector<int> elementsBubble_SortVectorOrdenado = {1, 2, 3, 4, 5, 6, 7, 8, 9};

        std::cout << "Orden inicial: ";
        for(auto elem: elementsBubble_SortVectorOrdenado) {
            std::cout << elem << ", ";
        }

        std::cout << "\n\n";
        bubble_sort(elementsBubble_SortVectorOrdenado);
        std::cout << "\nOrden final: ";
        for(auto elem: elementsBubble_SortVectorOrdenado){
            cout << elem << ", ";
        }

        std::cout << "\n\n";
        t5=clock();
        double time_Bubble_SortVectorOrdenado = (double(t5-t4)/CLOCKS_PER_SEC);
        std::cout << "Tiempo transcurrido del metodo de la burbuja en un vector ya ordenado: " << time_Bubble_SortVectorOrdenado << " segundos\n" << "\n";


        std::cout << "-----------------------------------------------------------------------------------------\n\n\n";


        unsigned t6,t7;
            t6=clock();
            std::cout << "UN VECTOR DE NUMEROS ALEATORIOS\n\n";
        srand (time(NULL));
        std::vector <int> elementsBubble_SortVectorNumerosAleatorios = {};
         int numeroAleatorio = 0;

         for (int pos = 0; pos < 200; pos++) {
           elementsBubble_SortVectorNumerosAleatorios.push_back((rand () % 200) + 1);
         }

         std::cout << "Orden inicial: ";
         for(auto elem: elementsBubble_SortVectorNumerosAleatorios) {
             std::cout << elem << ", ";
         }

         std::cout << "\n\n";
         bubble_sort(elementsBubble_SortVectorNumerosAleatorios);
         std::cout << "\nOrden final: ";
         for(auto elem: elementsBubble_SortVectorNumerosAleatorios){
             cout << elem << ", ";
         }

         std::cout << "\n\n";
         t7=clock();
         double time_Bubble_SortVectorNumerosAleatorios = (double(t7-t6)/CLOCKS_PER_SEC);
         std::cout << "Tiempo transcurrido del metodo de la burbuja en un vector con numeros aleatorios: " << time_Bubble_SortVectorNumerosAleatorios << " segundos\n" << "\n";


         std::cout << "-----------------------------------------------------------------------------------------\n\n\n";





    std::cout << "METODO DE SELECION:\n\n";

    unsigned t8,t9;
        t8=clock();
        std::cout << "VECTOR ORDENADO INVERSAMENTE\n\n";
        std::vector<int> elementsSelection_SortVectorOrdenadoInversamente = {100,99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,83,82,81,80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65,64,63,62,61,60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};

        std::cout << "Vector inicial: ";
        for(auto elem: elementsSelection_SortVectorOrdenadoInversamente) {
            std::cout << elem << ", ";
        }
        std::cout << "\n\n";
        selection_sort(elementsSelection_SortVectorOrdenadoInversamente);
        std::cout << "\nOrden final: ";
        for(auto elem: elementsSelection_SortVectorOrdenadoInversamente){
            std::cout << elem << ", ";
        }

        std::cout << "\n\n";
        t9=clock();
        double time_Selection_SortVectorOrdenadoInversamente = (double(t9-t8)/CLOCKS_PER_SEC);
        std::cout << "Tiempo transcurrido del metodo de selecion en un vector ordenado inversamente: " << time_Selection_SortVectorOrdenadoInversamente << " segundos\n" << "\n";

        std::cout << "-----------------------------------------------------------------------------------------\n\n\n";


        unsigned t10,t11;
            t10=clock();
            std::cout << "UN VECTOR CON TODOS SUS NUMEROS IGUALES\n\n";

        std::vector<int> elementsSelection_SortVectorNumerosIguales = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

        std::cout << "Orden inicial: ";
        for(auto elem: elementsSelection_SortVectorNumerosIguales) {
            std::cout << elem << ", ";
        }

        std::cout << "\n\n";
        selection_sort(elementsSelection_SortVectorNumerosIguales);
        std::cout << "\nOrden final: ";
        for(auto elem: elementsSelection_SortVectorNumerosIguales){
            cout << elem << ", ";
        }

        std::cout << "\n\n";
        t11=clock();
        double time_Selection_SortVectorNumerosIguales = (double(t11-t10)/CLOCKS_PER_SEC);
        std::cout << "Tiempo transcurrido del metodo de selecion en un vector con todos los numeros iguales: " << time_Selection_SortVectorNumerosIguales << " segundos\n" << "\n";



        std::cout << "-----------------------------------------------------------------------------------------\n\n\n";



        unsigned t12,t13;
            t12=clock();
            std::cout << "UN VECTOR YA ORDENADO\n\n";

        std::vector<int> elementsSelection_SortVectorOrdenado = {1, 2, 3, 4, 5, 6, 7, 8, 9};

        std::cout << "Orden inicial: ";
        for(auto elem: elementsSelection_SortVectorOrdenado) {
            std::cout << elem << ", ";
        }

        std::cout << "\n\n";
        selection_sort(elementsSelection_SortVectorOrdenado);
        std::cout << "\nOrden final: ";
        for(auto elem: elementsSelection_SortVectorOrdenado){
            cout << elem << ", ";
        }

        std::cout << "\n\n";
        t13=clock();
        double time_Selection_SortVectorOrdenado = (double(t13-t12)/CLOCKS_PER_SEC);
        std::cout << "Tiempo transcurrido del metodo de selecion en un vector ya ordenado: " << time_Selection_SortVectorOrdenado << " segundos\n" << "\n";


        std::cout << "-----------------------------------------------------------------------------------------\n\n\n";



        unsigned t14,t15;
            t14=clock();
            std::cout << "UN VECTOR DE NUMEROS ALEATORIOS\n\n";
        srand (time(NULL));
        std::vector <int> elementsSelection_SortVectorNumerosAleatorios = {};


         for (int pos = 0; pos < 200; pos++) {
           elementsSelection_SortVectorNumerosAleatorios.push_back((rand () % 200) + 1);
         }

         std::cout << "Orden inicial: ";
         for(auto elem: elementsSelection_SortVectorNumerosAleatorios) {
             std::cout << elem << ", ";
         }

         std::cout << "\n\n";
         selection_sort(elementsSelection_SortVectorNumerosAleatorios);
         std::cout << "\nOrden final: ";
         for(auto elem: elementsSelection_SortVectorNumerosAleatorios){
             cout << elem << ", ";
         }

         std::cout << "\n\n";
         t15=clock();
         double time_Selection_SortVectorNumerosAleatorios = (double(t15-t14)/CLOCKS_PER_SEC);
         std::cout << "Tiempo transcurrido del metodo de selecion en un vector con numeros aleatorios: " << time_Selection_SortVectorNumerosAleatorios << " segundos\n" << "\n";


         std::cout << "-----------------------------------------------------------------------------------------\n\n\n";








 // METODO MERGE_SORT



    unsigned t16,t17;
        t16=clock();
        std::cout << "VECTOR ORDENADO INVERSAMENTE\n\n";
        std::vector<int> elementsMerge_SortVectorOrdenadoInversamente = {100,99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,83,82,81,80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65,64,63,62,61,60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};

        std::cout << "Vector inicial: ";
        for(auto elem: elementsMerge_SortVectorOrdenadoInversamente) {
            std::cout << elem << ", ";
        }
        std::cout << "\n\n";
        merge_sort(elementsMerge_SortVectorOrdenadoInversamente);
        std::cout << "\nOrden final: ";
        for(auto elem: elementsMerge_SortVectorOrdenadoInversamente){
            std::cout << elem << ", ";
        }

        std::cout << "\n\n";
        t17=clock();
        double time_Merge_SortVectorOrdenadoInversamente = (double(t17-t16)/CLOCKS_PER_SEC);
        std::cout << "Tiempo transcurrido del metodo de ordenamiento por mezcla en un vector ordenado inversamente: " << time_Merge_SortVectorOrdenadoInversamente << " segundos\n" << "\n";

        std::cout << "-----------------------------------------------------------------------------------------\n\n\n";


        unsigned t18,t19;
            t18=clock();
            std::cout << "UN VECTOR CON TODOS SUS NUMEROS IGUALES\n\n";

        std::vector<int> elementsMerge_SortVectorNumerosIguales = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

        std::cout << "Orden inicial: ";
        for(auto elem: elementsMerge_SortVectorNumerosIguales) {
            std::cout << elem << ", ";
        }

        std::cout << "\n\n";
        merge_sort(elementsMerge_SortVectorNumerosIguales);
        std::cout << "\nOrden final: ";
        for(auto elem: elementsMerge_SortVectorNumerosIguales){
            cout << elem << ", ";
        }

        std::cout << "\n\n";
        t19=clock();
        double time_Merge_SortVectorNumerosIguales = (double(t19-t18)/CLOCKS_PER_SEC);
        std::cout << "Tiempo transcurrido del metodo de selecion en un vector con todos los numeros iguales: " << time_Merge_SortVectorNumerosIguales << " segundos\n" << "\n";



        std::cout << "-----------------------------------------------------------------------------------------\n\n\n";

    unsigned t20,t21;
        t20=clock();
        std::cout << "UN VECTOR YA ORDENADO\n\n";

    std::vector<int> elementsMerge_SortOrdenado = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << "Orden inicial: ";
    for(auto elem: elementsMerge_SortOrdenado) {
        std::cout << elem << ", ";
    }

    std::cout << "\n\n";
    merge_sort(elementsMerge_SortOrdenado);
    std::cout << "\nOrden final: \n";
    for(auto elem: elementsMerge_SortOrdenado){
        std::cout << elem << ", ";
    }

    std::cout << "\n---\n";
    t21 = clock();
    double time_Merge_SortOrdenado = (double(t21-t20)/CLOCKS_PER_SEC);
    std::cout << "Tiempo transcurrido del metodo de ordenamiento por mezcla en un vector ya ordenado: " << time_Merge_SortOrdenado << " segundos\n" << "\n";

    std::cout << "-----------------------------------------------------------------------------------------\n\n\n";


    unsigned t22,t23;
        t22=clock();
        std::cout << "UN VECTOR DE NUMEROS ALEATORIOS\n\n";
    srand (time(NULL));
    std::vector <int> elementsMerge_SortVectorNumerosAleatorios = {};


     for (int pos = 0; pos < 200; pos++) {
       elementsMerge_SortVectorNumerosAleatorios.push_back((rand () % 200) + 1);
     }

     std::cout << "Orden inicial: ";
     for(auto elem: elementsMerge_SortVectorNumerosAleatorios) {
         std::cout << elem << ", ";
     }

     std::cout << "\n\n";
     elementsMerge_SortVectorNumerosAleatorios = merge_sort(elementsMerge_SortVectorNumerosAleatorios);
     std::cout << "\nOrden final: ";
     for(auto elem: elementsMerge_SortVectorNumerosAleatorios){
         std::cout << elem << ", ";
     }

     std::cout << "\n\n";
     t23=clock();
     double time_Merge_SortVectorNumerosAleatorios = (double(t23-t22)/CLOCKS_PER_SEC);
     std::cout << "Tiempo transcurrido del metodo de selecion en un vector con numeros aleatorios: " << time_Merge_SortVectorNumerosAleatorios << " segundos\n" << "\n";


     std::cout << "-----------------------------------------------------------------------------------------\n\n\n";







    //std::cout << "\n\n\n\n\n\n";



    unsigned t24,t25;
        t24=clock();
        std::cout << "VECTOR ORDENADO INVERSAMENTE\n\n";
        std::vector<int> elementsQuick_SortVectorOrdenadoInversamente = {100,99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,83,82,81,80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65,64,63,62,61,60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};

        std::cout << "Vector inicial: ";
        for(auto elem: elementsQuick_SortVectorOrdenadoInversamente) {
            std::cout << elem << ", ";
        }
        std::cout << "\n\n";
        quick_sort(elementsQuick_SortVectorOrdenadoInversamente, 0, elementsQuick_SortVectorOrdenadoInversamente.size()-1);
        std::cout << "\nOrden final: ";
        for(auto elem: elementsQuick_SortVectorOrdenadoInversamente){
            std::cout << elem << ", ";
        }

        std::cout << "\n\n";
        t25=clock();
        double time_Quick_SortVectorOrdenadoInversamente = (double(t25-t24)/CLOCKS_PER_SEC);
        std::cout << "Tiempo transcurrido del metodo de ordenamiento por mezcla en un vector ordenado inversamente: " << time_Quick_SortVectorOrdenadoInversamente << " segundos\n" << "\n";

        std::cout << "-----------------------------------------------------------------------------------------\n\n\n";

        unsigned t26,t27;
            t26=clock();
            std::cout << "UN VECTOR CON TODOS SUS NUMEROS IGUALES\n\n";

        std::vector<int> elementsQuick_SortVectorNumerosIguales = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

        std::cout << "Orden inicial: ";
        for(auto elem: elementsQuick_SortVectorNumerosIguales) {
            std::cout << elem << ", ";
        }

        std::cout << "\n\n";
        quick_sort(elementsQuick_SortVectorNumerosIguales, 0, elementsQuick_SortVectorNumerosIguales.size()-1);
        std::cout << "\nOrden final: ";
        for(auto elem: elementsQuick_SortVectorNumerosIguales){
            cout << elem << ", ";
        }

        std::cout << "\n\n";
        t27=clock();
        double time_Quick_SortVectorNumerosIguales = (double(t27-t26)/CLOCKS_PER_SEC);
        std::cout << "Tiempo transcurrido del metodo de ordenamiento por mezcla en un vector con todos los numeros iguales: " << time_Quick_SortVectorNumerosIguales << " segundos\n" << "\n";

        std::cout << "-----------------------------------------------------------------------------------------\n\n\n";




        unsigned t28,t29;
            t28=clock();
            std::cout << "UN VECTOR YA ORDENADO\n\n";

        std::vector<int> elementsQuick_SortOrdenado = {1, 2, 3, 4, 5, 6, 7, 8, 9};

        std::cout << "Orden inicial: ";
        for(auto elem: elementsQuick_SortOrdenado) {
            std::cout << elem << ", ";
        }

        std::cout << "\n\n";
        quick_sort(elementsQuick_SortOrdenado, 0, elementsQuick_SortOrdenado.size()-1);
        std::cout << "\nOrden final: \n";
        for(auto elem: elementsQuick_SortOrdenado){
            std::cout << elem << ", ";
        }

        std::cout << "\n---\n";
        t29 = clock();
        double time_Quick_SortOrdenado = (double(t29-t28)/CLOCKS_PER_SEC);
        std::cout << "Tiempo transcurrido del metodo de ordenamiento por mezcla en un vector ya ordenado: " << time_Quick_SortOrdenado << " segundos\n" << "\n";

        std::cout << "-----------------------------------------------------------------------------------------\n\n\n";


        unsigned t30,t31;
            t30=clock();
            std::cout << "UN VECTOR DE NUMEROS ALEATORIOS\n\n";
        srand (time(NULL));
        std::vector <int> elementsQuick_SortVectorNumerosAleatorios = {};


         for (int pos = 0; pos < 200; pos++) {
           elementsQuick_SortVectorNumerosAleatorios.push_back((rand () % 200) + 1);
         }

         std::cout << "Orden inicial: ";
         for(auto elem: elementsQuick_SortVectorNumerosAleatorios) {
             std::cout << elem << ", ";
         }

         std::cout << "\n\n";
         quick_sort(elementsQuick_SortVectorNumerosAleatorios, 0, elementsQuick_SortVectorNumerosAleatorios.size()-1);
         std::cout << "\nOrden final: ";
         for(auto elem: elementsQuick_SortVectorNumerosAleatorios){
             cout << elem << ", ";
         }

         std::cout << "\n\n";
         t31=clock();
         double time_Quick_SortNumerosAleatorios = (double(t31-t30)/CLOCKS_PER_SEC);
         std::cout << "Tiempo transcurrido del metodo de ordenamiento por mezcla en un vector con numeros aleatorios: " << time_Quick_SortNumerosAleatorios << " segundos\n" << "\n";


         std::cout << "-----------------------------------------------------------------------------------------\n\n\n";


    // AHORA AQUI VOY A HACER UNO QUE ES EL METODO DE INSERCION QUE ESTA EN ESTA PAGINA   https://www.youtube.com/watch?v=lYNyL0HuWSg

    unsigned t32,t33;
        t32=clock();
        std::cout << "VECTOR ORDENADO INVERSAMENTE\n\n";
        std::vector<int> elementsInsertion_SortOrdenadoInversamente = {100,99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,83,82,81,80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65,64,63,62,61,60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};

        std::cout << "Vector inicial: ";
        for(auto elem: elementsInsertion_SortOrdenadoInversamente) {
            std::cout << elem << ", ";
        }
        std::cout << "\n\n";
        insertion_Sort(elementsInsertion_SortOrdenadoInversamente);
        std::cout << "\nOrden final: ";
        for(auto elem: elementsInsertion_SortOrdenadoInversamente){
            std::cout << elem << ", ";
        }

        std::cout << "\n\n";
        t33=clock();
        double time_Insertion_SortVectorOrdenadoInversamente = (double(t33-t32)/CLOCKS_PER_SEC);
        std::cout << "Tiempo transcurrido del metodo de insertion sort en un vector ordenado inversamente: " << time_Insertion_SortVectorOrdenadoInversamente << " segundos\n" << "\n";

        std::cout << "-----------------------------------------------------------------------------------------\n\n\n";

        unsigned t34,t35;
            t34=clock();
            std::cout << "UN VECTOR CON TODOS SUS NUMEROS IGUALES\n\n";

        std::vector<int> elementsInsertion_SortVectorNumerosIguales = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

        std::cout << "Orden inicial: ";
        for(auto elem: elementsInsertion_SortVectorNumerosIguales) {
            std::cout << elem << ", ";
        }

        std::cout << "\n\n";
        insertion_Sort(elementsInsertion_SortVectorNumerosIguales);
        std::cout << "\nOrden final: ";
        for(auto elem: elementsInsertion_SortVectorNumerosIguales){
            cout << elem << ", ";
        }

        std::cout << "\n\n";
        t35=clock();
        double time_Insertion_SortVectorNumerosIguales = (double(t35-t34)/CLOCKS_PER_SEC);
        std::cout << "Tiempo transcurrido del metodo de insertion sort en un vector con todos los numeros iguales: " << time_Insertion_SortVectorNumerosIguales << " segundos\n" << "\n";



        std::cout << "-----------------------------------------------------------------------------------------\n\n\n";



        unsigned t36,t37;
            t36=clock();
            std::cout << "UN VECTOR YA ORDENADO\n\n";

        std::vector<int> elementsInsertion_SortVectorOrdenado = {1, 2, 3, 4, 5, 6, 7, 8, 9};

        std::cout << "Orden inicial: ";
        for(auto elem: elementsInsertion_SortVectorOrdenado) {
            std::cout << elem << ", ";
        }

        std::cout << "\n\n";
        insertion_Sort(elementsInsertion_SortVectorOrdenado);
        std::cout << "\nOrden final: ";
        for(auto elem: elementsInsertion_SortVectorOrdenado){
            cout << elem << ", ";
        }

        std::cout << "\n\n";
        t37=clock();
        double time_Insertion_SortVectorOrdenado = (double(t37-t36)/CLOCKS_PER_SEC);
        std::cout << "Tiempo transcurrido del metodo de insertion sort en un vector ya ordenado: " << time_Insertion_SortVectorOrdenado << " segundos\n" << "\n";


        std::cout << "-----------------------------------------------------------------------------------------\n\n\n";



        unsigned t38,t39;
            t38=clock();
            std::cout << "UN VECTOR DE NUMEROS ALEATORIOS\n\n";
        srand (time(NULL));
        std::vector <int> elementsInsertion_SortVectorNumerosAleatorios = {};


         for (int pos = 0; pos < 200; pos++) {
           elementsInsertion_SortVectorNumerosAleatorios.push_back((rand () % 200) + 1);
         }

         std::cout << "Orden inicial: ";
         for(auto elem: elementsInsertion_SortVectorNumerosAleatorios) {
             std::cout << elem << ", ";
         }

         std::cout << "\n\n";
         insertion_Sort(elementsInsertion_SortVectorNumerosAleatorios);
         std::cout << "\nOrden final: ";
         for(auto elem: elementsInsertion_SortVectorNumerosAleatorios){
             cout << elem << ", ";
         }

         std::cout << "\n\n";
         t39=clock();
         double time_Insertion_SortVectorNumerosAleatorios = (double(t39-t38)/CLOCKS_PER_SEC);
         std::cout << "Tiempo transcurrido del metodo de insertion sort en un vector con numeros aleatorios: " << time_Insertion_SortVectorNumerosAleatorios << " segundos\n" << "\n";


         std::cout << "-----------------------------------------------------------------------------------------\n\n\n";




         unsigned t40,t41;
           std::cout << "VECTOR ORDENADO INVERSAMENTE\n\n";
             std::vector <float> arrVectorOrdenadoInversamente = {100,99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,83,82,81,80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65,64,63,62,61,60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
             //Calculate size of array
             float N = sizeof(arrVectorOrdenadoInversamente)/sizeof(arrVectorOrdenadoInversamente[0]);
             std::cout << "Array to be sorted: \n";
             for(auto elem: arrVectorOrdenadoInversamente) {
                 std::cout << elem << ", ";
             }
           std::cout << "\n\n";
           t40=clock();
             shellsort(arrVectorOrdenadoInversamente, N);
             t41=clock();
             std::cout << "\nArray after shell sort: \n";
             for(int i = arrVectorOrdenadoInversamente.size()-1; i >= 0; i--) {
                     std::cout << arrVectorOrdenadoInversamente.at(i) << ", ";
                 }

                 std::cout << "\n\n";

                 double time_Shell_SortVectorOrdenadoInversamente = (double(t41-t40)/CLOCKS_PER_SEC);
                 std::cout << "Tiempo transcurrido del metodo de shell sort en un vector ordenado inversamente: " << time_Shell_SortVectorOrdenadoInversamente << " segundos\n" << "\n";

                 std::cout << "\n\n";




                 unsigned t42,t43;
                   std::cout << "----------VECTOR NUMS IGUALES----------\n\n";
                   std::vector<float> arrVectorIguales = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
                   float Y = sizeof(arrVectorIguales)/sizeof(arrVectorIguales[0]);
                   std::cout << "Vector inicial!" << std::endl;
                   for(auto elem: arrVectorIguales) {
                           std::cout << elem << ", ";
                       }
                   t42=clock();
                   shellsort(arrVectorIguales, Y);
                   t43=clock();
                   std::cout << "\nOrden final:\n";
                   for(auto elem: arrVectorIguales) {
                           std::cout << elem << ", ";
                       }
                   std::cout << "\n---\n";
                   double time_Shell_SortVectorTodosIguales = (double(t43-t42)/CLOCKS_PER_SEC);
                   std::cout << "Tiempo transcurrido del metodo de shellsort: " << time_Shell_SortVectorTodosIguales << " segundos\n";

                   std::cout << "\n\n";


                   unsigned t44,t45;
                       std::cout << "---------- VECTOR ORDENADO----------\n\n";
                       std::vector<float> arrVectorOrdenado = {1, 2, 3, 4, 5, 6, 7, 8, 9};
                       float T = sizeof(arrVectorOrdenado)/sizeof(arrVectorOrdenado[0]);
                       std::cout << "Vector inicial!" << "\n";
                       for(auto elem: arrVectorOrdenado) {
                               std::cout << elem << ", ";
                           }
                       t44=clock();
                       shellsort(arrVectorOrdenado, T);
                       t45=clock();
                       std::cout << "\nOrden final:\n";
                       for(auto elem: arrVectorOrdenado) {
                               std::cout << elem << ", ";
                           }
                       std::cout << "\n---\n";
                       double time_Shell_SortVectorOrdenado = (double(t45-t44)/CLOCKS_PER_SEC);
                       std::cout << "Tiempo transcurrido del metodo de shellsort: " << time_Shell_SortVectorOrdenado << " segundos\n" << "\n";


                       std::cout << "\n\n";


        // ME FALTA EN EL SHELL SORT LOS NUMEROS ALEATORIOS



        unsigned t46,t47;
        t46=clock();

        std::cout << "VECTOR ORDENADO INVERSAMENTE\n\n";

        std::vector<int> elementsSortVectorOrdenadoInversamente = {100,99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,83,82,81,80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65,64,63,62,61,60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};

          std::cout << "Vector inicial: ";
          for(auto elem: elementsSortVectorOrdenadoInversamente) {
            std::cout << elem << ", ";
          }

          std::cout << "\n\n";

          std::sort(elementsSortVectorOrdenadoInversamente.begin(), elementsSortVectorOrdenadoInversamente.end());

          std::cout << "\nOrden final: ";
          for (auto elem : elementsSortVectorOrdenadoInversamente) {
            std::cout << elem << ", ";
          }

          std::cout << "\n\n";
          t47=clock();
          double time_SortVectorOrdenadoInversamente = (double(t47-t46)/CLOCKS_PER_SEC);
          std::cout << "Tiempo transcurrido del metodo sort en un vector ordenado inversamente: " << time_SortVectorOrdenadoInversamente << " segundos\n" << "\n";

          std::cout << "-----------------------------------------------------------------------------------------\n\n\n";

        unsigned t48,t49;
        t48=clock();

        std::cout << "UN VECTOR CON TODOS SUS NUMEROS IGUALES\n\n";

        std::vector<int> elementsSortVectorNumerosIguales = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

          std::cout << "Vector inicial: ";
          for(auto elem: elementsSortVectorNumerosIguales) {
            std::cout << elem << ", ";
          }

          std::cout << "\n\n";

          std::sort(elementsSortVectorNumerosIguales.begin(), elementsSortVectorNumerosIguales.end());

          std::cout << "\nOrden final: ";
          for (auto elem : elementsSortVectorNumerosIguales) {
            std::cout << elem << ", ";
          }

          std::cout << "\n\n";
          t49=clock();
          double time_elementsSortVectorNumerosIguales = (double(t49-t48)/CLOCKS_PER_SEC);
          std::cout << "Tiempo transcurrido del metodo sort en un vector ordenado inversamente: " << time_elementsSortVectorNumerosIguales << " segundos\n" << "\n";

          std::cout << "-----------------------------------------------------------------------------------------\n\n\n";

        unsigned t50,t51;
        t50=clock();

        std::cout << "UN VECTOR YA ORDENADO\n\n";

        std::vector<int> elementsSortVectorOrdenado = {1, 2, 3, 4, 5, 6, 7, 8, 9};

          std::cout << "Vector inicial: ";
          for(auto elem: elementsSortVectorOrdenado) {
            std::cout << elem << ", ";
          }

          std::cout << "\n\n";

          std::sort(elementsSortVectorOrdenado.begin(), elementsSortVectorOrdenado.end());

          std::cout << "\nOrden final: ";
          for (auto elem : elementsSortVectorOrdenado) {
            std::cout << elem << ", ";
          }

          std::cout << "\n\n";
          t51=clock();
          double time_elementsSortVectorOrdenado = (double(t51-t50)/CLOCKS_PER_SEC);
          std::cout << "Tiempo transcurrido del metodo sort en un vector ordenado inversamente: " << time_elementsSortVectorOrdenado << " segundos\n" << "\n";

          std::cout << "-----------------------------------------------------------------------------------------\n\n\n";

        unsigned t52,t53;
        t52=clock();

        std::cout << "UN VECTOR DE NUMEROS ALEATORIOS\n\n";
        srand (time(NULL));

        std::vector<int> elementsSortVectorNumerosAleatorios = {};

        for (int pos = 0; pos < 200; pos++) {
          elementsSortVectorNumerosAleatorios.push_back((rand () % 200) + 1);
        }

          std::cout << "Vector inicial: ";
          for(auto elem: elementsSortVectorNumerosAleatorios) {
            std::cout << elem << ", ";
          }

          std::cout << "\n\n";

          std::sort(elementsSortVectorNumerosAleatorios.begin(), elementsSortVectorNumerosAleatorios.end());

          std::cout << "\nOrden final: ";
          for (auto elem : elementsSortVectorNumerosAleatorios) {
            std::cout << elem << ", ";
          }

          std::cout << "\n\n";
          t53=clock();
          double time_elementsSortVectorNumerosAleatorios = (double(t53-t52)/CLOCKS_PER_SEC);
          std::cout << "Tiempo transcurrido del metodo sort en un vector ordenado inversamente: " << time_elementsSortVectorNumerosAleatorios << " segundos\n" << "\n";

          std::cout << "-----------------------------------------------------------------------------------------\n\n\n";






    /* ESTO ES UNA COSA QUE NO SIRVE PARA NADA
    for (auto elem: elements) {
        std::cout << elem << ", ";
    }

    quick_sort(elements, 0, elements.size()-1);

    std::cout << "\n";

    for (auto elem: elements) {
        std::cout << elem << ", ";
    }
    */

    /*

    unsigned t6,t7;
        t6=clock();
        std::cout << "UN VECTOR CON TODOS SUS NUMEROS IGUALES\n\n";

    std::vector<int> elementsQuick_Sort = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << "Orden inicial: ";
    for(auto elem: elementsQuick_Sort) {
        std::cout << elem << ", ";
    }

    std::cout << "\n\n";
    quick_sort(elementsQuick_Sort, 0, elementsQuick_Sort.size()-1);
    std::cout << "\nOrden final: \n";
    for(auto elem: elementsQuick_Sort){
        cout << elem << ", ";
    }

    std::cout << "\n---\n";
    t7=clock();
    double timeQuick_Sort = (double(t6-t7)/CLOCKS_PER_SEC);
    std::cout << "Tiempo transcurrido del metodo de ordenamiento rapido: " << timeQuick_Sort << " segundos\n" << "\n";

*/

}


