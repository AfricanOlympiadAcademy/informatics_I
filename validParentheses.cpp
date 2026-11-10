#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

bool ValidParenthesis(string s);
unordered_map<char, char> map = 
{{'(', ')'},
{'[',']'},
{'{','}'}};

int main(){
    string g;
    cin >> g;
    cout << ValidParenthesis(g)<< endl;
    
    return 0;
}

bool ValidParenthesis(string s){
    stack<char> d;
    for (char c: s){
        if (c == '(' || c == '{' || c == '['){
            d.push(map[c]);
        }
        else{
            if (d.top() == c){
                d.pop();
            }
            else{
                return false;
            }
        }
        
    }
    return true;
}