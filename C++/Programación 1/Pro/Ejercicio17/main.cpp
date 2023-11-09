#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int numeroa {0};
    int numerob {0};
    int numeroc {0};
    cout<< "Introduce tres numeros:";
    cin>> numeroa >> numerob >> numeroc;
    vector<int> multiplos {0};

    int num{numeroa};
    while(num <=numerob){
        if(num % numeroc ==0) multiplos.push_back(num);
        num++;
    }
}
