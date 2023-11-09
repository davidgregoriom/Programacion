//Este es el 21


#include <iostream>
#include <string>
#include <vector>
#include <array>



using namespace std;

int main(){
   array<int,10>serie;
   serie.at(0)=0,
   serie.at(1)=-1;

   for(int i{2}; i<10; i++){
       serie.at(i)= serie.at(i-2) + serie.at(i-1);
   }

   for(auto elem: serie){
       cout << elem <<"\n";
   }
}
