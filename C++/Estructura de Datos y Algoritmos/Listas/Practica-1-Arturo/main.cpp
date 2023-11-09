#include <iostream>
#include <string>
#include <vector>
#include <array>
using namespace std;

//Apartado 1
bool es_par(int num){

    if(num>2){
        num-=2 ;
        return es_par(num);
    }else if(num ==1){
        return false;
    }else{
        return true;
    }
}

//Apartado 2
int cociente(int dividendo, int divisor){
    if(divisor>dividendo){
        return 0;

    }else{
        return 1+cociente(dividendo-divisor, divisor);
    }


}

//Apartado 3
int resto(int dividendo, int divisor){
    if(dividendo < divisor){
        return dividendo;
    }else{
        return resto(dividendo-divisor, divisor);
    }
}

//Apartado 4
bool es_multiplo(int num, int divisor){
    if(num<divisor){
        return false;
    }else if(num== divisor){
        return true;
    }else{
        return es_multiplo(num-divisor, divisor);
    }

}

//Apartdado 5
int mcd(int a, int b){
    if(b ==0){
        return a;

    }else{
        mcd(b, a%b);
    }
}

//Apartado 6
int sum(int N){
    if(N == 1){
        return 1;
    }else{
        return N+sum(N-1);
    }
}

//Apartado 7
int sum_pares(int N){
    if(N == 2){
        return 2;
    }else if(N % 2 == 0){
        return N+sum_pares(N-2);
    }else if(N % 2 == 1){
        return sum_pares(N-1);
    }
}

//Apartado 8
int sum_impares(int N){
    if(N == 1){
        return 1;
    }else if(N % 2 == 0){
        return sum_impares(N-1);
    }else if(N % 2== 1){
        return N+sum_impares(N-2);
    }
}

//Apartado 9
string invertir1(const string & input){
    string res = " ";
    if(input.size() == 0){
        res = input;
        return res;
    }else{
        char primeraletra = input.at(0);
        res = input.substr(1);
        return invertir1(res) + primeraletra;
    }

}

//Apartado 10
int invertir(int num){
    int invertido{0};
    while(num>0){
        invertido=invertido * 10 + (num % 10);
        num /= 10;
    }
    return invertido;
}

//Apartado 11
string num2binary(int num){
    string binar{};
    while(num!=0){
        if(num%2==1){
            binar.push_back('1');
        }else{
            binar.push_back('0');
        }
        num/=2;
    }
    return binar;
}

//Apartado 12
bool equal(const vector<int>& lhs, const vector<int>& rhs){
    if(lhs.size()==rhs.size()){
        for(int i{0}; i<lhs.size(); i++){
            if(lhs.at(i)!=rhs.at(1)){
                return false;
            }
        }
    }else{
        return false;
    }
    return true;
}

//Apartado 13
bool equal(const array<array<int, 100>, 100>& lhs,  const array<array<int, 100>, 100>& rhs){
    for(int i{0}; i<lhs.size(); i++){
        if(lhs.at(i)!=rhs.at(1)){
            return false;
        }

     }
    return true;
}

//Apartado 14
bool is_perfect(int num){
    int sum;
    vector<int> v{1,2,3,5,7};
    for(auto elem: v){
        if(num%elem==0){
            sum += elem;
        }
    }if(sum = num){
        return true;
    }else{
        return false;
    }

}

//Apartado 15
void bubble_sort_recursive(vector<int>& values){
  for(int i = 0; i < values.size() - 1; i++){
    bool any_swap = false;
    for(int k = 0; k < values.size() - 1 - i; k++){
      if(values.at(k) > values.at(k + 1)){
        swap(values.at(k), values.at(k + 1));
        any_swap = true;
      }
    }
    if(!any_swap){
      break;
    }
  }
}

//Algoritmo 1
void quicksort_strings(vector<string>& values){
    for(int i{0}; i<values.size();i++){
        for(int j{0}; j<values.size();j++){
            if(values.at(i).size()<values.at(j).size()){
                string aux=values.at(j);
                values.at(j)=values.at(i);
                values.at(i)=aux;
            }
        }
    }
}

//Algoritmo 2
struct Point { float x, y; };

void sort_by_distance(vector<Point>& values, float origin_x, float origin_y){
    vector<vector<int>> dist{};
    for(int i{0}; i<values.size();i++){
        vector<int> aux{};
        int px=values.at(i).x-origin_x;
        aux.push_back(px);
        int py=values.at(i).y-origin_y;
        aux.push_back(py);
        dist.push_back(aux);
    }
    for(int i{0}; i<values.size();i++){
        for(int j{0}; j<values.size();j++){
            if(dist.at(i).at(0)<dist.at(j).at(0) || dist.at(i).at(1)<dist.at(j).at(1)){
                Point aux = values.at(j);
                values.at(j) = values.at(i);
                values.at(i) = aux;
            }
        }

    }
}

int main()
{


}
