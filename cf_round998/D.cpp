#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
int nums[N];

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> nums[i];
    }
    if(nums[1] > nums[2]){
        cout << "NO" << endl;
        return;
    }
    ll temp = nums[1];
    for(int i = 2; i < n; ++i){
        if(nums[i] > nums[i + 1]){
            if(nums[i] - nums[i + 1] > temp){
                cout << "NO" << endl;
                return;
            }
            
        }
        temp = nums[i] - temp;
    }
    cout << "YES" << endl;
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