#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, l, r;
    cin >> n >> l >> r;
    ll len_mid = r - l + 1;
    vector<ll> nums(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> nums[i];
    }
    ll ans1 = 0, ans2 = 0;
    vector<ll> left = nums;
    sort(left.begin() + 1, left.begin() + r + 1);
    for(int i = 1; i <= len_mid; ++i){
        ans1 += left[i];
    }
    vector<ll> right = nums;
    sort(right.begin() + l, right.end());
    for(int i = l; i < l + len_mid; ++i){
        ans2 += right[i];
    }
    cout << min(ans1, ans2) << endl;

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