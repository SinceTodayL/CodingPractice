#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;

void solve(){
   bool isPrime = true;
   for(ll i = 2; i * i <= n; ++i){
        if(k / i == 0){
            isPrime = false;
            break;
        }
   }
   if(isPrime){
        if(k * 2 <= n){
            cout << 2 << endl;
        }
        else{
            cout << 1 << endl;
        }
   }
   else{
     cout << 2 << endl;
   }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    n++,k++;
    solve();

    return 0;
}