#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<bool> bflag(n, false);
    set<int> c;
    for(int i = 0; i <= n - 1; ++i){
        cin >> a[i];
    }
    for(int i = 0; i <= n - 1; ++i){
        cin >> b[i];
    }   
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(bflag[j]){
                continue;
            }
            if(c.find(a[i] + b[j]) == c.end()){
                c.insert(a[i] + b[j]);
                bflag[j] = true;
                break;
            }
            else{
                continue;
            }
        }
    }
    if(c.size() >= 3){
        cout << "yes" << endl;
    }
    else{
        cout << "no" << endl;
    }

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}