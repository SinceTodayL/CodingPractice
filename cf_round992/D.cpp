#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 400010;
vector<bool> is_prime(N + 2, true);
void init(){
    is_prime[1] = false;
    for(int i = 2; i * i <= N; ++i){
        if(is_prime[i]){
            for(int j = i * i; j <= N; j += i){
                is_prime[j] = false;
            }
        }
    }
}

void dfs(const vector<vector<int>>& edge, vector<int>& ans, int father, int cur, int& now ,vector<bool>& mp){
    for(int d : edge[cur]){
        if(d == father){
            continue;
        }
        int st = now;
        if(!is_prime[abs(now - ans[cur])]){
            mp[now] = true;
            ans[d] = now; 
            while(mp[now]){
                now++;
            }
            dfs(edge, ans, cur, d, now, mp);
            continue;
        }
        while(is_prime[abs(st - ans[cur])] || (!is_prime[abs(st - ans[cur])] && mp[st] == true)){
            st++;
        }
        mp[st] = true;
        ans[d] = st;
        dfs(edge, ans, cur, d, now, mp);
    }
}

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> edge(n + 1);
    int u, v;
    for(int i = 1; i <= n - 1; ++i){
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    vector<int> ans(n + 1, 0);
    ans[0] = 0;
    ans[1] = 1;
    edge[0].push_back(1);
    vector<bool> mp(2*n + 1, false);
    mp[1] = true;
    for(int i = 1; i <= 2 * n; ++i){
        mp[i] = false;
    }
    int now = 2;
    dfs(edge, ans, 0, 1, now, mp);
    for(int i = 1; i <= n; ++i){
        cout << ans[i] << " \n"[i == n];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}