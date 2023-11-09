#include <iostream>

using namespace std;

int main(){


    cout << "Dime un numero: ";
    int n{0};
    cin >> n;
    int f{1};

    for(int i{1}; i<= n ; i++){
        f=f*i;


    }

    cout<< f << "\n";
    return 0;

}
