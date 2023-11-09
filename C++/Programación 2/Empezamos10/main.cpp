#include <iostream>

using namespace std;
template<typename T,typename MOD>
class Vector3{
public:

        Vector3(T const & elem1,T const & elem2,T const & elem3);
        T getElem() const;
        MOD Module() const;

private:

        T elem1,elem2,elem3;


};
template<>
Complejo Vector3<Complejo,Complejo>::Module() const{


}
//lista simple enlazada


int main()
{
    Vector3<int,float> a{1,2,3};

}
