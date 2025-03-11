#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    for(ll i = 2ll; i * i <= n; ++i){
        if(n % i == 0){
            cout << n / i << endl;
            break;
        }
    }

    return 0;
}