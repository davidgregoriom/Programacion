#include <iostream>
#include <memory>
#include <vector>

using namespace std;
template<typename T>
class punteroLiso{
private:
    T * punt;
public:
    punteroLiso(){punt =nullptr;}
    punteroLiso(T in){punt=new T(in);}
    ~punteroLiso(){delete punt;}
    T &operator *(){
        if(punt!=nullptr){
            return *punt;
        }else{
            throw string("no existe");
        }
    }
};
template<typename T>
ostream &operator <<(ostream & os,const vector<T>&in){
    for(T e:in){
        os << e;
    }
    os <<endl;
    return os;

}

int main()
{
    punteroLiso<int> mipunt;
    punteroLiso<int> miotropunt(12);

    try{
        cout<<*miotropunt<<endl;
        cout<<&miotropunt<<endl;
    }catch(string& e){
        cout << e <<endl;
    }
    *miotropunt=200;
    cout <<*miotropunt<<endl;

    punteroLiso<vector<double>> hola({1,2,3,4});
    cout << *hola<<endl;
    cout << &hola<<endl;

    return 0;
}
