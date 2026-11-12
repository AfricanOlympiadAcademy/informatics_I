#include <bits/stdc++.h>
using namespace std;
int N;
int M;
vector<pair<long long,long long>> interval;
bool solve(long long &mid){
    long long prev = -4e18;
    int count = 0;
    for(auto& i : interval){
        while(max(i.first, prev + mid) <= i.second){
            prev = max(i.first, prev + mid);
            count ++;
            if(count >= N) break;
        }
        
        if(count >= N) break;
    }
    return (count >= N);
}
int main(){
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);
    cin  >> N >> M;
    long long a;
    long long b;
    for(int i  = 0; i < M; i++){
        cin >> a >> b;
        interval.push_back({a,b});
    }
    sort(interval.begin(),interval.end());
    long long low = 1;
    long long highes_possible_interval = 2000000000;
    highes_possible_interval *= highes_possible_interval;
    long long high = highes_possible_interval;
    long long res = -1;
    while(low <= high){
        long long mid = (high + low)/2;
        if(solve(mid)){
            res = mid;
            low = mid +1;
        }
        else{
            high = mid - 1;
        }
    }
    cout << res << endl;
    return 0;
}