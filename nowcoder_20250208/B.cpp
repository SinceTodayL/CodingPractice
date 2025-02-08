#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n, t, k;
    cin >> n >> t >> k;
    int cnt = (n - k) / t;
    int ans = min(k + 1, cnt);
    cout << ans << endl;
    
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