#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2505;

int k, n;
vector<vector<int>> relations(N);
struct node{
    int cost, value;
    double y;
}a[N];
double dp[N][N];

// TLE
/*
void dfs(int root){
    dp[root][0] = 0;
    for(int i = 0; i < relations[root].size(); ++i){
        int son = relations[root][i];
        dfs(son);
        for(int j = k; j >= 0; --j){
            for(int t = 0; t <= j; ++t){
                dp[root][j] = max(dp[root][j], dp[root][j - t] + dp[son][t]);  // 深入理解这个式子！
            }
        }
    }
    if(root){
        for(int i = k; i > 0; --i){
            dp[root][i] = dp[root][i - 1] + a[root].y;
        }
    }
}

bool check(double x){
    for(int i = 0; i <= n; ++i){
        a[i].y = - a[i].cost * x + a[i].value * 1.0; 
    }
    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= k; ++j){
            dp[i][j] = -1e9;
        }
    }
    dfs(0);
    return dp[0][k] > 1e-6;
}
*/

int son_nums[N];
int pos[N];
int cnt = 0;
void dfs(int root){
    son_nums[root] += 1;
    for(int i = 0; i < relations[root].size(); ++i){
        int son = relations[root][i];
        dfs(son);
        son_nums[root] += son_nums[son];
    }
    pos[++cnt] = root;
}

bool check(double x){
    for(int i = 0; i <= n; ++i){
        a[i].y = -a[i].cost*x + a[i].value;
    }
    for(int i = 0; i <= cnt; ++i){
        for(int j = 0; j <= k + 1; ++j){
            dp[i][j] = -1e9;
        }
    }
    dp[0][0] = 0;
    for(int i = 1; i <= cnt; ++i){
        for(int j = 1; j <= k + 1; ++j){
            dp[i][j] = max(dp[i-1][j], dp[i-son_nums[pos[i]]][j-1] + a[pos[i]].y);
        }
    }
    for(int i = 0; i <= cnt; ++i){
        for(int j = 0; j <= k + 1; ++j){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[cnt][k+1] >= 1e-6;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int temp = 0;
    cnt = 0;
    double l = 0, r = 0;
    cin >> k >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i].cost >> a[i].value >> temp;
        r += a[i].value;
        relations[temp].push_back(i);
    }
    dfs(0);
    while(fabs(l - r) > 1e-4){
        double mid = (l + r) / 2;
        if(check(mid)){
            l = mid;
        }
        else{
            r = mid;
        }

    }
    printf("%.3f\n", l);
    return 0;
}