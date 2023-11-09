#include <iostream>
#include <vector>

using namespace std;
template<typename T>
class PunteroListo{
private:
    T* puntero;
public:
    PunteroListo(){puntero=nullptr;}
    PunteroListo(T in){puntero= new T(in);}
    ~PunteroListo(){delete puntero;}

    T &operator*(){
        if(puntero!= nullptr){
            return *puntero;
        }else{
            throw string{"ha fallado"};
        }
    }
};
template<typename T>
ostream &operator<<(ostream &os,const vector<T>&v){
    for(T e:v){
        os<<e;
    }
    os<<endl;
    return os;
}

int main(){
    PunteroListo<int> miPuntero;
    PunteroListo<int> miOtro(666);

    try{
        cout<<*miOtro<<endl;
        cout<<&miOtro<<endl;
    }catch(string e){

        cout<<e<<endl;
    }
    *miOtro=200;
    cout<<*miOtro<<endl;

    PunteroListo<vector<double>>miPunteroVector({1,2,3});
    cout<<*miPunteroVector;
    cout<<&miPunteroVector;

    PunteroListo<vector<double>>miPunteroVectorchar({'h','o','l','a'});
    cout<<*miPunteroVectorchar;
    cout<<&miPunteroVectorchar;
    return 0;
}
