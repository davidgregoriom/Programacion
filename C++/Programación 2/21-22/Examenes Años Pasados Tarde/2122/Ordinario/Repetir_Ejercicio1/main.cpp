#include <iostream>
#include <vector>
#include <array>

using namespace std;


class Polinomio{
private:
    vector<double>polinomio;
public:
    Polinomio(){}
    Polinomio(const vector<double> & polinomio,const int & grado){
        if(polinomio.size()!=grado){
            throw string ("aqui no va bien");
        }
        this->polinomio=polinomio;
    }
    Polinomio operator +(const Polinomio &p){
        vector<double> aux1{getPolinomio()},aux2{p.getPolinomio()};

        int tam1=polinomio.size();
        int tam2=p.getGrado()+1;
        if(tam1<tam2){
            aux2.resize(tam1,0);
        }else{
            aux1.resize(tam2,0);
        }
        for(int i=0;i<aux1.size();i++){
            aux1.at(i)=aux1.at(i)+aux2.at(i);
        }
        try {
            Polinomio retorno(aux1,aux1.size()-1);
            return retorno;
        } catch(const string &s) {
            cout<< "error"<<endl;
        }

    }
    int getGrado()const{return polinomio.size()-1;}
    vector<double> getPolinomio() const{return polinomio;}
    void setPolinomio(const vector<double> &value){polinomio = value;}
};

ostream &operator <<(ostream &os,const Polinomio &p){
    auto poli=p.getPolinomio();
    for(int i=0;i<p.getGrado()+1;i++){
        if(i==0){
            os<<poli.at(0);
        }else {
            if(poli.at(i)<0){
                os<<"+"<<poli.at(i)<<"*X"<<i;
            }else if(poli.at(i)>0){
                os<<poli.at(i)<<"*X"<<i;
            }else{

            }
        }
    }
    return os;

}
istream &operator >>(istream & is,Polinomio &p){
    vector<double>aux;
    int grado=0,cte;
    cout<<"Grado del polinomio? ";
    cin>>grado;
    cout<<endl;

    for(int i=0;i<grado+1;i++){
        cout<<"introduce para el grado "<<i<<endl;
        cin>>cte;
        aux.push_back(cte);
    }

    try{
        p=Polinomio(aux,grado);

    }catch(const string &s){
        cout << s;
    }
    return is;
}

int main() {
    Polinomio po1,po2({1,2,3,4},3),po3;
    cin>>po1;
    po3=po1+po2;
    cout<<po1<<endl;
    cout<<po2<<endl;
    cout<<po3<<endl;

    cout<<"Excepcion"<<endl;

    try {
        Polinomio mal({1,2,3,4,5,6},4);
    } catch (const string &e) {
        cout<<"Excepcion"<<e<<endl;
    }
   return 0;
}


