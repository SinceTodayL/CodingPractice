#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> l(n), r(n), s;
    for(int i = 0; i < n; ++i){
        cin >> l[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> r[i];
    }
    ll ans = 0;
    for(int i = 0; i < n; ++i){
        ans += max(l[i], r[i]);
        s.push_back(min(l[i], r[i]));
    }
    sort(s.begin(), s.end());
    for(int i = n - 1; i >= n - k + 1; --i){
        ans += s[i];
    }
    cout << ans + 1 << endl;
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