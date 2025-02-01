#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

inline ll gcd(ll x, ll y){
    return y == 0 ? x : gcd(y, x % y);
}

void solve(int t){
    ll n, a, b;
    cin >> n >> a >> b;
    ll cnt = n / gcd(a, b);
    if(cnt & 1){
        cout << "Case #" << t << ": " << "Yuwgna" << endl;
    }
    else{
        cout << "Case #" << t << ": " << "Iaka" << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i){
        solve(i);
    }

    return 0;
}