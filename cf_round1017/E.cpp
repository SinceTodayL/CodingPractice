#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

ll pow2[32];
void init(){
    ll a = 1;
    for(int i = 0; i < 32; ++i){
        pow2[i] = a;
        a *= 2;
    }
}

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n);
    ll ans = 0;
    for(int i = 0; i < n; ++i){
        cin >> nums[i];
        ans += nums[i];
    }
    vector<int> fac(31, 0);
    for(int i = 0; i < n; ++i){
        for(int j = 30; j >= 0; --j){
            if((nums[i] >> j) & 1){
                fac[j]++;
            }
        }
    }
    vector<ll> score(n, 0);
    ll max_value = -99999999999999999;
    for(int i = 0; i < n; ++i){
        for(int j = 30; j >= 0; --j){
            if((nums[i] >> j) & 1){
                score[i] += (-fac[j] * pow2[j] + (n - fac[j]) * pow2[j]);
            }
        }
        max_value = max(max_value, score[i]);
        //cout << "    " << max_value << endl;
    }
    cout << ans + max_value << endl;
}

signed main(){
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