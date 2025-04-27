#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int n, q;
        cin >> n >> q;
        vector<int> nums(n+1), pos(n+1);
        for(int i = 1; i <= n; ++i){
            cin >> nums[i];
        }
        for(int i = 1; i <= n; ++i){
            pos[ nums[i] ] = i;
        }

        while(q--){
            int l, r, k;
            cin >> l >> r >> k;
            int pk = pos[k];
            if(pk < l || pk > r){
                cout << -1 << " \n"[q==0];
                continue;
            }

            int L = l, R = r;
            int mL = 0, mR = 0;               
            int B_left = 0, B_right = 0;   
            while(L <= R){
                int mid = (L + R) >> 1;
                if(mid == pk) break;
                if(mid < pk){
                    ++mL;
                    if(nums[mid] > k) ++B_left;
                    L = mid + 1;
                } else {
                    ++mR;
                    if(nums[mid] < k) ++B_right;
                    R = mid - 1;
                }
            }

            if(k - 1 < mL || (n - k) < mR){
                cout << -1 << " \n"[q==0];
            } else {
                int d = 2 * max(B_left, B_right);
                cout << d << " \n"[q==0];
            }
        }
    }
    return 0;
}