#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> ans(n);
    int mid = (n + 1) / 2 - 1;
    if(n % 2 == 0){
        cout << -1 << endl;
        return;
    }
    for(int i = 0; i < n; ++i){
        ans[(mid + i) % n] = ((mid + i) % n + i) % n;
    }
    for(int i = 0; i < n; ++i){
        cout << ans[i] + 1 << " ";
    }
    cout << endl;
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