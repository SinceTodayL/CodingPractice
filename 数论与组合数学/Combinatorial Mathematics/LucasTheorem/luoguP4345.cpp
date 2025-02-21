#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2350;
const ll mod = 2333;
ll c[N + 2][N + 2];
ll f[N + 2][N + 2];

inline ll lucas(ll n, ll k){
    if(k == 0 || k == n){
        return 1;
    }
    if(n < k){
        return 0;
    }
    return c[n % mod][k % mod] * lucas(n / mod, k / mod) % mod;
}

ll F(ll n, ll k){
    if(k < 0){
        return 0;
    }
    else if(k == 0 || n == 0){
        return 1;
    }
    if(n < mod && k < mod){
        return f[n][k] % mod;
    }
    return (F(n / mod, (k / mod) - 1) * (f[n % mod][mod - 1] % mod)) % mod + lucas(n / mod, k / mod) * (f[n % mod][k % mod] % mod) % mod;

}

void init(){
    c[0][0] = 1;
    for(int i = 0; i < N; ++i){
        c[i][0] = 1;
        c[i][i] = 1;
    }
    for(int i = 1; i < N; ++i){
        for(int j = 1; j < i; ++j){
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
        }
    }
    f[0][0] = 1;
    for(int i = 0; i < N; ++i){
        f[i][0] = 1;
    }
    for(int i = 0; i < N; ++i){
        for(int j = 1; j < N; ++j){
            f[i][j] = (c[i][j] + f[i][j - 1]) % mod;
        }
    }
}

void solve(){
    ll n, k;
    cin >> n >> k;
    cout << F(n, k) % mod << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();
    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}