#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> nums(n, vector<int>(n, 0));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> nums[i][j];
        }
    }
    unordered_set<int> st;
    vector<int> st2;
    for(int i = 0; i < n; ++i){
        int cnt = 0;
        for(int j = n - 1; j >= 0; --j){
            if(nums[i][j] == 1){
                cnt++;
            }
            else{
                break;
            }
        }
        st2.push_back(cnt);
    }
    sort(st2.begin(), st2.end());
    for(int i = 0; i < n; ++i){
        if(st.find(st2[i]) != st.end()){
            while(st2[i] >= 0){
                if(st.find(st2[i]) == st.end()){
                    st.insert(st2[i]);
                    break;
                }
                st2[i]--;
            }
        }
        else{
            st.insert(st2[i]);
        }
    }
    cout << min(ll(st.size()), n) << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}