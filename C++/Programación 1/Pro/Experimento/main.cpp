#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string texto{"el,texto del, examen."};
    vector<string> text{};
    vector<string> text2{};
    string palabras= "";
    string palabras2 = "";

    int contador{0};

    for(auto elem:texto){
        if(elem ==',' && elem=='.'){
            contador++;
        }
    }
    for(auto elem:texto){
        if(elem !=',' && elem!=' ' && elem!='.'){
            palabras.push_back(elem);

        }else{
            text.push_back(palabras);
            palabras= " ";

        }
    }

    text.push_back(palabras);

    for(auto elem: text){
        cout << elem << " " ;

    }





    cout<< contador;

    return 0;




}
