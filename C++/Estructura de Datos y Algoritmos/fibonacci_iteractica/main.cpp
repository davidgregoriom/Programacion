#include <iostream>


using namespace std;

void fibonacci_iteractivo(int num){
    int x{0},y{1},z{0};
    for(int i=0; i<num;i++){

        cout << x << " ";
        z=x+y;
        x=y;
        y=z;
    }


}

int fibonacci_recursivo(int num){
    if((num==0)||(num==1)){
        return(num);
    }else{
        return(fibonacci_recursivo(num-1)+fibonacci_recursivo(num-2));
    }
}


int main(){

    int num, num_rec=0;
    cout<< "Mete numero\n";
    cin >> num;
    cout << "\nLa serie es: \n";
    //Fibonacci de modo iteractivo
    cout <<"Modo iteractivo: ";
    fibonacci_iteractivo(num);

    //Fibonacci de modo recursivo
    cout <<"\nModo recursivo:";
    while(num_rec<num){
    cout <<" "<<fibonacci_recursivo(num_rec);
    num_rec++;
    }
    return 0;
}
