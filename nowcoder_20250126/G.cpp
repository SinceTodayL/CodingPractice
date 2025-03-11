#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, K;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> K;
    ll L = 0, R = n;
    ll temp_total, value;
    while(L <= R){
        ll total = 0;
        ll mid = (L + R) / 2;
        for(ll l = 1, r; l <= n; l = r + 1){
            r = n / (n / l);
            ll mod = n - (n / l) * l;
            ll k = n / l;
            if(mod < mid)
                continue;
            total += min((mod - mid) / k + 1, r - l + 1);
        }
        if(total >= K){
            L = mid + 1;
        }
        else{
            R = mid - 1;
            temp_total = total;
            value = mid;
        }
    }
    ll ans;
    ans += (K - temp_total) * (value - 1);
    for(ll l = 1, r; l <= n; l = r + 1){
        r = n / (n / l);
        ll mod = n - (n / l) * l;
        ll k = n / l;
        if(mod < value)
            continue;
        ll len = min((mod - value) / k + 1, r - l + 1);
        ans += 1ll * (mod + mod - k * (len - 1)) * len / 2;
    }
    cout << ans << endl;
    return 0;
}