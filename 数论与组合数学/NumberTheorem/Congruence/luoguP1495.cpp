#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 11;
int n;
ll mod[N];
ll mmod[N];
ll a[N];

ll multi(ll a, ll b, ll Mod){
    ll ans = 0;
    while(b > 0){
        if(b & 1){
            ans = (ans + a) % Mod;
        }
        a = (a + a) % Mod;
        b >>= 1;
    }
    return ans;
}

ll extended_gcd(ll a, ll b, ll& x, ll& y){
    if(!b){
        x = 1;
        y = 0;
        return a;
    }
    ll gcd = extended_gcd(b, a % b, y, x);
    y -= (a / b) * x;
    return gcd;
}

ll inverse(ll b, ll Mod){
    ll x, y;
    extended_gcd(Mod, b, x, y);
    return (y % Mod + Mod) % Mod;
}

ll crt(){
    ll M = 1;
    for(int i = 1; i <= n; ++i){
        M *= mod[i];
    }
    for(int i = 1; i <= n; ++i){
        mmod[i] = M / mod[i];
    }
    long long ans = 0;
    for(int i = 1; i <= n; ++i){
        long long term = (a[i] * mmod[i]) % M;
        term = multi(term , inverse(mmod[i], mod[i]), M) % M; 
        ans = (ans + term) % M; 
    }
    return ans % M;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> mod[i] >> a[i];
    }
    cout << crt() << endl;
    return 0;
}