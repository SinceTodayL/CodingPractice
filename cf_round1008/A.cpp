#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll x, input;
    double n;
    double all = 0;
    cin >> n >> x;
    for(int i = 1; i <= n; ++i){
        cin >> input;
        all += input;
    }
    if(fabs(all / n - x) < 1e-6){
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