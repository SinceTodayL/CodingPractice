#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
const int N = 2510;
double s[N], p[N];
vector<int> G[N];
double f[N][N], value[N];
int dfn[N], sz[N];
int cnt;

void dfs(int u, int fa){
    dfn[++cnt] = u;
    sz[u] = 1;
    for(int i = 0; i < G[u].size(); ++i){
        int v = G[u][i];
        if(v == fa){
            continue;
        }
        dfs(v, u);
        sz[u] += sz[v];
    }
}

bool check(double x){
    for(int i = 1; i <= n + 2; ++i){
        for(int j = 1; j <= k + 1; ++j){
            f[i][j] = INT_MIN;
        }
    }
    for(int i = 1; i <= n; ++i){
        value[i] = p[i] - x * s[i];
    }
    for(int i = n + 1; i >= 1; --i){
        for(int j = 1; j <= k + 1; ++j){
            f[i][j] = max(f[i][j], f[i + 1][j - 1] + value[dfn[i]]);
            f[i][j] = max(f[i][j], f[i + sz[dfn[i]]][j - 1] + value[dfn[i]]);
            f[i][j] = max(f[i][j], f[i + sz[dfn[i]]][j]);

        }
    }
    return f[1][k + 1] > 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> n;
    int x;
    for(int i = 1; i <= n; ++i){
        cin >> s[i] >> p[i] >> x;
        G[x].push_back(i);
        G[i].push_back(x);
    }
    dfs(0, 0);
    double l = 0, r = 1e8, mid;
    while(r - l > 1e-4){
        mid = (l + r) / 2;
        if(check(mid)){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    cout << fixed << setprecision(3) << l << endl;
    return 0;
}