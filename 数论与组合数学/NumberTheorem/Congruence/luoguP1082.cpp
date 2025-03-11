#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// 求 ax 和 1 同余于 mod 的最小整数解

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

ll mod_inverse(ll a, ll mod){
    ll x, y;
    ll gcd = extended_gcd(a, mod, x, y);
    return (x % mod + mod) % mod;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll a, mod;
    cin >> a >> mod;
    cout << mod_inverse(a, mod) << endl;

    return 0;
}