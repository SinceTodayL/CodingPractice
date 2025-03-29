    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    
    const ll mod = 998244353;
    int n, m, d;
    
    void solve(){
        cin >> n >> m >> d;
        vector<string> s(n);
        vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(m + 1, vector<ll>(2, 0)));
        vector<vector<vector<ll>>> prefix_dp(n, vector<vector<ll>>(m + 1, vector<ll>(2, 0)));
    
        for(int i = 0; i < n; ++i){
            cin >> s[i];
            s[i] = " " + s[i];
        }
    
        dp[n - 1][0][0] = (s[n - 1][0] == 'X' ? 1 : 0);
    
        for(int i = 1; i <= m; ++i){
            if(s[n - 1][i] == 'X'){
                dp[n - 1][i][0] = 1;
            }
            prefix_dp[n - 1][i][0] = (prefix_dp[n - 1][i - 1][0] + dp[n - 1][i][0]) % mod;
        }
    
        for(int i = 1; i <= m; ++i){
            if(s[n - 1][i] == 'X'){
                dp[n - 1][i][1] = prefix_dp[n - 1][min(m, i + d)][0] - prefix_dp[n - 1][max(i - d - 1, 0)][0] - dp[n - 1][i][0];
            }
            prefix_dp[n - 1][i][1] = (prefix_dp[n - 1][i - 1][1] + dp[n - 1][i][1]) % mod;
        }
    
        for(int i = n - 2; i >= 0; --i){
            for(int j = 1; j <= m; ++j){
                if(s[i][j] == 'X'){
                    dp[i][j][0] = (((prefix_dp[i + 1][min(m, j + d - 1)][0] - prefix_dp[i + 1][max(j - d, 0)][0]) % mod) % mod + 
                                ((prefix_dp[i + 1][min(m, j + d - 1)][1] - prefix_dp[i + 1][max(j - d, 0)][1]) % mod) % mod) % mod;
                }
                prefix_dp[i][j][0] = (prefix_dp[i][j - 1][0] + dp[i][j][0]) % mod;
            }
    
            for(int j = 1; j <= m; ++j){
                if(s[i][j] == 'X'){
                    dp[i][j][1] = ((prefix_dp[i][min(m, j + d)][0] - prefix_dp[i][max(j - d - 1, 0)][0] - dp[i][j][0]) % mod + mod) % mod;
                }
                prefix_dp[i][j][1] = (prefix_dp[i][j - 1][1] + dp[i][j][1]) % mod;
            }
        }
    
        ll ans = 0;
        for(int i = 1; i <= m; ++i){
            if(s[0][i] == 'X'){
                ans = (ans + dp[0][i][0] + dp[0][i][1]) % mod;
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