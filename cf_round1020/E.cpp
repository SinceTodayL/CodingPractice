#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n, q, l, r, k, p;
    cin >> n >> q;
    vector<int> nums(n + 1, 0), pos(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> nums[i];
    }
    for(int i = 1; i <= n; ++i){
        pos[nums[i]] = i;
    }
    while(q--){
        int ans = 0;
        cin >> l >> r >> k;
        p = pos[k];
        if(p < l || p > r){
            cout << -1 << " \n"[q == 0];
            continue;
        }
        while(l < r){
            int mid = (l + r) >> 1;
            if(nums[mid] == k){
                break;
            }
            if(mid < p){
                if(nums[mid] > p){
                    ans++;
                }
                l = mid + 1;
            }
            else if(mid > p){
                if(nums[mid] < p){
                    ans++;
                }
                r = mid - 1;
            }
            else{
                break;
            }
        }
        cout << (ans == 0 ? 0 : ans + 1) << " \n"[q == 0];
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