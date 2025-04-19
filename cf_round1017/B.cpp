#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n, m, l ,r;
    cin >> n >> m >> l >> r;
    int l1 = 0, r1 = 0;
    l1 = max(-m, l);
    r1 = m + l1;
    cout << l1 << " " << r1 << endl;
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