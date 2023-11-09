#include <iostream>
#include<array>

int main() {

  std::string cad {""};
  std::cout << "introduzca un texto " << "\n";
  int pos {-1};
  getline (std::cin,cad);

  for(auto elem: cad){
    pos++;
    if (elem == ' '){
      if(cad.at(pos+1) == 'a'){
        int next_espacio = cad.find (' ', pos+1);
        if(next_espacio != -1){

         std::cout << cad.substr(pos+1 , next_espacio - pos -1) << " ";

       }else{
         std::cout << cad.substr(pos+1);
       }

      }
    }
  }
 return 0;

}
