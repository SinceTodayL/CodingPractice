#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n + 1);
    ll sum = 0;
    for(int i = 1; i <= n; ++i){
        cin >> nums[i];
        sum += nums[i];
    }
    if(sum == 0){
        cout << 3 << endl;
        cout << 1 << " " << n - 2 << endl;
        cout << 2 << " " << 3 << endl;
        cout << 1 << " " << 2 << endl;
        return;
    }
    int length = 0, cnt = 0, l, r;
    bool flag = false;
    vector<pair<int, int>> ans; 
    for(int i = 1; i <= n; ++i){
        if(!flag){
            if(nums[i] == 0){
                l = i - length;
                flag = true;
                if(i == n){
                    ans.push_back(make_pair(n - 1 - length, n - length));
                    cnt++;
                    length += (1);
                }
            }
        }
        else{
            if(nums[i] == 0){
                if(i == n){
                    r = n - length;
                    ans.push_back(make_pair(l, r));
                    cnt++;
                    length += (r - l);
                }
            }
            else{
                flag = false;
                r = i - length;
                if(r - l == 1){
                    length += 1;
                    ans.push_back(make_pair(l, r));
                    cnt++;
                }
                else{
                    length += (r - l - 1);
                    ans.push_back(make_pair(l, r - 1));
                    cnt++;
                }
            }
        }
    }
    ans.push_back(make_pair(1, n - length));
    cnt++;
    cout << cnt << endl;
    for(int i = 0; i < cnt; ++i){
        cout << ans[i].first <<  " " << ans[i].second << endl;
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