#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    int p = (k + n - 1) / n;
    int ans = (m) / (m - p + 1);
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