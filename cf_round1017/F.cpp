    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;

    void solve(){
        int n, m, k;
        cin >> n >> m >> k;
        int cur = 1;
        vector<vector<int>> ans(n + 1, vector<int>(m + 1, 0));
        
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                ans[i][j] = cur;
                cur = cur % k + 1;
            }
        }
        
        if(m % k != 0)
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
        else
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                if(i & 1)
                    cout << ans[i][(j) % (m) + 1] << " ";
                else
                    cout << ans[i][j] << " ";
            }
            cout << endl;
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