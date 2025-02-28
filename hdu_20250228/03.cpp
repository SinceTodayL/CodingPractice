#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n;
    ll sum_a = 0;
    ll sum_b = 0;
    ll sum_c = 0;
    cin >> n;
    ll input;
    for(int i = 1; i <= n; ++i){
        cin >> input;
        sum_a += input;
    }
    for(int i = 1; i <= n; ++i){
        cin >> input;
        sum_b += input;
    }
    for(int i = 1; i <= n; ++i){
        cin >> input;
        sum_c += input;
    }

    ll res = (sum_c - sum_b) / sum_a;
    cout << res << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}