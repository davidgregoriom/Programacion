#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main(){

    ///Primelo

    string cadena{""};
    cout<<"Introduce una cadena de texto:\n";
    getline(cin,cadena);

    ///Segundo

    vector<string>palabras;
    string palabra{""};
    for(auto e:cadena){

        if(e != ' '){
         palabra.push_back(e);
        }else{
          palabras.push_back(palabra);
          palabra.clear();
        }
    }
    if(!palabra.empty())palabras.push_back(palabra);


    /// Tercero

    for(auto palabra: palabras){
        char primera = palabra. front();
        char ultima = palabra.back();
        if(primera == 'a'||primera == 'e'||primera == 'i'||primera == 'o'||primera == 'u'){
             if(ultima == 'a'||ultima == 'e'||ultima == 'i'||ultima == 'o'||ultima == 'u'){
                 cout << palabra<< "\n";
             }
        }
    }



}
