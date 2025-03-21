#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1510;
vector<int> edge[N];
int ans[N][2];  

void dfs(int cur, int fa){
    ans[cur][1] = 1;
    for(int i = 0; i < edge[cur].size(); ++i){
        int v = edge[cur][i];
        if(v == fa){
            continue;
        }
        dfs(v, cur);
        ans[cur][1] += min(ans[v][1], ans[v][0]);
        ans[cur][0] += ans[v][1];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int index, number, x;
    for(int i = 1; i <= n; ++i){
        cin >> index >> number;
        for(int j = 1; j <= number; ++j){
            cin >> x;
            edge[index].push_back(x);
            edge[x].push_back(index);
        }
    }
    dfs(0, -1);

    
    cout << min(ans[0][0], ans[0][1]) << endl;

    return 0;
}