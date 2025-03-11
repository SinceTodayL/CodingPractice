#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// 计算 ax + by = gcd(a, b) 的特解
ll extended_gcd(ll a, ll b, ll& x, ll& y){
    if(!b){
        x = 1;
        y = 0;
        return a;
    }
    ll gcd = extended_gcd(b, a % b, y, x);
    y = y - (a / b) * x;
    return gcd;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    

    return 0;
}