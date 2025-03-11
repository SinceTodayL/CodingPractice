#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k;
void solve(){
    ll l = 0, r = 0, ans = n * k;
    for(l = 1; l <= min(n, k); l = r + 1){
        r = min(k / (k / l), n);
        ans -= ((k / l) * ((l + r) * (r - l + 1)) / 2);
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    solve();

    return 0;
}