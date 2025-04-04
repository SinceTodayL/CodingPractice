#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll x, ll y){
    return y == 0 ? x : gcd(y, x % y);
}

void solve(){
    ll n, k;
    cin >> n >> k;
    vector<ll> nums(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> nums[i];
    }
    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(2, vector<ll>(2, 0)));
    dp[1][0][0] = nums[1];
    dp[1][0][1] = nums[1];
    dp[1][1][0] = nums[1] + k;
    dp[1][1][1] = nums[1] + k;
    for(int i = 2; i <= n; ++i){
        dp[i][0][0] = gcd(dp[i - 1][0][0], nums[i]);
        dp[i][0][1] = max(gcd(dp[i - 1][0][1], nums[i]), gcd(dp[i - 1][1][0], nums[i]));
        dp[i][1][0] = max(gcd(dp[i - 1][0][0], nums[i] + k), gcd(dp[i - 1][1][0], nums[i] + k));
    }
    cout << max(dp[n][1][0], dp[n][0][1]) << endl;
    /*
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < 2; ++j){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */
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