#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(int n, int dp, vector<int>& depth, const vector<vector<int>>& g, vector<bool>& flag){
    flag[n] = true;
    for(int ele : g[n]){
        if(!flag[ele])
        {   depth[ele] = min(depth[ele], dp + 1);
            dfs(ele, dp + 1, depth, g, flag);}
    }
}

void solve(){
    ll n, st, en;
    cin >> n >> st >> en;
    vector<vector<int>> g(n + 1);
    int t1, t2;
    for(int i = 1; i < n; ++i){
        cin >> t1 >> t2;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }    

    vector<int> depth(n + 1, INT_MAX);
    vector<bool> flag(n + 1, false);
    depth[en] = 0;
    dfs(en, 0, depth, g, flag);

    int max_dp = 0;
    for(int i = 1; i <= n; ++i){
        max_dp = max(max_dp, depth[i]);
    }
    vector<vector<int>> res(max_dp + 1);
    for(int i = 1; i <= n; ++i){
        res[depth[i]].push_back(i);
    }
    for(int i = max_dp; i >= 0; --i){
        for(int ele : res[i]){
            cout << ele << " ";
        }
    }
    cout << endl;
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