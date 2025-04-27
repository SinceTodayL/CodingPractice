#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 998244353;

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n + 1, 0);
    for(int i = 1; i <= n; ++i){
        cin >> nums[i];
    }
    ll ans = 0, pre2 = 0, pre3 = 0;
    for(int i = 1; i <= n; ++i){
        if(nums[i] == 1){
            pre2 = (pre2 + 1) % mod;
        }
        else if(nums[i] == 2){
            pre3 = (pre3 + pre2) % mod;
            pre2 = (pre2 * 2) % mod;
        }
        else{
            ans = (ans + pre3) % mod;
        }
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