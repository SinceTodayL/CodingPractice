#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    
    if(k == 0){
        string rev = s;
        reverse(rev.begin(), rev.end());
        if(s < rev)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
    else {
        bool allSame = true;
        for(int i = 1; i < n; ++i){
            if(s[i] != s[0]){
                allSame = false;
                break;
            }
        }
        cout << (allSame ? "NO" : "YES") << "\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}
