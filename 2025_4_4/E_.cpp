#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll x, ll y){
    return y == 0 ? x : gcd(y, x % y);
}

void solve(){
    ll n, k;
    cin >> n >> k;
    vector<ll> nums(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> nums[i];
    }
    vector<ll> posfix(n + 1, 0);
    posfix[n] = nums[n];
    for(int i = n - 1; i >= 1; --i){
        posfix[i] = gcd(posfix[i + 1], nums[i]);
    }
    vector<ll> prefix(n + 1, 0);
    prefix[1] = nums[1];
    for(int i = 2; i <= n; ++i){
        prefix[i] = gcd(prefix[i - 1], nums[i]);
    }
    ll ans = 0;
    for(int i = 0; i <= n; ++i){
        if(i == n){
            ans = max(ans, prefix[n]);
        }
        else if(prefix[i] != prefix[i + 1]){
            ll cur = 0, mid = nums[i + 1] + k;
            for(int j = i + 1; j <= n; ++j){
                mid = gcd(nums[j] + k, mid);
                if(j < n)
                    cur = gcd(gcd(prefix[i], mid), posfix[j + 1]);
                else
                    cur = gcd(prefix[i], mid);
                ans = max(ans, cur);
            }
        }
    }
    cout << ans << endl;
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