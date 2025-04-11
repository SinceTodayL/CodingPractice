#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll k;
    cin >> k;
    const int mod = 10;
    for(int i = 0; i <= 9; ++i){
        string s = to_string(k - i);
        s = '0' + s;
        int cnt = 10;
        for(char ch : s){
            cnt = min(cnt, ('7' - ch + mod) % mod);
        }
        if(cnt <= i){
            cout << i << '\n';
            return;
        }
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