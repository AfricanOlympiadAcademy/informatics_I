#include <bits/stdc++.h>
using namespace std;

int cases(int N, int K, vector<int> &diamonds){
    vector<int> counts= {};
    for(int i = 0 ; i < N; i ++){
        counts.push_back(0);
    }
    
    int i = 0;
    int j = 0;
    while(i < N){
        while((j < N) && (diamonds[j] - diamonds[i] <= K)){
            j++;
        }
        counts[i] = j - i;
        i++;
    }
    
    vector<int> max_c= {};
    for(int k = 0 ; k <= N; k ++){
        max_c.push_back(0);
    }
    
    int a = N - 1;
    while(a >= 0){
        if(counts[a] > max_c[a+1]){
            max_c[a] = counts[a];
        }
        else{
            max_c[a] = max_c[a+1];
        }
        a--;
    }
    
    int ans = 0;
    int b = 0;
    while(b < N){
        int p = counts[b] + max_c[b + counts[b]];
        if(p > ans){
            ans = p;
        }
        b++;
    }
    
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    
    int N;
    int K;
    cin >> N >> K;
    
    vector<int> diamonds= {};
    for(int i = 0 ; i < N; i ++){
        int m;
        cin >> m;
        diamonds.push_back(m);
    }
    
    sort(diamonds.begin(),diamonds.end());
    
    int ans = cases(N,K,diamonds);
    cout << ans << "\n";
    
    return 0;
}