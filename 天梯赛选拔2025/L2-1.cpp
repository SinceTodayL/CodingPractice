#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<vector<int>> son;
vector<int> depth;
vector<bool> flag;
void dfs(int index, int d){
    depth[index] = d;
    flag[index] = false;
    for(int s : son[index]){
        if(flag[s])
            dfs(s, d + 1);
    }
}
    
ll solve(int root){
    for(int i = 0; i < n; ++i){
        flag[i] = true;
        depth[i] = 0;
    }
    dfs(root, 0);
    int max_d = 0;
    for(int i = 0; i < n; ++i){
        max_d = max(max_d, depth[i]);
    }
    vector<int> times(max_d + 1, 0);
    for(int i = 0; i < n; ++i){
        times[depth[i]]++;
    }
    ll ans1 = 0, ans2 = 0;
    for(int i = 0; i <= max_d; i += 2){
        ans1 += times[i];
    }
    for(int i = 1; i <= max_d; i += 2){
        ans2 += times[i];
    }
    return min(ans1, ans2);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    son.resize(n);
    depth.resize(n, 0);
    flag.resize(n, true);
    
    int index, num, input;
    for(int i = 0; i < n; ++i){
        cin >> index >> num;
        for(int j = 0; j < num; ++j){
            cin >> input;
            son[index].push_back(input);
            son[input].push_back(index);
        }
    }
    
    ll ans = INT_MAX;
    for(int i = 0; i < n; ++i){
        ans = min(ans, solve(i));
    }
    cout << ans << endl;
    return 0;
}