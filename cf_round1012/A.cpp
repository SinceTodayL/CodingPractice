#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int x, y, a;
    cin >> x >> y >> a;
    int all = x + y;
    a %= all;
    if(a >= 0 && a < x){
        cout << "No" << endl;
    }
    else{
        cout << "Yes" << endl;
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