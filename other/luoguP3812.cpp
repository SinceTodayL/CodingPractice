#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 63;
ll p[N];

void insert(ll x){
    for(int i = N; i >= 0; --i){
        if(x >> i == 1){
            if(p[i] == 0){
                p[i] = x;
                return;
            }
            else{
                x ^= p[i];
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll x, n;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> x;
        insert(x);
    }
    ll ans = 0;
    for(int i = N; i >= 0; --i){
        ans = max(ans, ans ^ p[i]);
    }

    cout << ans << endl;

    return 0;
}