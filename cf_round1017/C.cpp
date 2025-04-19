#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> nums(n, vector<int>(n, 0));
    set<int> st;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> nums[i][j];
            st.insert(nums[i][j]);
        }
    }
    vector<int> ans;
    for(int i = 1; i <= 2 * n; ++i){
        if(st.find(i) == st.end()){
            ans.push_back(i);
            break;
        }
    }
    for(int i = 0; i < n; ++i){
        ans.push_back(nums[i][0]);
    }
    for(int i = 1; i < n; ++i){
        ans.push_back(nums[n - 1][i]);
    }
    for(int i = 0; i < 2 * n; ++i){
        cout << ans[i] << " ";
    }
    cout << endl;
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