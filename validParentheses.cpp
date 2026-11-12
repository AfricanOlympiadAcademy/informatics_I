#include <bits/stdc++.h>
using namespace std;

bool check_valid(string s){
    vector<char> st = {};
    int i = 0;
    int n = s.size();
    
    while(i < n){
        if((s[i] == '(') || (s[i] == '{') || (s[i] == '[')){
            st.push_back(s[i]);
        }
        else{
            if((st.size() == 0)){
                return false;
            }
            
            int last = st.size() - 1;
            char p = st[last];
            
            if((s[i] == ')') && (p == '(')){
                st.pop_back();
            }
            else if((s[i] == '}') && (p == '{')){
                st.pop_back();
            }
            else if((s[i] == ']') && (p == '[')){
                st.pop_back();
            }
            else{
                return false;
            }
        }
        i++;
    }
    
    if((st.size() == 0)){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;
    
    if(check_valid(s)){
        cout << "true" << "\n";
    }
    else{
        cout << "false" << "\n";
    }
    
    return 0;
}