#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> edge;
vector<ll> f;
vector<ll> value;

void dfs(int cur, int father){
    f[cur] = value[cur];
    for(int i = 0; i < edge[cur].size(); ++i){
        int t = edge[cur][i];
        if(t != father){
            dfs(t, cur);
            if(f[t] > 0){
                f[cur] += f[t];
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    edge.resize(n + 1);
    f.resize(n + 1);
    value.resize(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> value[i];
    }
    int x, y;
    for(int i = 1; i <= n - 1; ++i){
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    ll ans = INT_MIN;
    dfs(1, 0);
    for(int i = 1; i <= n; ++i){
        ans = max(ans, f[i]);
    }
    cout << ans << endl;

    return 0;
}