#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fp(ll a, ll p){
    ll ans = 1;
    while(p){
        if(p & 1){
            ans *= a;
        }
        a *= a;
        p >>= 1;
    }
    return ans;
}
void solve(){
    ll n, m;
    cin >> m >> n;
    if(m == 1){
        cout << 2 << endl;
    }
    else
        cout << fp(2, m) - 1 << endl;
}

int main(){

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}