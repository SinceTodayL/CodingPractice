#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
int cnt = 0;
int ans = INT_MAX;
vector<string> nums;
vector<vector<int>> flag;
vector<vector<bool>> path;
void dfs(int i, int j){
    // path[i][j] = true;
    // cout << i << " " << j << endl;
    if(nums[i][j] == '0'){
        if(!path[i][j])
            cnt++;
        path[i][j] = true;
        // cout << "cnt++" << endl;
        return;
    }
    flag[i][j] = 0;
    path[i][j] = true;
    if(i > 0){
        // cout << 1 << endl;
        if(!path[i - 1][j]){
            // path[i - 1][j] = true;
            dfs(i-1, j);
        }
    }
    if(i < n - 1){
       // cout << 2 << endl;
        if(!path[i + 1][j]){
            // path[i + 1][j] = true;
            dfs(i+1, j);
        }
    }
    if(j > 0){
       // cout << 3 << endl;
        if(!path[i][j-1]){
            //  path[i][j-1] = true;
            dfs(i, j-1);
        }
    }
    if(j < m - 1){
        //cout << 4 << endl;
        if(!path[i][j+1]){
            // path[i][j+1] = true;
            dfs(i, j+1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    nums.resize(n);
    flag.resize(n);
    path.resize(n);
    for(int i = 0; i < n; ++i){
        cin >> nums[i];
        flag[i].resize(m);
        path[i].resize(m);
        for(int j = 0; j < m; ++j){
            if(nums[i][j] == '1'){
                flag[i][j] = 1;
            }
            else{
                flag[i][j] = 0;
            }
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(flag[i][j] && nums[i][j] == '1'){
                cnt = 0;
                for(int i = 0; i < n; ++i){
                    fill(path[i].begin(), path[i].end(), false);
                }
                dfs(i, j);
                // cout << "cnt:" << cnt << endl;
                ans = min(ans, cnt);
            }
        }
    }
    

    cout << ans << endl;
    return 0;
}