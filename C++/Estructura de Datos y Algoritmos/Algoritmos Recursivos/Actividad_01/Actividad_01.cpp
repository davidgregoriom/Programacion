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
bool is_palindrome(string word) {
    for(int i{0};i>(word.size()/2+1);i++){
        if(word.at(i)==word.at(word.size()-i)){
            return true;
        }else if(word.at(i)==((word.size()/2)+1)){
            return true;
        }else{
            return false;
            break;
        }
    }
}



int main() {
    vector<string> phrases{{"ana", "yo soy", "isaac no ronca asi", "me lavo la mano","usted","usted de tsu"}};
    for (auto word: phrases) {
        word = remove_blanks(word);
        cout << word << "? " << is_palindrome(word) << endl;
    }
}
