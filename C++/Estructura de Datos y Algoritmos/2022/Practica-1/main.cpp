#include <iostream>

using namespace std;
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
bool es_par2(int num){

    if(num%2==0){
        return true;
    }else{
        return false;
    }
}

int mcd(int a, int b){
    if(b ==0){
        return a;
    }else{
        mcd(b, a%b);
    }
}
int mcd_2(int a,int b){
    int c ;
    while(b!=0){
        c=b;
        b=a%b;
        a= c;
    }
    return a;
}

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
int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
