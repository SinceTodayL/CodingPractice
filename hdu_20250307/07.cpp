#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;

void solve(){
    ll n;
    cin >> n;
    ll ans = 0;
    ll temp = n / 2;
    ans = temp * (temp + 1);
    cout << ans % mod << endl;
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