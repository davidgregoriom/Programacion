#include <iostream>
#include <vector>
#include <memory>
#include "figura.h"

using namespace std;

int main()
{
    vector<shared_ptr<figuras>> figuras;
        bool exit = 0;
        while(exit == 0){
        cout << "que figuras desea introducir?" << endl;
        string a;
        cin >> a;
        if(a == "Cuadrado"){
            cout << "introduzca size de lado\n";
            float size{0};
            cin >> size;
            cuadrado a{size};
            shared_ptr<cuadrado> cua = make_shared<cuadrado>(a);
            figuras.push_back(cua);
        }

        }
}
