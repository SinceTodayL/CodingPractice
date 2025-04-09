#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll x, y;
    cin >> x >> y;
    if((x + 1 - y) % 9 == 0 && (x + 1 - y) >= 0){
        cout << "yes" << endl;
    }
    else{
        cout << "no" << endl;
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