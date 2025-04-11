#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> nums(50);
void init(){
    nums[0] = 0;
    nums[1] = 1;
    nums[2] = 4;
    for(int i = 3; i <= 50 && nums[i - 1] <= 1e9; ++i){
        nums[i] = 2 * (nums[i - 1] + 1);
    }
}

void solve(){
    int n;
    cin >> n;
    cout << lower_bound(nums.begin(), nums.end(), n) - nums.begin() << '\n';
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