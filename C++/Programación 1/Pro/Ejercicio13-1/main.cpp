#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<string> palabras;
    string texto;
    cout << "Introduce un texto: \n";
    getline(cin, texto);

    string palabra{""};
    for(auto elem: texto){
        if(elem !=' ')palabra.push_back(elem);
        else{
            palabras.push_back(palabra);
            palabra= "";
        }
    }
    palabras.push_back(palabra);

    for(auto elem:palabras){
        if(elem.find("a") != -1){
            cout <<elem << "\n";
        }
    }

}
