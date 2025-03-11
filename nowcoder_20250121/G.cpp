#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    ll ans = 0;
    cin >> n;
    vector<ll> nums(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> nums[i];
        ans += nums[i];
    }
    if(ans != (n * (n + 1)) / 2){
        cout << -1 << endl;
        return 0;
    }
    sort(nums.begin() + 1, nums.end());
    int cnt = 0;
    for(int i = 1; i <= n; ++i){
        if(nums[i] > i){
            cnt += (nums[i] - i);
        }
    }
    cout << cnt << endl;

    return 0;
}