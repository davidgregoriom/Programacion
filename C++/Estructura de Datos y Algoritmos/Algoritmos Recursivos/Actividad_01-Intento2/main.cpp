#include <iostream>
#include <string>
#include <vector>
using namespace std;


string remove_blanks(string word) {
    string word_2;
    for(auto c:word){
        if(c==' '){
            ///No necesitas hacer nada
        }else{
            word_2.push_back(c);
        }
    }
    return word_2;
}



bool is_palindrome(string word){
    string word_2;
   int len = word.size();
   for(auto c: word){
       if(word.size() == word_2.size()){
           if(word==word_2){
               return true;
           }else{
               return false;
           }
       }else{
        word_2.push_back(len);
        len = len-1;
       }

   }

    //Recursión: 'palabra' será un palíndromo si 'palabra [1, len-1]' es un palíndromo
}



int main() {
    vector<string> phrases{{"ana", "yo soy", "isaac no ronca asi", "me lavo la mano","usted","usted de tsu"}};
    for (auto word: phrases) {
        word = remove_blanks(word);
        cout << word << "? " << is_palindrome(word) << endl;
    }
}
