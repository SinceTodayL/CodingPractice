#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int pipei(vector<string>& a, vector<string>& s){
    int cnt = 0;
    for(int i = 0; i < a.size(); ++i){
        if(a[i] == s[i]){
            cnt++;
        }
    }
    return cnt;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    vector<vector<string>> s(m, vector<string>(n));
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            cin >> s[i][j];
        }
    }
    vector<int> cnt(m);
    int max_ele = 0;
    for(int i = 0; i < m; ++i){
        cnt[i] = pipei(a, s[i]);
        max_ele = max(max_ele, cnt[i]);
    }
    int ans = n + (n - max_ele) * 2;
    vector<bool> flag(n, false);
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(a[j] == s[i][j]){
                flag[j] = true;
            }
        }
    }
    for(int i = 0; i < n; ++i){
        if(flag[i] == false){
            cout << -1 << endl;
            return;
        }
    }
    cout << max_ele << endl;
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