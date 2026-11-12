#include <bits/stdc++.h>
using namespace std;

bool check_recursive(string &s, int a, int b, int count){
    if((a >= b)){
        return true;
    }
    
    if((s[a] == s[b])){
        return check_recursive(s, a + 1, b - 1, count);
    }
    else{
        if((count >= 1)){
            return false;
        }
        
        bool p1 = check_recursive(s, a + 1, b, count + 1);
        bool p2 = check_recursive(s, a, b - 1, count + 1);
        
        if((p1 == true) || (p2 == true)){
            return true;
        }
        else{
            return false;
        }
    }
}

bool check_PII(string s){
    int a = 0;
    int b = s.size() - 1;
    int count = 0;
    return check_recursive(s, a, b, count);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;
    
    if(check_PII(s)){
        cout << "true" << "\n";
    }
    else{
        cout << "false" << "\n";
    }
    
    return 0;
}