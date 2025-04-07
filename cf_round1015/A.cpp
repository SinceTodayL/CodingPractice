#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> ans(n + 1);
    if(n % 2 == 0){
        cout << -1 << endl;
    }
    else{
        ans[1] = n;
        ans[2] = 2;
        ans[3] = 1;
        for(int i = 4; i <= n; ++i){
            ans[i] = i - 1;
        }
        for(int i = 1; i <= n; ++i){
            cout << ans[i] << " ";
        }
        cout << endl;
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