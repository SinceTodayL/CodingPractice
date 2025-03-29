#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i){
        cin >> nums[i];
    }
    unordered_map<int, int> mp;
    auto check = [&](unordered_map<int, int> mp){
        return mp[0] >= 3 && mp[1] >= 1 && mp[2] >= 2 && mp[3] >= 1 && mp[5] >= 1;
    };
    for(int i = 0; i < n; ++i){
        mp[nums[i]]++;
        if(check(mp)){
            cout << i + 1 << endl;
            return;
        }
    }
    cout << 0 << endl;
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