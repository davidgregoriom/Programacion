#include <iostream>
#include <vector>

using namespace std;
void bubble_sort(std::vector<float>& desordenado) {
    for(int i=0; i<desordenado.size()-1;i++){
        for(int j=0; j<desordenado.size()-1 ;j++){
            if(desordenado[j]>desordenado[j+1]){
                swap(desordenado[j],desordenado[j+1]);
            }

        }
    }
}

int main()
{
    vector<float>elementos{1,6,2,5,3,7,9,4};
    bubble_sort(elementos);
}
