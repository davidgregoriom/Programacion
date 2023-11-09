#include <iostream>
#include <vector>

using namespace std;








int main(){
    int acu = 0;
    vector<int>num(10,0);
    cout << "Introduce 10 numeros:\n";
    cin>> num[0];
    for(int i = 0; i<10;i++){
        cin>>num[i] ;
    }

    for(int i=0 ; i<9 ; i++){

    acu = acu+  num[i];

    }

    acu = acu /10;

    cout << acu<< "\n";
return 0;
}

