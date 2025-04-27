#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 2e18 + 10;

void solve(){
    ll n, k, m, a, b;
    cin >> n >> k >> m >> a >> b;
    vector<ll> powk;
    vector<ll> divk;
    if(k == 1){
        cout << (n % m == 0 ? 0 : -1) << '\n';
        return;
    }
    ll cur = 1;
    for(int i = 0; i < 65; ++i){
        powk.push_back(cur);
        if(cur >= N / k) break;
        cur *= k;
    }
    cur = n;
    while(cur >= 1){
        divk.push_back(cur);
        cur /= k;
    }
    divk.push_back(0);

    ll ans = N;
    int s1 = powk.size(), s2 = divk.size();
    for(int i = 0; i < s2; ++i){
        ll cur_n = divk[i];
        for(int j = 0; j < s1; ++j){
            // —— 改动1：用 (cur_n%m)*(powk[j]%m)%m 来代替直接相乘，绝对不会溢出 —— 
            ll Mod = (cur_n % m) * (powk[j] % m) % m;
            if(Mod == 0 || Mod + powk[j] - 1 >= m){
                ans = min(ans, i * b + j * a);
            }
        }
    }
    cout << ans << endl;
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
