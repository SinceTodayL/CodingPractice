#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fp(ll a, ll n){
    if(n < 1){
        return 0;
    }
    ll ans = 1;
    while(n){
        if(n & 1){
            ans *= a;
        }
        a *= a;
        n >>= 1;
    }
    return ans;
}

void solve(){
    ll n, m;
    cin >> n >> m;
    if(m == 1){
        cout << 1 << endl;
        return;
    }
    double ans = log(n) / log(m);
    ll cnt = static_cast<int>(ans);
    ll ans1 = abs(fp(m, cnt - 1) - n);
    ll ans2 = abs(fp(m, cnt) - n);
    ll ans3 = abs(fp(m, cnt + 1) - n);
    if(ans1 < ans2){
        if(ans1 <= ans3){
            cout << cnt - 1 << endl;
        }
        else{
            cout << cnt + 1 << endl;
        }
    }
    else{
        if(ans2 <= ans3){
            cout << cnt << endl;
        }
        else{
            cout << cnt + 1 << endl;
        }
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