#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <array>

using namespace std;

int main() {
  srand(time(NULL));
  array<int,100> cien;
  vector<int> losmultiplosdetres;

  for(int i{0} ;i< cien.size(); i++){
      cien.at(i)=rand() % 21;
  }
    for(auto elem:cien){
        if(elem%3 ==0)losmultiplosdetres.push_back(elem);
    }

  int numero = rand() % 21;

  cout<< rand <<"\n";

}
