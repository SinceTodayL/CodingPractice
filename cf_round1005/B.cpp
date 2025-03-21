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
    unordered_map<int, int> cnt;
    for(int i = 0; i < n; ++i){
        cnt[nums[i]]++;
    }
    int ans = 0, Cnt = 0, left = 0, right = 0, l = 0;
    bool flag = false;
    for(int i = 0; i < n; ++i){
        if(!flag){
            if(cnt[nums[i]] == 1){
                flag = true;
                Cnt++;
                l = i + 1;
            }
        }
        else{
            if(cnt[nums[i]] == 1){
                Cnt++;
            }
            else{
                flag = false;
                if(ans < Cnt){
                    left = l;
                    right = i;
                }
                ans = max(ans, Cnt);
                Cnt = 0;
            }
        }
    }
    if(flag){
        if(ans < Cnt){
            left = l;
            right = n;
        }
    }
    ans = max(ans, Cnt);
    if(ans > 0){
        cout << left << " " << right << endl;
    }
    else{
        cout << 0 << endl;
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