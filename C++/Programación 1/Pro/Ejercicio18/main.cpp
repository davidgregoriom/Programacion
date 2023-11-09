#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<string> palabras={"perro", "gato", "guardar", "andres", "luis", "guardar", "botella"};
    vector<string> guardadas;


    int pos{0};
    for(auto elem:palabras){
        if (elem == "guardar"){
            if (pos != palabras.size()-1){
              guardadas.push_back(palabras.at(pos+1));

            }
        }
        pos++;
    }

}
