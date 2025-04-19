#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 998244353;

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n + 1, 0);
    for(int i = 1; i <= n; ++i){
        cin >> nums[i];
    }
    // vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    vector<int> dp(n + 1, 0);
    if(nums[1] == 0){
        dp[1] = 1;
    }
    else{
        dp[1] = 0;
    }
    dp[0] = 1;
    for(int i = 2; i <= n; ++i){
        if(nums[i] == nums[i - 1]){
            dp[i] = (dp[i] + dp[i - 1]) % mod;
        }
        if(nums[i] == nums[i - 2] + 1){
            dp[i] = (dp[i] + dp[i - 2]) % mod;
        }
    }
    
    cout << (dp[n] + dp[n - 1]) % mod << endl;
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