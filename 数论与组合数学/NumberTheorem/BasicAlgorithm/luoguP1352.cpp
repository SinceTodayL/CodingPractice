// 洛谷P1352 没有上司的舞会（树上DP经典）
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 6010;
int n;
int value[N];
vector<vector<int>> son(N);
int f[N][2];  // 第二个dim ：如果为1则代表参加，反之不参加；
int ans = 0;
int Root = 0;
vector<bool> flag(N+1, false);

void solve(int root){
    f[root][0] = 0;
    f[root][1] = value[root];
    for(int sons:son[root]){
        solve(sons);
        f[root][0] += max(f[sons][0], f[sons][1]);
        f[root][1] += f[sons][0];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> value[i];
    }
    int l, k;
    for(int i = 1; i <= n - 1; ++i){
        cin >> l >> k;
        son[k].push_back(l);
        flag[l] = true;
    }
    for(int i = 1; i <= n; ++i){
        if(!flag[i]){
            Root = i;
            break;
        }
    }
    
    solve(Root);
    cout << max(f[Root][0], f[Root][1]) << endl;
    return 0;
}