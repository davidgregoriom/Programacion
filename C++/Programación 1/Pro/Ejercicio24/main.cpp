#include <iostream>
#include <vector>


using namespace std;

int main()
{

    cout << "Dime un numero: ";
    int num{0};
    cin >> num;
    vector<int> factores;
    for(int divisor{1}; divisor < num /2; divisor++){
        if(num % divisor ==0)factores.push_back(divisor);

    }
     factores.push_back(num);

     return 0;






}
