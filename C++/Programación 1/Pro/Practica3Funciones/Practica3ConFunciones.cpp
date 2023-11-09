#include <iostream>
#include <array>

using namespace std;
//Apartado2
array<int,9> matriz(){
    array<int,9> matriz1;
    for(int i{0};i<9;i++){

        cout<<"introduce un elemento "<< i+1 <<":";
        float num ;
        cin >> num;
        matriz1.at(i)=num;



    }
    int contador{0};
    for(int i=0;i<matriz1.size();i++){
        if(contador<3){
            cout<< matriz1.at(i);
            contador++;
        }else{
            cout <<"\n";
            cout << matriz1.at(i);
            contador=1;


        }
    }
    return matriz1;
}
array<int,9> matriz2(){
    cout << "\n ahora meta la 2ªmatriz\n";
    int contador {0};
    array<int,9> matri2;
    for(int i{0};i<9;i++){

        cout<<"introduce un elemento "<< i+1 <<":";
        float num ;
        cin >> num;
        matri2.at(i)=num;



    }
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

    return matri2;

}


array<int,9>suma(){
    array<int,9>sum;
    array<int,9> matris1;
    array<int,9> matris2;
    matris1=matriz();
    matris2=matriz2();

    for(int i=0;i<9;i++){
        sum.at(i)=matris1.at(i)+matris2.at(i);
    }

    cout <<"Y su suma es:\n";
    int contador{0};
    for(int i=0;i<sum.size();i++){
        if(contador<3){
            cout<< sum.at(i);
            contador++;
        }else{
            cout <<"\n";
            cout << sum.at(i);
            contador=1;
        }
    }
    return sum;
}



array<int,9>resta(){
    array<int,9>rest;
    array<int,9> re1;
    array<int,9> re2;
    re1=matriz();
    re2=matriz2();

    for(int i=0;i<9;i++){
        rest.at(i)=re1.at(i)+re2.at(i);
    }

    cout <<"Y su resta es:\n";
    int contador{0};
    for(int i=0;i<rest.size();i++){
        if(contador<3){
            cout<< rest.at(i);
            contador++;
        }else{
            cout <<"\n";
            cout << rest.at(i);
            contador=1;
        }
    }
    return rest;
}
int determina(){
    array<int,9>determ1;
    array<int,9>determ2;
    determ1=matriz();
    determ2=matriz2();
    int deter1=(determ1.at(0)*determ1.at(4)*determ1.at(8)+determ1.at(1)*determ1.at(5)*determ1.at(6)+determ1.at(2)*determ1.at(3)*determ1.at(7))-(determ1.at(2)*determ1.at(4)*determ1.at(6)+determ1.at(1)*determ1.at(3)*determ1.at(8)+determ1.at(0)*determ1.at(5)*determ1.at(7));
    int deter2 =(determ2.at(0)*determ2.at(4)*determ2.at(8)+determ2.at(1)*determ2.at(5)*determ2.at(6)+determ2.at(2)*determ2.at(3)*determ2.at(7))-(determ2.at(2)*determ2.at(4)*determ2.at(6)+determ2.at(1)*determ2.at(3)*determ2.at(8)+determ2.at(0)*determ2.at(5)*determ2.at(7));
}










int main(){
    array<int,9> matri{0,0,0,0,0,0,0,0,0};
    array<int,9> matri2{0,0,0,0,0,0,0,0,0};
    array<int,9> suma2;
    array<int,9> resta2;
    int contador=0;
    int determinante;

    cout << "Introduce una opcion del 1 al 6 : \n 1.Salir del programa \n 2.Introducir matrices \n 3.Sumar matrices y mostrar la suma por pantalla \n 4.Restar matrices y mostrar la resta por pantalla \n 5.Calcular determinante matriz 3x3 y mostrarlo por pantalla \n 6.Imprimir las 2 matrices \n" ;
    int opcion;
    cin >> opcion;

    while(opcion <=6){
        if(opcion==1){
            return 0;
        }else if(opcion==2){


            matri= matriz();
            matri2= matriz2();
            cout << "\n Introduce una opcion del 1 al 6 : \n 1.Salir del programa \n 2.Introducir matrices \n 3.Sumar matrices y mostrar la suma por pantalla \n 4.Restar matrices y mostrar la resta por pantalla \n 5.Calcular determinante matriz 3x3 y mostrarlo por pantalla \n 6.Imprimir las 2 matrices \n" ;

            return main();
        }else if(opcion==3){
            suma();
            suma2= suma();

            cout << "\n Introduce una opcion del 1 al 6 : \n 1.Salir del programa \n 2.Introducir matrices \n 3.Sumar matrices y mostrar la suma por pantalla \n 4.Restar matrices y mostrar la resta por pantalla \n 5.Calcular determinante matriz 3x3 y mostrarlo por pantalla \n 6.Imprimir las 2 matrices \n" ;


            return main();

        }else if(opcion==4){
            resta();
            resta2= resta();
            return main();
            cout << "\n Introduce una opcion del 1 al 6 : \n 1.Salir del programa \n 2.Introducir matrices \n 3.Sumar matrices y mostrar la suma por pantalla \n 4.Restar matrices y mostrar la resta por pantalla \n 5.Calcular determinante matriz 3x3 y mostrarlo por pantalla \n 6.Imprimir las 2 matrices \n" ;


            return main();

        }else if(opcion==5){
            determina();
            determinante=determina();
            return main();

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
