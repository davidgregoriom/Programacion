#include <iostream>
#include <string>

using namespace std;

void repetir(const string & cadena,const int & numero){
    if(numero<=0)throw string {"numero positivo"};
    for(int i=numero;i>0;i--){
        cout << cadena;   
    }
}

int main()
{
    string cadena;
    int numero;
    cout << "meta cadena y repeticiones!" << endl;
     getline(cin,cadena);

    cin >> numero;

    cin.ignore();

    repetir(cadena,numero);

    return 0;
}
