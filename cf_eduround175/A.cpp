#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n;
    cin >> n;
    ll cnt = n % 15;
    cout << (n / 15) * 3 + min(3ll, cnt + 1) << endl;
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