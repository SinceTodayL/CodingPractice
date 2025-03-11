/*
GCD and LCM 模板
已知n个数的gcd,lcm，求有多少种不同的组合
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const ll N = 1e9 + 7;

int prime[100010];
bool isprime[100010];
int cnt = 0;
// 埃氏筛
void get_prime(){
    ll limit = sqrt(N);
    for(int i = 0; i <= limit; ++i){
        isprime[i] = true;
    }
    for(int i = 2; i * i <= limit; ++i){
        if(isprime[i]){
            for(int j = i * i; j <= limit; j += i){
                isprime[j] = false;
            }
        }
    }
    for(int i = 2; i <= limit; ++i){
        if(isprime[i]){
            prime[cnt++] = i;
        }
    }
}

vector<int> factor;
void get_factor(ll num){
    factor.resize(cnt + 1);
    fill(factor.begin(), factor.end(), 0);
    for(int i = 0; i < cnt; ++i){
        factor[i] = 0;
        while(num % prime[i] == 0){
            factor[i]++;
            num /= prime[i];
        }
    }
    if(num != 1){
        factor[cnt] = 1;
    }
}

ll fastpower(ll a, ll n){
    ll ans = 1;
    while(n){
        if(n & 1){
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        n >>= 1;
    }
    return ans % mod;
}

void solve(){
    ll x, y, n;
    cin >> x >> y >> n;
    if(y % x != 0){
        cout << 0 << endl;
        return;
    }
    ll t = y / x;
    get_factor(t);
/*
    cout << "factor: "<< endl;
    for(int i = 0; i < cnt; ++i){
        cout << factor[i] << " ";
    }
    cout << endl;
*/
    ll ans = 1;
    ll temp = 0;
    for(int i = 0; i <= cnt; ++i){
        temp = 0;
        if(factor[i] != 0){
            temp = (temp + fastpower(factor[i] + 1, n)) % mod;
            temp = ((temp - fastpower(factor[i], n)) + mod) % mod;
            temp = ((temp - fastpower(factor[i], n)) + mod) % mod;
            temp = (temp + fastpower(factor[i] - 1, n )) % mod;
            ans = (ans * temp) % mod;
        }
    }
    cout << (ans + mod) % mod << endl;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    get_prime();
    while(t--){
        solve();
    }
    return 0;
}