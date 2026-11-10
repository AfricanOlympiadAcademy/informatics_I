#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool IsPalindrome(string s);
string Strip(string s);

int main(){
    string g;
    cin >> g;
    cout << IsPalindrome(g)<< endl;
    
    return 0;
}

bool IsPalindrome(string s){
    if (s.size() == 0 || s.size() == 1){
        return true;
    }
    if (s[0] == s[s.size()-1]){
        return IsPalindrome(Strip(s));
    }
    else{
        //return (IsPalindrome(s.erase(0, 1)) || IsPalindrome(s.erase(s.size()-1, 1)));
        if (s[0] == s[s.size()-2]){
            return IsPalindrome(s.erase(s.size()-1, 1));
        }
        else{if (s[1] == s[s.size()-1]){
            return IsPalindrome(s.erase(0,1));
        }else{
            return false;
        }}
    }
}
string Strip(string s){
    string newText;
    for (int i = 1; i < s.size()-1; i++){
        newText += s[i];
    }
    return newText;
}