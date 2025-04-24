#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


ll n;
ll cal(ll l, ll r){
    return ((r/2)-((l-1)/2)) + ((r/5)-((l-1)/5)) - ((r/10)-((l-1)/10));
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    ll l, r;
    ll ans = 0;
    for(l = 1; l <= n; l = r + 1){
        r = n / (n / l);
        ans += (r - l + 1 - (cal(l, r))) * (n / l);
        ans += (cal(l, r)) * n;
    }
    cout << ans << endl;


    return 0;
}