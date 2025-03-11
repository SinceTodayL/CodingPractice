#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
int n, m, a, b, k;
const int mod = 10007;

int fastpower(int a, int n){
    int ans = 1;
    a %= mod;
    while(n){
        if(n & 1){
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        n >>= 1;
    }
    return ans % mod;
}
const int N = 10001;
int fac[N];
int inverse[N];

int C(int n, int m){
    return (fac[n] * (inverse[m] % mod) * (inverse[n - m] % mod)) % mod;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> k >> n >> m;
    fac[0] = 1;
    for(int i = 1; i <= n + m; ++i){
        fac[i] = (fac[i - 1] * i) % mod;
        inverse[i] = fastpower(fac[i], mod - 2);
    }
    int ans = (((fastpower(a, n) % mod) * fastpower(b, m) % mod) * C(k, n) % mod) % mod;
    cout << ans << endl;

    return 0;
}