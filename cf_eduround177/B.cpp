#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, k, x;
    cin >> n >> k >> x;
    vector<ll> nums(n);
    ll sum_num = 0;
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
        sum_num += nums[i];
    }
    ll row, col = 0;
    row = x / sum_num;
    if(x % sum_num == 0){
        cout << max(0ll, n * k - (row * n) + 1) << '\n';
        return;
    }
    ll left = x - row * sum_num;
    for(int i = n - 1; i >= 0; --i){
        left -= nums[i];
        if(left > 0){
            col++;
        }
        else{
            break;
        }
    }
    ll temp = row * n + col;
    ll ans = max(0ll, n * k - temp);
    cout << ans << '\n';
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