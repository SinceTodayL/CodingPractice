#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll x, y, n, m, L;
    cin >> x >> y >> m >> n >> L;
    ll a = n - m;
    ll c = x - y;
    if(a < 0){
        a = -a;
        c = -c;
    }
    ll d = extended_gcd(a, L, x, y);
    if(c % d != 0){
        cout << "impossible" << endl;
    }
    else{
        x *= (c / d);
        x = (x % (L / d) + (L / d)) % (L / d);
        cout << x << endl;
    }

    return 0;
}