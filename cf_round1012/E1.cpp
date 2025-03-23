#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long



void solve() {
    int n, k;
    cin >> n >> k;
    ll sum_a = 0;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum_a += a[i];
    }
    for (int i = 0; i < n; ++i) 
        cin >> b[i];

    int rounds = 0;
    ll minus = 0;
    while (1) {
        sum_a -= minus;
        minus = 0;
        if (sum_a == 0) break;

        for (int i = 0; i < n; ++i) {
            int t = min(a[i], b[i]);
            a[i] -= t;
            b[i] -= t;
            minus += t;
        }

        ll temp = a[n - 1];
        for (int i = n - 1; i >= 1; --i) {
            a[i] = a[i - 1];
        }
        a[0] = temp;
        rounds++;
    }

    cout << rounds << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}