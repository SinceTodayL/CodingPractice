#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n;
    cin >> n;
    ll odd = 0, even = 0;
    int input;
    for(int i = 1; i <= n; ++i){
        cin >> input;
        if(input & 1){
            odd++;
        }
        else{
            even++;
        }
    }
    ll ans = 0;
    if(even){
        ans = 1 + odd;
    }
    else{
        ans = odd - 1;
    }
    cout << ans << endl;
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