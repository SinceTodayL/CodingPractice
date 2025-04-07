#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n;++i){
        cin >> a[i];
    }
    if(k == n){
        for(int i = 1; i < n; i += 2){
            if(a[i] != (i + 1) / 2){
                cout << (i + 1) / 2 << endl;
                return;
            }
        }
        cout << k / 2 + 1 << endl;
    }
    else{
        for(int i = 1; i <= n - k + 1; ++i){
            if(a[i] != 1){
                cout << 1 << endl;
                return;
            }
        }
        cout << 2 << endl;
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