#include <iostream>
#include <array>
#include <vector>
#include <memory>


using namespace std;



int main(){
  vector<int> v{1,2,3};
  auto a=make_shared<vector<int>>(v);
  for(int i{0};i<2;i++){
      a.push_back(i);
  }
  cout << a.size();

  return 0;
}
