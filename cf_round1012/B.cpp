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
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            bool flag1 = true, flag2 = true;
            if(s[i][j] == '1'){
                for(int k = i; k >= 0; --k){
                    if(s[k][j] != '1'){
                        flag1 = false;
                        break;
                    }
                }
                for(int k = j; k >= 0; --k){
                    if(s[i][k] != '1'){
                        flag2 = false;
                        break;
                    }
                }
            }
            if(flag1 == false && flag2 == false){
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
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