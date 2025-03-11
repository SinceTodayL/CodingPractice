#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll a, b;
    cin >> a >> b;
    if(a == 1 && b == 1){
        cout << 1 << endl;
    }
    else{
        cout << max(a, b) - min(a, b) << endl;
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