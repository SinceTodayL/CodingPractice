#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> ans(n);
    x = min(n - 1, x);
    for(int i = 0; i < x; ++i){
        ans[i] = i;
    }
    for(int i = x + 1; i < n; ++i){
        ans[i - 1] = i;
    }
    ans[n - 1] = x;
    for(int i = 0; i < n; ++i){
        cout << ans[i] << " \n"[i == n - 1];
    }
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