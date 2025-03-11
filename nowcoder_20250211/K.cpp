#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll x, y;
    cin >> x >> y;
    ll temp = 2 * x + 1;
    if(temp % 4 == y % 4){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
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