#include <vector>
#include <iostream>

using namespace std;


int particion(vector<int> &v,int inicio,int final){

    auto pivote = v.at(inicio);
    int K= inicio;
    int F= final;

    while(true){
        while(v.at(K)<=pivote&& K<F) ++K;
        while(v.at(F)> pivote)--F;
        if(K>=F)break;
        swap(v.at(K),v.at(F));

    }
    swap(v.at(inicio),v.at(F));

    return F;
}

void quickSort(std::vector<int> &v, int inicio, int final)
{
   if(inicio >=final){

   }else{
       int pivote= particion(v,inicio,final);

       quickSort(v,inicio,pivote-1);
       quickSort(v,pivote+1,final);
   }
}

int main()
{
    std::vector<int> vec{2,3,5,1,7,0,9,8,6,4};

    quickSort(vec, 0, vec.size()-1);

    for(auto elem:vec)
    {
        std::cout << elem << std::endl;
    }
    return 0;
}
