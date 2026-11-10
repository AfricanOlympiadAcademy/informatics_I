#include <bits/stdc++.h>
using namespace std;

vector<int> check_sum_two(int a, int b, vector<pair<long long, int>> &list, long long target){
    while(a < b){
        if(list[a].first + list[b].first > target){
            b--;
        }
        else if(list[a].first + list[b].first < target){
            a++;
        }
        else{
            vector<int> v;
            v.push_back(list[a].second);
            v.push_back(list[b].second);
            return v;
        }
    }
    return {};
}

vector<int> check_sum_three(int n, long long x, vector<pair<long long, int>> &list){
    for(int i = 0; i < n; i++){
        int a = i + 1; 
        int b = n - 1; 
        long long target = x - list[i].first;
        
        vector<int> v = check_sum_two(a, b, list, target);
        if(!v.empty()){
            v.insert(v.begin(), list[i].second);
            return v;
        }
    }
    return {};
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    long long x;
    cin >> n >> x;
    
    vector<pair<long long, int>> list;
    for(int i = 0; i < n; i++){
        long long m;
        cin >> m;
        list.push_back({m, i + 1});
    }
    
    sort(list.begin(), list.end());
    
    vector<int> v = check_sum_three(n, x, list);
    
    if(v.empty()){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    
    for(int i : v){
        cout << i << " ";
    }
    cout << "\n";
    
    return 0;
}