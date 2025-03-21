#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n, k, ans;
    cin >> n >> k;
    if(n & 1){
        ans = 1;
        n -= k;
        if(n <= 0){
            cout << 1 << endl;
            return;
        }
        k--;
        ans += (n / k) + (n % k != 0);
        cout << ans << endl;
    }
    else{
        k--;
        ans = (n / k) + (n % k != 0);
        cout << ans << endl;
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