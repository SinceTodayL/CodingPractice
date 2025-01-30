#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<ll> nums(n + 1);
    bool flag = true;
    for(int i = 1; i <= n; ++i){
        cin >> nums[i];
        if(nums[i] == 1){
            flag = false;
        }
    }
    if(flag){
        cout << 1000000007 << endl;
    }
    else{
        cout << -1 << endl;
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