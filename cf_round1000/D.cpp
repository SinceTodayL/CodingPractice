#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, m;
    cin >> n >> m;
    vector<ll> numa(n + 1);
    vector<ll> numb(m + 1);
    for(int i = 1; i <= n; ++i){
        cin >> numa[i];
    }
    for(int i = 1; i <= m; ++i){
        cin >> numb[i];
    }
    sort(numa.begin() + 1, numa.end());
    sort(numb.begin() + 1, numb.end());
    vector<ll> suma(n + 1, 0);
    vector<ll> sumb(m + 1, 0);
    for(ll i = 1; i <= n - 1; ++i){
        suma[i] = suma[i - 1] + (numa[n - i + 1] - numa[i]);
    }
    for(ll i = 1; i <= m - 1; ++i){
        sumb[i] = sumb[i - 1] + (numb[m - i + 1] - numb[i]);
    }
    vector<ll> ans;
    for(ll x = 1; x <= (n + m) / 3 + 2; ++x){
        ll l = max(0ll, 2 * x - m), r = min(x, n - x);
        if(l > r){
            break;
        }
        auto f = [&](ll ka){return suma[ka] + sumb[x - ka];};
        while(r - l > 3){
            ll ml = (2 * l + r) / 3;
            ll mr = (l + 2 * r) / 3;
            if(f(ml) > f(mr)){
                r = mr;
            }
            else{
                l = ml;
            }
        }
        ll mans = 0;
        for(ll i = l; i <= r; ++i){
            mans = max(mans, f(i));
        }
        ans.push_back(mans);
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); ++i){
        cout << ans[i] << " ";
    }
    cout << endl;
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