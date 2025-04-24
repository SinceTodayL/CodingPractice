#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> color(n, vector<int>(m, 0));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> color[i][j];
        }
    }
    unordered_map<int, int> mp;
    int count = 0;
    bool flag = false;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            mp[color[i][j]] = max(mp[color[i][j]], 1);
            if(i > 0 && color[i - 1][j] == color[i][j] ||
               i < n - 1 && color[i + 1][j] == color[i][j] ||
               j > 0 && color[i][j - 1] == color[i][j] ||
               j < m - 1 && color[i][j + 1] == color[i][j]){
                flag = true;
                mp[color[i][j]] = max(mp[color[i][j]], 2);
            }
        }
    }       
    for(auto p : mp){
        count += p.second;
    }
    cout << count - 1 - flag << '\n';                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
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