#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e6 + 1;
ll inverse[N];
void get_inverse(ll n, ll p){  // p 为 mod, 且 p 为质数
    inverse[1] = 1;
    for(int i = 2; i <= n; ++i){
        inverse[i] = (p - p/i) * inverse[p % i] % p;  // 神奇的逆元递推公式
    }
}

int main(){

    ll n, p;
    cin >> n >> p;
    get_inverse(n, p);
    for(int i = 1; i <= n; ++i){
        printf("%lld\n", inverse[i]);
    }

    return 0;
}