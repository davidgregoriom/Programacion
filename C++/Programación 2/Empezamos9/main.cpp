#include <iostream>
#include <array>
#include <math.h>

//template<typename T>

//T sumar(T const & a,T const & b){
    //return a+b;

//}
//Primero el caso especifico y despues el caso general


template<typename T>
class Vector3{
public:

        Vector3(T const & elem1,T const & elem2,T const & elem3);
        T getElem() const;
        float Module() const;

private:

        T elem1,elem2,elem3;


};




//template<typename T>


//T Vector3::getElem() const
//{
//if(i==1) return elem1;
//if(i==2) return elem2;
//if(i==3) return elem3;
//throw string{"Our of bounds"};
//}



//el vector de numeros complejos , el modulo sea complejo ,su real sea el de las partes reales y el de la imaginara la de las imaginarias.

template<typename T>
float Vector3<T>::Module() const
{
 return elem1*elem1+elem2*elem2+elem3*elem3;
}
int main(){

    //Vector3<int> a{1,2,3};
}
