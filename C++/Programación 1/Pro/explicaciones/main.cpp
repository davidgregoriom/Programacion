#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(){
    set<int> conjunto;
    conjunto.insert(1);
    conjunto.insert(1);
    conjunto.erase(1);

    if(conjunto.erase(1)) cout <<"borrado";
    else cout <<"No existia";


}
