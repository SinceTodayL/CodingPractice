#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = '0' + s;
    int ans = 0;
    for(int i = 0; i < n; ++i){
        if(s[i] != s[i + 1]){
            ans++;
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