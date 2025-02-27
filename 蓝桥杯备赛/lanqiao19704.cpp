#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
const int N = 200010;
int c[N];
int d[N];
int ans = 0;
unordered_map<int, vector<int>> mp1, mp2;

void dfs(int x, int y, int count){
    if(c[x] != d[y]){
        return;
    }
    ans = max(count + 1, ans);
    for(int i = 0; i < mp1[x].size(); ++i){
        for(int j = 0; j < mp2[y].size(); ++j){
            int a = mp1[x][i], b = mp2[y][j];
            dfs(a, b, count + 1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> c[i];
    }
    for(int i = 1; i <= m; ++i){
        cin >> d[i];
    }
    int u, v;
    for(int i = 1; i <= n - 1; ++i){
        cin >> u >> v;
        if(u > v){
            swap(u, v);
        }
        mp1[u].push_back(v);
    }
    for(int i = 1; i <= m - 1; ++i){
        cin >> u >> v;
        if(u > v){
            swap(u, v);
        }
        mp2[u].push_back(v);
    }
    dfs(1, 1, 0);
    cout << ans << endl;
    return 0;
}