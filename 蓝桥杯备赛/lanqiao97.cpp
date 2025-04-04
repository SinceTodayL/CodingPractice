#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    vector<int> nums(n + 1, 0);
    for(int i = 1; i <= n; ++i){
        cin >> nums[i];
    }

    vector<ll> prefix_num(n + 1, 0);
    for(int i = 1; i <= n; ++i){
        prefix_num[i] = (prefix_num[i - 1] + nums[i]) % k;
    }

    vector<int> cnt(k, 0);
    for(int i = 0; i <= n; ++i){
        cnt[prefix_num[i] % k]++;
    }

    ll ans = 0;
    for(int i = n; i > 0; --i){
        cnt[prefix_num[i] % k]--;
        ans += cnt[prefix_num[i] % k];
    }

    cout << ans << endl;
    return 0;
}