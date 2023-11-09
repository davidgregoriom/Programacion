#include <iostream>
#include <vector>

using namespace std;
class Perro{
  private :
    std::string nombre;
    int chipID;


  public :
    Perro(std::string name, int chip);

    int getChipID() const ;
    std::string getNombre() const ;


};
bool operator<(Perro const & a,Perro const & b){
  return a<b;
}
void bubble_sort(std::vector<Perro> &  elements){

    for(int i=0;i<elements.size()-1;i++){
        bool a_swap=false;
        for(int j=0;i<elements.size()-1-i;j++){
            if(elements[j] < elements[j+1]){

            swap(elements[j+1],elements[j]);
            a_swap=true;
            }
        }
        if(!a_swap){break;}
    }
}

int main(){




}
