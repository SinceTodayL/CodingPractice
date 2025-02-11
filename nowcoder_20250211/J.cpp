#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, x, y;
ll cal(ll k){
    ll ans1 = - (k * k) + k * (n - x - 1);
    ll temp = - n + k + x + y;
    if(temp < 0){
        ans1 += (temp * (temp - 1)) / 2;
    }
    return ans1;
}
ll Search() {
    ll low = 0, high = y;
    ll ans = cal(0);
    for(ll k = low; k <= high; k++){
        //cout << ans << " ";
        ans = max(ans, cal(k));
    }
    //cout << endl;
    return ans;
}

void solve(){
    cin >> n >> x >> y;
    if(y >= n){
        ll ans = 0;
        for(int i = 0; i < n; ++i){
            ll temp = (x + i + 1) * (n - i);
            ans = max(ans, temp);
        }
        cout << ans << endl;
        return;
    }
    ll ans = x * n + y - ((n - y) * (n - y - 1)) / 2;
    ans += Search();
    // cout << "res" << Search() << endl;
    if(n >= x + 2 * y){
        ans =((x + y) * (x + y + 1)) / 2;
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