#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e10;

ll fastpower(ll a, ll n){
    ll ans = 1;
    while(n){
        if(n & 1) 
            ans *= a;
        a *= a;
        n >>= 1;
    }
    return ans;
}

ll fastpower_withmod(ll a, ll n){
     ll ans = 1;
     while(n){
        if(n & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        n >>= 1;
     }
     return ans % mod;
}


int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    
    cout << fastpower(2, 40) << endl;
    cout << fastpower_withmod(2, 40) << endl;

    return 0;
}