#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(vector<int>& nums, int n, int k, int mid){
    int cnt = 0;
    unordered_set<int> st;
    for(int i = 0; i < n; ++i){
        if(nums[i] < mid){
            st.insert(nums[i]);
        }
        if(st.size() == mid){
            st.clear();
            cnt++;
        }
    }
    return cnt >= k;
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    int l = 0, r = n / k;
    int mid;
    while(l < r){
        mid = ((l + r) >> 1) + 1;
        if(check(a, n, k, mid)){
            l = mid;
        }
        else{
            r = mid - 1;
        }
    }
    cout << l << endl;
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