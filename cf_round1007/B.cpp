#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n;
    cin >> n;
    ll temp = static_cast<ll>(sqrt(((n * (n + 1)) / 2)));
    if(temp * temp == (n * (n + 1)) / 2){
        cout << -1 << endl;
    }
    else{
        vector<ll> ans(n + 2, 0);
        for(ll i = 1; i <= n + 1; ++i){
            ans[i] = i;
        }
        for(ll i = 1; i <= n; ++i){
            ll temp = static_cast<ll>(sqrt(((i * (i + 1)) / 2)));
            if(temp * temp == (i * (i + 1)) / 2){
                swap(ans[i + 1], ans[i]);
            }
        }
        for(ll i = 1; i <= n; ++i){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
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