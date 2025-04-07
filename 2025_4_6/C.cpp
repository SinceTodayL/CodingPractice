#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll all = 0;

void change(vector<int>& ans, int l, int r, int st){
    cout << l << " " << r << " " << st << endl;
    int num = ans[st];
    int len = (r - l + 2) / 2;
    vector<int> temp;
    for(int i = l; i < st; ++i){
        temp.push_back(ans[i]);
    }
    for(int i = st + len; i <= r; ++i){
        temp.push_back(ans[i]);
    }
    for(int i = l; i <= r; ++i){
        if((i - l) & 1){
            ans[i] = temp[(i - l) / 2];
        }
        else{
            ans[i] = num;
        }
    }
}

void solve(){
    vector<int> cnt(10);
    for(int i = 0; i < 10; ++i){
        cin >> cnt[i];
        all += cnt[i];
    }
    if(cnt[0] == 1 && all == 0){
        cout << -1 << endl;
        return;
    }
    if(all & 1){
        if(cnt[0] >= (all + 1) / 2){
            cout << -1 << endl;
            return;
        }
        else{
            for(int i = 1; i < 10; ++i){
                if(cnt[i] > (all + 1) / 2){
                    cout << -1 << endl;
                    return;
                }
            }
        }
    }
    else{
        for(int i = 0; i < 10; ++i){
            if(cnt[i] > (all) / 2){
                cout << -1 << endl;
                return;
            }
        }
    }

    vector<int> ans(all + 1);
    int now = 1;
    for(int i = 0; i < 10; ++i){
        for(int j = now; j < now + cnt[i]; ++j){
            ans[j] = i;
        }
        now += cnt[i];
    }

    for(ll i = 1; i < all; ++i){
        if(ans[i] == ans[i + 1]){
            int len = 0;
            for(int k = i; k <= all; ++k){
                if(ans[k] == ans[i]){
                    len++;
                }
                else{
                    break;
                }
            }
            ll l, r;
            r = min(all, i + 2*len - 2);
            int right = r - i + 1 - len, left = len - 1 - right;
            l = i - left;
            change(ans, l, r, i);
        }
        if(ans[i] == 0 && i == 1){
            for(int j = 1; j < all; ++j){
                if(ans[j] == 0){
                    swap(ans[j], ans[j + 1]);
                    ++j;
                }
            }
        }
    }

    for(ll i = all - 1; i >= 1; --i){
        if(ans[i] == ans[i + 1]){
            int len = 0;
            for(int k = i; k >= 1; --k){
                if(ans[k] == ans[i]){
                    len++;
                }
                else{
                    break;
                    
                }
            }
            ll l, r;
            l = max(1ll, i - len + 1);
            int left = len - 1 - (i - l + 1), right = len - 1 - left;
            r = i + len - 1 + right - 1;
            change(ans, l, r, i - len + 1);
        }
        if(ans[i] == 0 && i == 1){
            for(int j = 1; j < all; ++j){
                if(ans[j] == 0){
                    swap(ans[j], ans[j + 1]);
                    ++j;
                }
            }
        }
    }


    for(int i = 1; i <= all; ++i){
        cout << ans[i];
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}