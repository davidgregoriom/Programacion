#include <iostream>
#include<array>
#include<string>
#include<vector>
using namespace std;

int main(){
    vector<string>palabra;
    string texto;
    cout << "Introduce el texto";
    getline(cin,texto);


    string palabra{""};
    for(auto elem:texto){
        if(elem != ' '){
            palabra.push_back(elem);
        }
        else{
            palabras.push_back(palabra);
            palabra ="";
        }

    }
   palabra.push_back(palabra);

   for(auto elem: palabras){
       if(elem.find("a") !=-1){
           cout << elem << "\n";
       }

   }


}
 
