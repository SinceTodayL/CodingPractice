#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
const int N = 1e7 + 3;
int cnt = 0;
bool isPrime[N];
vector<ll> phi;
vector<ll> prefix_phi;
#define int long long
void solve(){
    phi.resize(N + 1);
    for (int i = 0; i < N; ++i) {
        phi[i] = i;
    }
    for (int i = 2; i < N; ++i) {
        if (phi[i] == i) {
            for (int j = i; j < N; j += i) {
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
    for (int i = 1; i < N; ++i) {
        phi[i] = phi[i - 1] + phi[i];
    }
    for(int i = 1; i < N; ++i){
        isPrime[i] = true;
    }
    isPrime[1] = false;
    for(int i = 2; i <= n; ++i){
        if(isPrime[i]){
            for(ll j = 1ll * i *i; j <= n; j += i){
                isPrime[j] = false;
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n ; ++i) {
        if(isPrime[i])
            ans += (2 * phi[n / i] - 1);
    }
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    solve();

    return 0;
}