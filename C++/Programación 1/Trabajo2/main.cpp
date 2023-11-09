#include <iostream>
#include <vector>
#include<functional>
#include <set>

using namespace std;

int main()
{
   array<int,5> miArray{1,4,3,1,5};
   set<int>miArr;

   for(int i{0};i<5;i++){
      miArr.insert(miArray.at(i));
   }


}
