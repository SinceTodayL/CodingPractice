#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll x, y;
    cin >> x >> y;
    if(x == y){
        cout << -1 << endl;
        return;
    }
    ll max_bit = max(64 - __builtin_clzll(x), 64 - __builtin_clzll(y)); 
    ll ans = 1;
    for(int i = 1; i <= max_bit + 1; ++i){
        ans *= 2;
    }
    cout << ans - max(x, y) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
