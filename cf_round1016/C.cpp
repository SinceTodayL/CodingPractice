#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isprime(ll x){
    for(int i = 2; i * i <= x; ++i){
        if(x % i == 0){
            return false;
        }
    }
    return true;
}

void solve(){
    ll x, k;
    cin >> x >> k;
    if(x == 1){
        if(k == 1){
            cout << "No" << endl;
        }
        else if(k == 2){
            cout << "yes" << endl;
        }
        else if(k >= 3){
            cout << "no" << endl;
        }
    }
    else if(k != 1){
        cout << "No" << endl;
    }
    else{
        if(isprime(x)){
            cout << "yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
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