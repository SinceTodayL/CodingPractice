#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll inv = 5e8 + 4;
const ll mod = 1e9 + 7;
 


void solve(){
    int n;
    string s;
    cin >> n >> s;
    s = " " + s;
    ll ans = 0;
    for(int i = n; i > 1; --i){
        if(s[i] == '0'){
            ans = (ans * inv) % mod;
        }
        else{
            ans = (1 + ans) * inv % mod;
        }
    }
    cout << (n - 1 + ans) % mod << endl;
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