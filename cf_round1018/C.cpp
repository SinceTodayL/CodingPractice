#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> nums(n + 1, vector<int>(n + 1, 0));
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> nums[i][j];
        }
    }
    vector<vector<int>> row(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> col(n + 1, vector<int>(n + 1, 0));
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            row[i][j] = nums[i][j] - nums[i][j - 1];
        }
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            row[j][i] = nums[j][i] - nums[j - 1][i];
        }
    }
    vector<int> score_row(n + 1, 0);
    vector<int> score_col(n + 1, 0);
    for(int i = 1; i <= n; ++i){
        cin >> score_row[i];
    }
    for(int i = 1; i <= n; ++i){
        cin >> score_col[i];
    }
    ll ans = 0;
    vector<bool> plus(n + 2, true);
    vector<bool> minus(n + 2, true);
    vector<bool> zero(n + 2, false);
    for(int i = 1; i <= n; ++i){
        int cnt1 = 0, cnt2 = 0, cnt0 = 0;  // 1 : 1; 2 : -1
        for(int j = 1; j <= n; ++j){
            if(row[i][j] == 1)
                cnt1++;
            if(row[i][j] == -1)
                cnt2++;
            if(row[i][j] == 0)
                cnt0++;
        }
        if(cnt1 && cnt2 && cnt3){
            cout << -1 << endl;
            return;
        }
        if(cnt0)
            zero[i] = true;
        if(cnt1)
            minus[i] = false;
        if(cnt2)
            plus[i] = false;
    }
    plus[0] = false;
    vector<vector<ll>> dp(n + 1, vector<ll>(2, INT_MAX));
    dp[0][1] = dp[0][0] = 0;
    for(int i = 1; i <= n; ++i){
        if(zero[i]){
            if(plus[])
        }
        else{
            dp[i][0] = dp[i - 1][0];
            if(plus[i]){
                dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + score_row[i];
            }
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