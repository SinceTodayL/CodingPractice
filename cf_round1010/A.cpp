#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for(int i = 0; i < n; ++i){
        cin >> s[i];
    }
    int cnt = 0, cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; ++i){
        cnt = 0;
        for(int j = 0; j < m; ++j){
            if(s[i][j] == '1'){
                cnt++;
            }
        }
        if(cnt & 1){
            cnt1++;
        }
    }
    for(int i = 0; i < m; ++i){
        cnt = 0;
        for(int j = 0; j < n; ++j){
            if(s[j][i] == '1'){
                cnt++;
            }
        }
        if(cnt & 1){
            cnt2++;
        }
    }
    cout << max(cnt1, cnt2) << endl;
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