#include <iostream>
#include <vector>
#include <string.h>

int main(int argc, char const *argv[])
{
    std::string texto = "En medio del camino de la vida me vi perdido en una selva oscura, la buena senda errada y la andadura, cuando el alma vagaba adormecida. Largo fuera contar, que no se olvida, como era aquel lugar de desventura y es solo recordar tanta amargura, y la mente quedar despavorida";
    std::string tempWord = "";
    std::string tempOracion = "";
    std::vector<std::string> resultPalabras;
    std::vector<std::string> resultOraciones;

    for(auto c : texto){

        if( !isspace(c) && c != ','){

            tempWord += c;

        }else{

            if(!tempWord.empty()){
                resultPalabras.push_back(tempWord);
                tempOracion += tempWord + " ";
                tempWord.clear();
            }

            if(c == ','){
                resultOraciones.push_back(tempOracion);
                tempOracion.clear();
            }

        }

    }

    for(auto word : resultPalabras){
        std::cout << word << std::endl;
    }

    for(auto oracion : resultOraciones){
        std::cout << oracion << std::endl;
    }

    return 0;
}
