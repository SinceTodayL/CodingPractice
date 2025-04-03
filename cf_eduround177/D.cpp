#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int mod = 998244353;
const int M = 500000;
 
vector<ll> fac(M+1), invfac(M+1);
 
ll fp(ll a, ll x){
    ll res  = 1;
    while(x){
        if(x & 1) 
            res = res * a % mod;
        a = a * a % mod;
        x >>= 1;
    }
    return res;
}
 
void init(){
    fac[0] = 1;
    for(int i = 1; i <= M; i++){
        fac[i] = fac[i-1] * i % mod;
    }
    invfac[M] = fp(fac[M], mod-2);
    for(int i = M; i > 0; i--){
        invfac[i-1] = invfac[i] * i % mod;
    }
}
 
void solve(){
    vector<int> cnt(26);
    ll sum= 0;
    for(int i = 0; i < 26; i++){
        cin >> cnt[i];
        sum += cnt[i];
    }
    int odd = 0, even = 0;
    if(sum & 1){
        odd = sum/2 + 1;
        even = sum - odd;
    }
    else{
        odd = sum/2;
        even = sum/2;
    }
    vector<int> letter;
    for(int i = 0; i < 26; i++){
        if(cnt[i] > 0) 
            letter.push_back(cnt[i]);
    }
    vector<ll> dp1(odd+1, 0), dp2(odd+1, 0);
    dp1[0] = 1;
    for(int x : letter){
        for(int i = 0; i < dp2.size(); ++i){
            dp2[i] = 0;
        }
        for(int j = 0; j <= odd; j++){
            if(dp1[j]){
                dp2[j] = (dp2[j] + dp1[j]) % mod;
                if(j + x <= odd) 
                    dp2[j+x] = (dp2[j+x] + dp1[j]) % mod;
            }
        }
        swap(dp1, dp2);
    }

    ll combine = dp1[odd];
    ll all = fac[odd] * fac[even] % mod;
    for(int i = 0; i < 26; i++){
        if(cnt[i] > 0) 
            all = all * invfac[cnt[i]] % mod;
    }
    ll result = combine * all % mod;
    cout << result << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    init();
    while(t--){
        solve();
    }
    return 0;
}
