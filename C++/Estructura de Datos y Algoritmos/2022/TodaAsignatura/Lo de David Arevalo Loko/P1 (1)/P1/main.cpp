#include <iostream>
#include <vector>

using namespace std;

//Ej 1. Paridad de un numero mediante restas (recursividad simple).
bool es_par_recursivo(int num){
    if(num == 0) return true;
    else if(num == 1) return false;
    return es_par_recursivo(num - 2);
};

bool es_par_iterativo(int num){
    if(num % 2== 0) return true;
    if(num % 2 == 1) return false;
};


//Ej 2. Calcular el cociente de una divisiÃ³n entera
int cociente_recursivo(int dividendo, int divisor){
    if(dividendo < divisor) return 0;
    return cociente_recursivo(dividendo - divisor, divisor) + 1;
};

int cociente_iterativo(int dividendo, int divisor){
    int coc = dividendo / divisor;
    return coc;
};


//Ej 3. Calcular el resto de una division entera
int resto_recursivo(int dividendo, int divisor){
    if(dividendo < divisor) return dividendo;
    return resto_recursivo(dividendo - divisor, divisor);
};

int resto_iterativo(int dividendo, int divisor){
    int res = dividendo % divisor;
    return res;
};


//Ej 4. Implementar una funcion `es_multiplo` que devuelva si un numero `num` es o no divisible por otro numero `divisor`
bool es_multiplo_recursivo(int num, int divisor){
    if(num == 0) return true;
    if(num < divisor) return false;
    return es_multiplo_recursivo(num - divisor, divisor);
};

bool es_multiplo_iterativo(int num, int divisor){
    if(num % divisor == 0) return true;
    if(num % divisor != 0) return false;
};


//Ej 5. Implementar una funciÃ³n que calcule el mÃ¡ximo comÃºn divisor aplicando el [algoritmo de Euclides](https://es.wikipedia.org/wiki/Algoritmo_de_Euclides). Justifica y razona su orden de complejidad
int mcd_recursivo(int a, int b){
    if(b == 0) return a;
    return mcd_recursivo(b, a % b);
};

int mcd_iterativo(int a, int b){
    int r,m;
    if(a > b){
        r = a;
        m = b;
    }
    else{
        r = b;
        m = a;
    }
    for(int i = 1;i < r; i++){
        if(a % i == 0 && b % i == 0) m = i;
    }
    return m;
};


//Ej 6. Sumatorio de los nÃºmeros del `1` al `N` (incluido):
int sum_recursivo(int N){
    if(N == 0) return 0;
    return N + sum_recursivo(N - 1);
};

int sum_iterativo(int N){
    int sum = 0;
    for(int l = 1;l <= N;l++){
        sum = sum + l;
    }
    return sum;
};


//Ej 7. Sumatorio de los nÃºmeros **pares** del `1` al `N` (incluido):
int sum_pares_recursivo(int N){
    int p;
    if(N == 0){
        return 0;
    }
    else{
        if(N % 2 == 0){
            p = N + sum_pares_recursivo(N - 2);
        }
        else{N = N - 1;
            p = N + sum_pares_recursivo(N - 2);
        };
    };
    return p;
};

int sum_pares_iterativo(int N){
    int sum = 0;
    for(int l = 1;l <= N;l++){
        if(l % 2 == 0) sum = sum + l;
    }
    return sum;
};


//Ej 8. Sumatorio de los nÃºmeros **impares** del `1` al `N` (incluido):
int sum_impares_recursivo(int N){
    int im;
    if (N == 1){
        return 1;
    }
    else{
        if(N % 2 == 0){
            N = N - 1;
            im = N + sum_impares_recursivo(N-2);
        }
        else{ 
            im = N + sum_impares_recursivo(N-2);
        }
    }
    return im;
};

int sum_impares_iterativo(int N){
    int sum = 0;
    for(int l = 1;l <= N;l++){
        if(l % 2 == 1) sum = sum + l;
    }
    return sum;
};


//Ej 9. Implementar una funciÃ³n que invierta un `std::string` que recibe como argumento:
string invertir_recursivo(const string & input){
    string invertido = "";
    if(input.size() != 0){ char letra = input.at(input.size() - 1);
        invertido.push_back(input.at(input.size() - 1));
        invertido = input.substr(0,input.size() - 1);
        return letra+invertir_recursivo(invertido);
    }
    else{
        return input;
    }
};

string invertir_iterativo(const string & input){
    string invertido = "";
    for (int i = input.size() - 1; i >= 0; i--)
        invertido.push_back(input.at(i));
    return invertido;
};


//Ej 10. Implementar una funciÃ³n que invierta los dÃgitos de un nÃºmero entero. De manera que si el nÃºmero es `521` el algoritmo debe devolver `125`:
int invertir_recursivo(int num){
    if(num == 0) return 0;
    else{
        return (num % 10 * invertir_recursivo(num / 10)); 
    }
};

int invertir_iterativo(int num);


//Ej 11
long  num2binary_recursivo(int num){
    if(num == 0)return 0;
    else{
        return (num % 2 + (10 * num2binary_recursivo(num / 2)));
    }
};

string num2binary_iterativo(int num){
    string binar = "";
    while(num != 0){
        if(num % 2 == 1){
            binar.push_back('1');
        }
        else{
            binar.push_back('0');
        }
        num /= 2;
    }
    return binar;
};


//Ej 12. 
bool equal_recursivo(const vector<int>& lhs, const vector<int>& rhs); 
bool equal_iterativo(const vector<int>& lhs, const vector<int>& rhs);


int main(){
    bool ej1_1 = es_par_recursivo(98);
    cout << ej1_1 << endl;
    bool ej1_2 = es_par_iterativo(88);
    cout << ej1_2 << endl << endl;

    int ej2_1 = cociente_recursivo(8, 4);
    cout << ej2_1 << endl;
    int ej2_2 = cociente_iterativo(10, 7);
    cout << ej2_2 << endl << endl;

    int ej3_1 = resto_recursivo(90, 7);
    cout << ej3_1 << endl;
    int ej3_2 = resto_iterativo(30, 11);
    cout << ej3_2 << endl << endl;

    bool ej4_1 = es_multiplo_recursivo(6, 2);
    cout << ej4_1 << endl;
    bool ej4_2 = es_multiplo_iterativo(8, 2);
    cout << ej4_2 << endl << endl;

    int ej5_1 = mcd_recursivo(96, 8);
    cout << ej5_1 << endl;
    int ej5_2 = mcd_iterativo(80, 40);
    cout << ej5_2 << endl << endl;

    int ej6_1 = sum_recursivo(10);
    cout << ej6_1 << endl;
    int ej6_2 = sum_iterativo(10);
    cout << ej6_2 << endl << endl;

    int ej7_1 = sum_pares_recursivo(10);
    cout << ej7_1 << endl;
    int ej7_2 = sum_pares_iterativo(10);
    cout << ej7_2 << endl << endl;

    int ej8_1 = sum_impares_recursivo(10);
    cout << ej8_1 << endl;
    int ej8_2 = sum_impares_iterativo(10);
    cout << ej8_2 << endl << endl;

    string ej9_1 = invertir_recursivo("Supercalifragilisticoespiadiloso");
    cout << ej9_1 << endl;
    string ej9_2 = invertir_iterativo("Supercalifragilisticoespiadiloso");
    cout << ej9_2 << endl << endl;

    int ej10_1 = invertir_recursivo(123);
    cout << ej10_1 << endl << endl;
    /*int ej10_2 = invertir_iterativo(1234);
    cout << ej10_2 << endl << endl;*/

    long ej11_1 = num2binary_recursivo(5);
    cout << ej11_1 << endl;
    string ej11_2 = num2binary_iterativo(7);
    cout << ej11_2 << endl << endl;
    
    return 0;
}
