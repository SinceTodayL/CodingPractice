#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    unordered_map<int, int> mp;
    for(int i = 1; i <= n; ++i){
        mp[a[i]]++;
    }
    int max_ele = 0;
    for(auto ele : mp){
        max_ele = max(max_ele, ele.second);
    }
    cout << n - max_ele << endl;
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