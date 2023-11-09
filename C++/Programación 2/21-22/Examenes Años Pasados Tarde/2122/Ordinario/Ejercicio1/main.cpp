#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Polinomio{
private:
    vector<double>polinomio;
public:
    Polinomio(){}
    Polinomio(int grado,const vector<double>&polinomio_){
        if(grado!=polinomio_.size()-1){
            throw string{"Error"};
        }
        polinomio=polinomio_;
    }
    Polinomio operator +(const Polinomio &poli){
        int tamano1=polinomio.size();
        int tamano2=poli.getGrado()+1;
        vector<double>aux2{poli.getConstante()},aux1{getConstante()};

        if(tamano1>tamano2){
            aux1.resize(tamano1,0);
        }else{
            aux1.resize(tamano2,0);
        }
        for(int i{0};i<aux1.size();i++){
            aux1.at(i)=aux1.at(i)+aux2.at(i);
        }

        try{
            Polinomio retorno(aux1.size()-1,aux1);
            return retorno;
        }catch(const string &a){
            cout<<"Error"<<endl;
        }

    }
    int getGrado()const{return polinomio.size()-1;}
    vector<double>getConstante()const{return polinomio;}
    void setConstante(const vector<double>co){polinomio=co;}

};
ostream& operator <<(ostream &os,const Polinomio &poli){
    auto constante=poli.getConstante();

    for(int i=0;i<poli.getGrado()+1;i++){
        if(i==0){
            os<<constante.at(0);
        }else{
            if(constante.at(i)>0){
                os<<constante.at(i)<<i;
            }else if(constante.at(i)<0){
                os<<constante.at(i)<<i;
            }else{

            }
        }
    }
    return os;

}

istream& operator >>(istream &is,Polinomio &poli){
    vector<double>aux;
    int grado=0,constante;
    cout<<"Grado del polinomio? ";
    cin>>grado;
    cout<<endl;

    for(int i=0;i<grado+1;i++){
        cout<<"introduce la constante para el grado " <<i;
        cin>> constante;
        aux.push_back(constante);
    }
    try{
        poli=Polinomio(grado,aux);
    }catch(const string &a){
        cout<<"Excepcion"<<a;
    }
    return is;
}

int main(){
    Polinomio pol1,pol2(3,{1,2,3,4}),pol3; //Constructores
    std::cin>>pol1; //Sobrecarga de >>

    pol3=pol1+pol2; //Sobrecarga operador +

    std::cout<<"Polinomio 1: "<<pol1<<std::endl;   //Sobrecarga de <<
    std::cout<<"Polinomio 2: "<<pol2<<std::endl;
    std::cout<<"Polinomio 3: "<<pol3<<std::endl;

    std::cout<<"Ejemplo excepcion constructor: "<<std::endl;
    try{
        Polinomio mal(4,{1,2,3,4,5,6,7}); //ExcepciÃ³n del constructor
    }
    catch(const std::string &e)
    {
        std::cout<<"Excepcion capturada: "<<e<<std::endl;
    }

    return 0;vector<double>poli;
}
