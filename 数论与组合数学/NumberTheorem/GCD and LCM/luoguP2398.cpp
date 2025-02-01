#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 1;
int n;
ll Euler[N];
void solve(){
    for(int i = 1; i <= n; ++i){
        Euler[i] = i;
    }
    for(int i = 2; i <= n; ++i){
        if(Euler[i] == i){
            for(int j = i; j <= n; j += i){
                Euler[j] = (Euler[j] / i) * (i - 1);
            }
        }
    }
    for(int i = 2; i <= n; ++i){
        Euler[i] += Euler[i - 1];
    }
    ll ans = 0;
    for(ll i = 1; i <= n; ++i){
        ans += i * (2 * Euler[n / i] - 1);
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    solve();

    return 0;
}