/*
    扩展中国剩余定理 模板
    如果同余方程中的 m 都是互素的，x 有解公式
    但是如果不满足这个条件，就要用扩展中国剩余定理
    其实就是以两个为一个方程组，然后合并为一个，直到只剩两个方程
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 1;
int n;
ll a[N];
ll m[N];

//龟速乘, 防止爆long long
ll multiply(ll a, ll b, ll m){
    ll ans = 0;
    while(b > 0){
        if(b & 1){
            ans = (ans + a) % m;
        }
        a = (a + a) % m;
        b >>= 1;
    }
    return ans;
}

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

ll excrt(){
    ll x, y;
    ll m1 = m[1], a1 = a[1];
    ll ans = 0;
    for(int i = 2; i <= n; ++i){
        ll a2 = a[i], m2 = m[i];
        ll a = m1, b = m2;
        ll c = (a2 - a1 % m2 + m2) % m2;
        ll d = extended_gcd(a, b, x, y);

        // 无解
        if(c % d != 0){
            return -1;
        }

        x = multiply(x, c / d, b / d);  // 之所以模为b/d，是因为要求在模b/d意义下最小的x
        ans = a1 + x * m1;
        m1 = m2 / d * m1;
        ans = (ans % m1 + m1) % m1;
        a1 = ans;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> m[i] >> a[i];
    }
    cout << excrt() << endl;

    return 0;
}