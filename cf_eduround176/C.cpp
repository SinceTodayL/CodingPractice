#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void solve(){
    ll n, m;
    cin >> n >> m;
    vector<ll> nums(m);
    for(ll i = 0; i < m; ++i){
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    ll ans = 0;
    for(ll i = 1; i < n; ++i){
        int x = nums.end() - lower_bound(nums.begin(), nums.end(), i);
        int y = nums.end() - lower_bound(nums.begin(), nums.end(), n - i);
        ans += (x * y - min(x, y));
    }
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}