#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
    int n;
    cin >> n;
    n -= 2;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i){
        cin >> nums[i];
    }
    for(int i = 0; i <= n - 3; ++i){
        if(nums[i] == 1 && nums[i + 1] == 0 && nums[i + 2] == 1){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    return;
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