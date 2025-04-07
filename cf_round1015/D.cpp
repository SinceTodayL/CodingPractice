#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < n; ++i){
        cout << i % (n < (m + 1) * k ? k : n / (m + 1)) << " \n"[i == n - 1];
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