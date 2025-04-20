#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


ll n, ans = 0;

ll count(ll L, ll R) {
    auto f = [](ll x, ll d) { return x / d; };
    return (f(R,2)-f(L-1,2)) + (f(R,5)-f(L-1,5)) - (f(R,10)-f(L-1,10));
}


vector<ll> f2, f5, f;
ll cal(ll x){
    ll s = 0;
    ll l, r;
    for(l = 1; l <= x; l = r + 1){
        r = n / (n / l);
        ll a = count(l, min(r, x));
        if(r < x)
            s += (r - l + 1 - a) * (n / l);
        else{
            s += (x - l + 1 - a) * (n / l);
            break;
        }
        //cout << l << " " << r << " " << s << endl;
    }
    /*
    for(int i = 1; i < f.size(); ++i){
        if(f[i] <= x){
            s -= (n / f[i]);
        }
    }
    */
    return s;
}

void factor(){
    ll a = 1;
    while(a <= n){
        f2.push_back(a);
        a *= 2;
    }
    a = 1;
    while(a <= n){
        f5.push_back(a);
        a *= 5;
        // cout << a << endl;
    }
    for(ll i : f2){
        for(ll j : f5){
            if(i * j <= n)
                f.push_back(i * j);
            // cout << i << endl;
        }
    }
    sort(f.begin(), f.end());
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    factor();
    for(ll i = 0; i < f.size(); ++i){
        ans += cal(n / f[i]);
        //cout << ans << endl;
    }
    cout << ans << endl;

    return 0;
}