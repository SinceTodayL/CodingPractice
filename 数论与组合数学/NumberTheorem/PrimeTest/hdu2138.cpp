#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fastpower(ll a, ll n, ll mod){
    ll ans = 1;
    while(n){
        if(n & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        n >>= 1;
    }
    return ans % mod;
}

bool witness(ll a, ll n){ // 素性测试的核心函数，基于二次探测定理
    ll u = n - 1;
    int t = 0;
    while(u & 1 == 0){
        u >>= 1;
        t++;
    }
    ll x1, x2;
    x1 = fastpower(a, u, n);
    for(int i = 1; i <= t; ++i){
        x2 = fastpower(x1, 2, n);
        if(x2 == 1 && x1 != 1 && x1 != n - 1)
            return true;
        x1 = x2;
    }
    if(x1 != 1)
        return true;
    return false;
}

bool MillerRabin(ll n, ll s){
    if(n < 2)  //返回false，表示不是素数
        return false; 
    if(n == 2)
        return true;
    if(n % 2 == 0)
        return false;
    for(int i = 0; i < s && i < n; ++i){
        ll a = rand() % (n - 1) + 1;
        if(witness(a, n))
            return false;
    }
    return true;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll m, input, test_times = 30;
    while(cin >> m){
        ll cnt = 0;
        for(int i = 0; i < m; ++i){
            cin >> input;
            if(MillerRabin(input, test_times))
                cnt++;
        }
        cout << cnt << endl;
    }

    return 0;
}