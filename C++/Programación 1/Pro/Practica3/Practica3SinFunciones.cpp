#include <iostream>
#include <array>

using namespace std;


int main(){
    array<int,9> matri{0,0,0,0,0,0,0,0,0};
    array<int,9> matri2{0,0,0,0,0,0,0,0,0};

    cout << "Introduce una opcion del 1 al 6 : \n 1.Salir del programa \n 2.Introducir matrices \n 3.Sumar matrices y mostrar la suma por pantalla \n 4.Restar matrices y mostrar la resta por pantalla \n 5.Calcular determinante matriz 3x3 y mostrarlo por pantalla \n 6.Imprimir las 2 matrices \n" ;
    int opcion;
    cin >> opcion;

    while(opcion <=6){



        if(opcion==1){
            return 0;

        }else if(opcion==2){



            for(int i{0};i<9;i++){

                cout<<"introduce un elemento "<< i+1 <<":";
                float num ;
                cin >> num;
                matri.at(i)=num;



            }
            cout <<"ahora te toca la otra matriz:\n";

            for(int i{0};i<9;i++){

                cout<<"introduce un elemento "<< i+1 <<":";
                float num ;
                cin >> num;
                matri2.at(i)=num;



            }
            cout << " has introducido estas dos matrices:\n";
            int contador{0};
            for(int i=0;i<matri.size();i++){
                if(contador<3){
                    cout<< matri.at(i);
                    contador++;
                }else{
                    cout <<"\n";
                    cout << matri.at(i);
                    contador=1;
                }
            }
            cout<<"\n";
            for(int i=0;i<matri2.size();i++){
                if(contador<3){
                    cout<< matri2.at(i);
                    contador++;
                }else{
                    cout <<"\n";
                    cout << matri2.at(i);
                    contador=1;
                }
            }
            cout<<"\n";




            cout << "Introduce una opcion del 1 al 6 : \n 1.Salir del programa \n 2.Introducir matrices \n 3.Sumar matrices y mostrar la suma por pantalla \n 4.Restar matrices y mostrar la resta por pantalla \n 5.Calcular determinante matriz 3x3 y mostrarlo por pantalla \n 6.Imprimir las 2 matrices \n" ;

            cin >> opcion;

        }else if(opcion==3){
            array<int,9> suma;
            for(int i=0;i<9;i++){
                suma.at(i)=matri.at(i)+matri2.at(i);
            }

            cout <<"Y su suma es:\n";
            int contador{0};
            for(int i=0;i<suma.size();i++){
                if(contador<3){
                    cout<< suma.at(i);
                    contador++;
                }else{
                    cout <<"\n";
                    cout << suma.at(i);
                    contador=1;
                }
            }
            cout << "\n Introduce una opcion del 1 al 6 : \n 1.Salir del programa \n 2.Introducir matrices \n 3.Sumar matrices y mostrar la suma por pantalla \n 4.Restar matrices y mostrar la resta por pantalla \n 5.Calcular determinante matriz 3x3 y mostrarlo por pantalla \n 6.Imprimir las 2 matrices \n" ;

            cin >> opcion;

        }else if(opcion==4){
            array<int,9> resta;
            for(int i=0;i<9;i++){
                resta.at(i)=matri.at(i)-matri2.at(i);
            }

            cout <<"Y su resta es:\n";
            int contador{0};
            for(int i=0;i<resta.size();i++){
                if(contador<3){
                    cout<< resta.at(i);
                    contador++;
                }else{
                    cout <<"\n";
                    cout << resta.at(i);
                    contador=1;
                }
            }

            cout << "\n Introduce una opcion del 1 al 6 : \n 1.Salir del programa \n 2.Introducir matrices \n 3.Sumar matrices y mostrar la suma por pantalla \n 4.Restar matrices y mostrar la resta por pantalla \n 5.Calcular determinante matriz 3x3 y mostrarlo por pantalla \n 6.Imprimir las 2 matrices \n" ;

            cin >> opcion;

        }else if(opcion==5){
            int determinante1 =(matri.at(0)*matri.at(4)*matri.at(8)+matri.at(1)*matri.at(5)*matri.at(6)+matri.at(2)*matri.at(3)*matri.at(7))-(matri.at(2)*matri.at(4)*matri.at(6)+matri.at(1)*matri.at(3)*matri.at(8)+matri.at(0)*matri.at(5)*matri.at(7));
            int determinante2 =(matri2.at(0)*matri2.at(4)*matri2.at(8)+matri2.at(1)*matri2.at(5)*matri2.at(6)+matri2.at(2)*matri2.at(3)*matri2.at(7))-(matri2.at(2)*matri2.at(4)*matri2.at(6)+matri2.at(1)*matri2.at(3)*matri2.at(8)+matri2.at(0)*matri2.at(5)*matri2.at(7));
            cout<<"el determinante de la primera es:"<<determinante1 << "y el de la segunda es " << determinante2 <<"\n";
            cout << "Introduce una opcion del 1 al 6 : \n 1.Salir del programa \n 2.Introducir matrices \n 3.Sumar matrices y mostrar la suma por pantalla \n 4.Restar matrices y mostrar la resta por pantalla \n 5.Calcular determinante matriz 3x3 y mostrarlo por pantalla \n 6.Imprimir las 2 matrices \n" ;

            cin >> opcion;
        }else if(opcion==6){
            cout<<"las funciones son:\n";
            int contador{0};
            for(int i=0;i<matri.size();i++){
                if(contador<3){
                    cout<< matri.at(i);
                    contador++;
                }else{
                    cout <<"\n";
                    cout << matri.at(i);
                    contador=1;
                }
            }
            cout<<"\n";
            for(int i=0;i<matri.size();i++){
                if(contador<3){
                    cout<< matri.at(i);
                    contador++;
                }else{
                    cout <<"\n";
                    cout << matri.at(i);
                    contador=1;
                }
            }
            cout<<"\n";
            cout << "Introduce una opcion del 1 al 6 : \n 1.Salir del programa \n 2.Introducir matrices \n 3.Sumar matrices y mostrar la suma por pantalla \n 4.Restar matrices y mostrar la resta por pantalla \n 5.Calcular determinante matriz 3x3 y mostrarlo por pantalla \n 6.Imprimir las 2 matrices \n" ;

            cin >> opcion;
        }else{
            cout << "Introduce una opcion del 1 al 6 : \n 1.Salir del programa \n 2.Introducir matrices \n 3.Sumar matrices y mostrar la suma por pantalla \n 4.Restar matrices y mostrar la resta por pantalla \n 5.Calcular determinante matriz 3x3 y mostrarlo por pantalla \n 6.Imprimir las 2 matrices \n" ;

            cin >> opcion;


        }


    }
}
