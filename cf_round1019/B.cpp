#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    string s;
    cin >> n >> s;
    s = "0" + s;
    int cnt = 0;
    for(int i = 0; i < n; ++i){
        if(s[i] != s[i + 1]){
            cnt++;
        }
    }
    if(cnt <= 1){
        cout << cnt + n << '\n';
    }
    else if(cnt == 2){
        cout << n + cnt - 1 << '\n';
    }
    else{
        cout << n + cnt - 2 << '\n';
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