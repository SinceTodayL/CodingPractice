#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> nums(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> nums[i];
    }
    for(int i = 1; i <= n; ++i){
        bool flag = true;
        for(int j = 1; j <= n; ++j){
            if(i == j)
                continue;
            if(abs(nums[i] - nums[j]) % k == 0){
                flag = false;
                break;
            }
        }
        if(flag){
            cout << "YES\n" << i << '\n';
            return;
        }
    }
    cout << "NO" << endl;
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