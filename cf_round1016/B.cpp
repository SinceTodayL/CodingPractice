#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    string s;
    cin >> s;
    int len = s.size();
    int ans = 0, temp;
    for(int i = len - 1; i >= 0; --i){
        if(s[i] != '0'){
            ans += (len - 1 - i);
            temp = i;
            break;
        }
    }
    for(int i = 0; i < temp; ++i){
        if(s[i] != '0'){
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