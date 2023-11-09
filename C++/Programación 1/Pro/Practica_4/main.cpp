#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main(){



    function<float(vector<float>)>max= [](vector<float> const & u){

        float max{-99999};
        for(auto elem:u){
            if (max <elem ) max=elem;
        }
        return max;
    };
    function<float(vector<float>)>min= [](vector<float> const & x){

        float min{99999};
        for(auto elem:x){
            if (min >elem ) min=elem;
        }
        return min;
    };
    function<float(vector<float>)>mean=[](vector<float>const & v){
        float suma{0};
        for(auto elem:v){
            suma+= elem;
        }
        return suma/v.size();
    };

    function<float(vector<float>)> summatory= [](vector<float> const & vv){
        float suma{0};
        for(auto elem:vv){
            suma+= elem;
        }
        return suma;
    };
    function<float(vector<float>)> productory= [](vector<float> const & vv){

        float multi{1};
        for(auto elem:vv){
            multi*= elem;
        }

        return multi;
    };
    function<void(function<float(vector<float>)>,vector<float>)>print=[] (function<float(vector<float>)>const & a, vector<float> const & e ){
        cout <<a(e) << "\n";

    };

    function<float(function<float(vector<float>)>, function<float(vector<float>)>, vector<vector<float>>)> comp = [] (function<float(vector<float>)> f, function<float(vector<float>)> h, vector<vector<float>> v){
        vector<float> g;
        for(auto v: v){
            g.push_back(h(v));
        }
        return f(g);

    };


    //Apartado 1:
    vector<float>hola{2,2,3,4,5,6};
    cout <<"El elemento de valor máximo del vector es "<< max(hola) << "\n";
    cout <<"El elemento de valor mínimo del vector es "<< min(hola)<< "\n";
    cout <<"La media del vector es "<< mean(hola)<< "\n";
    cout <<"La suma de los miembros del vector es "<< summatory(hola)<< "\n";
    cout <<"El producto de los miembros del vector es"<< productory(hola)<< "\n";


    //Apartado 2:
    vector<vector<float>>vv{{1,2,3}, {3,5}, {1,1,1,1}};
    cout <<"El máximo de los máximos de cada vector es " <<comp(max, max, vv) << "\n";
    cout <<"El mínimo de los máximos de los vectores es " <<comp(min, max, vv) << "\n";
    cout <<"El sumatorio de las medias de los vectores es " <<comp(summatory, mean, vv) << "\n";
    cout <<"La media de los sumatorios de los vectores es "<<comp(mean, summatory, vv) << "\n";


    //Apartado 3:
    std::vector<std::vector<float>> datosVectores;
    std::vector<int> info;
    int numV=0;
    int cantN=0;
    std::cout<<"Introduce numero vectores\n";
    std::cin>>numV;

    for(int i=0;i<numV;i++){
      std::cout<<"Introduce numero datos V "<< i+1<<"\n";
      std::cin>>cantN;
      info.push_back(cantN);
    }
    int cont=0;

    for (auto elem:info){
      std::vector<float>aux;
      for(int j=0;j<elem;j++){
        std::cout<<"Introduce numero "<< cont+1<<" "<< j+1<<"\n";
        float n=0;
        std::cin>>n;
        aux.push_back(n);
      }
      datosVectores.push_back(aux);
      aux.clear();
      cont++;
    }

    std::array<std::function<float(std::vector<float>const &)>,5>operar{max,min,mean,summatory,productory};

    int f1=0;
    int f2=0;
    cout<<"elige 2 opciones"<<"\n";
    std::cout<<"0.max"<<"\n";
    std::cout<<"1.min"<<"\n";
    std::cout<<"2.media"<<"\n";
    std::cout<<"3.sumatorio"<<"\n";
    std::cout<<"4.producto"<<"\n";
    std::cin>>f1;
    std::cin>>f2;
    std::cout << comp(operar.at(f1),operar.at(f2),datosVectores);

    return 0;
}
