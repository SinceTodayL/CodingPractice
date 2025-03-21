#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);

    for(int i = 0; i < n; ++i){
        cin >> nums[i];
    }
    if(k != 1){
        sort(nums.begin(), nums.end());
        ll ans = 0;
        for(int i = n - 1; i >= n - k - 1; --i){
            ans += nums[i];
        }
        cout << ans << endl;
    }
    else{
        int index = -1;
        int max_ele = INT_MIN;
        for(int i = 0; i < n; ++i){
            if(nums[i] > max_ele){
                index = i;
                max_ele = nums[i];
            }
        }
        if(index != 0 && index != n - 1){
            cout << max_ele + max(nums[0], nums[n - 1]) << endl;
        }
        else{
            sort(nums.begin(), nums.end());
            cout << nums[n - 1] + nums[n - 2] << endl;
        }
    }
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