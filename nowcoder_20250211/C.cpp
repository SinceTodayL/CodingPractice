#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pow2[64];
ll record[64];

void solve(){
    ll k;
    cin >> k;
    ll index = upper_bound(record, record + 63, k) - record - 1;
    ll left = k - record[index];
    if(k == 1){
        cout << 2 << endl;
        return;
    }
    else if(k == 2){
        cout << 6 << endl;
        return;
    }
    ll ans = pow2[index] + (left + 1) * 2 ;
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    ll temp = 2;
    for(int i = 1; i <= 63; ++i){
        pow2[i] = temp;
        temp *= 2;
    }
    record[0] = 0;
    record[1] = 1;
    record[2] = 2;
    record[3] = 3;
    for(int i = 4; i <= 63; ++i){
        record[i] = record[i - 1] + pow2[i - 2] - 1;
    }
    while(t--){
        solve();
    }

    return 0;
}