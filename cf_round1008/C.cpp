#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> left, right;
int n;

void dfs(int x){
    if(x < n){
        for(int i = )
    }
}

void solve(){
    cin >> n;
    vector<ll> nums(2 * n);
    set<ll> st;
    left.resize(n);
    right.resize(n);
    for(int i = 0; i < 2 * n; ++i){
        cin >> nums[i];
        st.insert(nums[i]);
    }
    sort(nums.begin(), nums.end());
    

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