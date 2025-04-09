#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll k;
    cin >> k;
    if(k & 1){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
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