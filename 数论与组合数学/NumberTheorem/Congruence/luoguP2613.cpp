#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 19260817;  //这个N为质数

// 用扩展欧几里得算法求逆
ll extended_gcd(ll a, ll b, ll& x, ll& y){
    if(!b){
        x = 1;
        y = 0;
        return a;
    }
    ll gcd = extended_gcd(b, a % b, y, x);
    y -= (a / b) * x;
    return gcd;
}

// 快速读入一个很大的数，但是只要模m的结果（题中为10^100）
// 依位读入，依次取模即可
inline ll get_ll(){
    ll res = 0;
    char ch = getchar();
    while(!isdigit(ch) && ch != EOF){
        ch = getchar();
    }
    while(isdigit(ch)){
        res = (res << 3) + (res << 1) + (ch - '0');
        res %= mod;
        ch  = getchar();
    }
    return res;
}

// 求逆的mod为质数，因此可以用费马小定理求逆
ll fastpower(ll a, ll n){
    ll ans = 1;
    while(n){
        if(n & 1){
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        n >>= 1;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll a, b;
    a = get_ll();
    b = get_ll();
    if(b == 0){
        printf("Angry!\n");
    }

    ll inverse_b = fastpower(b, mod - 2) % mod;
    cout << (inverse_b * a) % mod << endl;

    /*
    ll x, y;
    extended_gcd(mod, b, x, y);
    y = ((y % mod) + mod) % mod;
    cout << (y * a) % mod << endl;
    */

    return 0;
}