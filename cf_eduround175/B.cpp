#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, x, k;
    cin >> n >> x >> k;
    string s;
    cin >> s;
    ll pos = x;
    int record = 0;
    int cnt = 0;
    bool flag = false;
    int loop = -1;
    ll ans = 0;
    ll t = 0;
    for(int i = 0; i < n; ++i){
        t++;
        if(s[i] == 'L'){
            pos--;
            record--;
            if(!flag){
                cnt++;
            }
        }
        else{
            pos++;
            record++;
            if(!flag){
                cnt++;
            }
        }
        if(record == 0){
            flag = true;
            loop = cnt;
        }
        if(pos == 0){
            if(flag){
                ans += (k - t) / loop + 1;
                break;
            }
            else{
                ans += 1;
                i = -1;
                cnt = 0;
                record = 0;
            }
        }
        if(t >= k){
            break;
        }
    }
    cout << ans << endl;
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