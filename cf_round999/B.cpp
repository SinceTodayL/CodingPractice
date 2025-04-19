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
    sort(nums.begin(), nums.end());
    int ptr1 = 0, ptr2 = 0;
    vector<int> ans(4);
    bool flag = false;
    while(ptr1 < n - 1 && !flag){
        while(ptr1 < n - 1 && nums[ptr1] != nums[ptr1 + 1]){
            ptr1++;
        }
        if(ptr1 == n - 1){
            break;
        }
        int a = nums[ptr1];
        ans[0] = ans[1] = a;
        for(ptr2 = 0; ptr2 < n - 1; ++ptr2){
            if(ptr1 - ptr2 > 1){
                if(nums[ptr2 + 1] - nums[ptr2] < 2 * a){
                    flag = true;
                    ans[2] = nums[ptr2 + 1]; ans[3] = nums[ptr2];
                    //cout << 1 << endl;
                    break;
                }
            }
            else if(ptr1 - ptr2 == 1 && ptr1 < n - 2){
                if(nums[ptr2 + 3] - nums[ptr2] < 2 * a){
                    flag = true;
                    ans[2] = nums[ptr2 + 3]; ans[3] = nums[ptr2];
                    break;
                }
            }
            else if(ptr1 - ptr2 == 0 || ptr1 - ptr2 == -1){
                continue;
            }
            else if(ptr1 - ptr2 < -1 && ptr2 <= n - 1){
                if(nums[ptr2 + 1] - nums[ptr2] < 2 * a){
                    flag = true;
                    ans[2] = nums[ptr2 + 1]; ans[3] = nums[ptr2];
                    break;
                }
            }
        }
        ++ptr1;
    }
    if(flag){
        for(int i = 0; i < 4; ++i){
            cout << ans[i] << " ";
        }
        cout << endl;
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