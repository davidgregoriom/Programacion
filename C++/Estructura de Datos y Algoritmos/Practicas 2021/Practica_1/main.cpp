#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <iterator>
using namespace std;

//Apartado_1:
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
//Apartado_2:
int cociente(int dividiendo, int divisor){

    if(dividiendo<divisor){
    return 0;
    }else{
       return 1+cociente(dividiendo-divisor, divisor);
    }
}
//Apartado_3:
int resto(int dividendo, int divisor){
    if(dividendo<divisor){
    return dividendo;
    }else{
       return resto(dividendo-divisor, divisor);
    }
}
//Aparado_4:
bool es_multiplo(int num, int divisor){
    if(num<divisor){
    return false;
    }else if(num== divisor){
        return true;
    }else{
       return es_multiplo(num-divisor, divisor);
    }
}
//Apartado_5:
int mcd(int a, int b){
    if(b ==0){
        return a;
    }else{
        mcd(b, a%b);
    }
}
//Apartado_6:
int sum(int N){
 if(N==1){
     return N;
 }else{
     return N+sum(N-1);
 }
}
//Apartado_7:
int sum_pares(int N){
 if(N%2==1){
     return sum_pares (N-1);
 }else{
     return N+sum_pares(N-2);
 }
}
//Apartado_8:
int sum_impares(int N){
 if(N%2==0){
     return sum_impares(N-1);
 }else{
     return N+sum_impares(N-2);
 }
}
//Apartado_9
string invertir(const string & input){
     string res = " ";
     if(input.size() == 0){
         res = input;
         return res;
     }else{
         char primeraletra = input.at(0);
         res = input.substr(1);
         return invertir(res) + primeraletra;
     }
}
//Apartado_10:
int invertir(int num){
    int i{0};
    while(num>0){
        i= i * 10  +(num %10);
    }
    return i;
}
//Apartado_11:
string num2binary(int num){
    string binar{};
        while(num!=0){
            if(num%2==1){
                binar.push_back('1');
            }else{binar.push_back('0');}
            num/=2;
        }
        return binar;
}
//Apartado_12:
bool equal1(const std::vector<int>& lhs, const std::vector<int>& rhs){
    if(lhs.size()==rhs.size()){
            for(int i{0}; i<lhs.size(); i++){
                if(lhs.at(i)!=rhs.at(1)){return false;}
            }
        }else{return false;}
        return true;
}
//Apartado_13:
bool equal(const std::array<std::array<int, 100>, 100>& lhs,  const std::array<std::array<int, 100>, 100>& rhs){
    for(int i{0}; i<lhs.size(); i++){
        if(lhs.at(i)!=rhs.at(1)){return false;}
     }
    return true;
}
//Apartado_14:
bool is_perfect(int num){
    int sum;
       vector<int> v{1,2,3,5,7};
       for(auto elem: v){
           if(num%elem==0){sum+=elem;}
       }
       if(sum=num)return true;
       else return false;
}
//Apartado_15:
void bubble_sort_recursive(std::vector<int>& values){
    for(int i{0}; i<values.size()-1;i++){
        bool any_swap=false;
        for(int j{0};j<values.size()-1-i;j++){
            if(values[j]> values[j+1]){
                swap(values[j],values[j+1]);
                any_swap= true;
            }
        }
        if(!any_swap){break;}
    }
}
//Apartado_16:
void quicksort_strings(std::vector<std::string>& values){
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
//Apartado_17:
struct Point { float x, y; };
void sort_by_distance(std::vector<Point>& values, float origin_x, float origin_y){
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
                    Point aux=values.at(j);
                    values.at(j)=values.at(i);
                    values.at(i)=aux;
                }
            }

        }
}
int main(){
    int i=18;
    double var;
    var=21/15;
    cout << es_multiplo(4,2)<< "\n";
    cout << es_par(i) << "\n";
    cout << cociente (4,2)<< "\n";
    cout << resto (5,2) << "\n";
    cout << es_multiplo (4,2) << "\n";
    cout << mcd(2366,273) << "\n";

}
