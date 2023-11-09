#include <iostream>
#include <string>
#include <vector>


using namespace std;
int p{0};
int x{0};
int i{0};
int l{-1};
int main(){
    vector<string> palabras;
    string texto{""};
    cout << "introduce el texto";
    getline(cin,texto);
    while(x!=9){
        p=texto.find("",i+1);
        string palabra=texto.substr(i,p-i);
            int p2=palabra.find("a");
               if(p2!=-1){
                   cout << palabra;
               }
         i=p;
               if(p==-1){
                   break;
               }
    }
    return(0);
}
