#include <iostream>
#include <vector>

using namespace std;
	
//BUBBLE SORT ALGORITHM 
void bubble_sort1(vector<int>& elements){	
  for(int i = 0; i < elements.size() - 1; i++){  // 'n-1' iterations	
    for(int k = 0; k < elements.size() - 1; k++){  // 'n-1' iterations
      if(elements[k] > elements[k + 1]){ // Compara los valores adyacentes
        swap(elements[k], elements[k + 1]);
      }	
    }	
  }	
}	

//MERGE-SORT ALGORITHM 
std::vector<int> merge(const std::vector<int>& izq,const std::vector<int>& der){
  std::vector<int> ret;
  auto izq_iterator = 0;
  auto der_iterator = 0;
  while (izq_iterator != izq.size() && der_iterator != der.size()){
    if (izq[izq_iterator] < der[der_iterator]){
      ret.push_back(izq[izq_iterator]);
      izq_iterator++;
    }
    else {
      ret.push_back(der[der_iterator]);
      der_iterator++;
    }
  }
  for (int i = izq_iterator; i < izq.size(); i++){
    ret.push_back(izq[i]);
  }	
  for (int i = der_iterator; i < der.size(); i++){	
    ret.push_back(der[i]);	
  }	
  return ret;	
}

std::vector<int> merge_sort(const vector<int>& elements){
  //Comprueba el caso básico/trivial
  if(elements.size() <= 1){
    return elements;
  }
  else{
    //Divide el vector en dos
    auto middle = elements.size() / 2;
    vector<int> left{elements.begin(), elements.begin() + middle};
    vector<int> right{elements.begin() + middle, elements.end()};
	  //Se aplica el merge_sort a cada uno de los vectores
    left = merge_sort(left);
    right = merge_sort(right);
    //Se fusionan esos dos vectores -ya- ordenados	
    return merge(left, right);	
  }	
}

//QUICK-SORT ALGORITHM 
//Una función para fusionar dos listas ordenadas	
int partition(vector<int>& elements, int left_index, int right_index){
  auto pivot = elements.at(left_index);
  int i = left_index;
  int j = right_index;
	while(true){
    while(elements.at(i) <= pivot && i < j){ 
      ++i;
    }
    while(elements.at(j) > pivot){
      --j;
    }
    if(i >= j) {
      break;
    }
    swap(elements.at(i), elements.at(j));	
  }	
  swap(elements.at(left_index), elements.at(j));	
  return j;	
}
void quick_sort(vector<int>& elements, int left_index, int right_index){	
  //Se comprueba el caso básico/trivial	
  if(left_index >= right_index){	
    return;
  }
  else{
    //Calcular el pivote
    int pivot = partition(elements, left_index, right_index);
	  //Aplicar clasificación rápida a ambos lados (el pivote ya está en su lugar)
    quick_sort(elements, left_index, pivot - 1);
    quick_sort(elements, pivot + 1, right_index);
  }
}

//SELECTION SORT	
void selection_sort(vector<int>& elements){	
  for(int i = 0; i < elements.size(); i++){  // 'n' iterations	
    //Busca el elemento mínimo en la sección derecha 
    int inMin = i;	
    for (int k = i + 1; k < elements.size(); k++){  //'n-i' iterations
      if(elements[k] < elements[inMin]){ //Se mantiene el índice del elemento mínimo
        inMin = k;
      }
    }
    //Intercambiar el elemento actual con el mínimo
    swap(elements[i], elements[inMin]);
  }	
}








