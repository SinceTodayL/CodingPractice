#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;
ll m, n;

ll fp(ll a, ll n){
    ll ans = 1;
    a %= mod;
    while(n){
        if(n & 1){
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        n >>= 1;
    }
    return ans;
}


/*
    DFS 法求组合数，内核是动态规划
*/

const ll N1 = 1005; 
// 本题不适用于这种解法，本题的 N 上限达到 1e6, 不可能用DFS解决
ll c[N1][N1];
ll dfs(ll n, ll m){
    if(m == 0){
        c[n][m] = 1;
    }
    if(m == 1){
        c[n][m] = n;
    }
    if(c[n][m]){
        return c[n][m];
    }
    // 这个用了组合数的对称性
    if(n - m < m){
        m = n - m;
    }
    return c[n][m] = (dfs(n - 1, m) + dfs(n - 1, m - 1)) % mod;
}


/*
    用逆直接计算组合数，但是要预处理阶乘
*/

const ll N2 = 1e6 + 1;
ll fac[N2];
// 预处理逆, 这里的 mod 是一个素数，可以方便的用费马小定理写出
ll inverse[N2]; 

// 核心就在求逆
ll C(int n, int m){
    if(n == m || m == 0){
        return 1;
    }
    return ((fac[n] * inverse[m] % mod) * inverse[n - m] % mod) % mod;
}
void init(){
    fac[0] = 1;
    for(int i = 1; i < N2; ++i){
        fac[i] = (i * fac[i - 1]) % mod;
        inverse[i] = fp(fac[i], mod - 2);
    }
}
ll cal(ll n, ll m){
    init();
    return C(n, m);
}

/*
    本题正解：卢卡斯定理 lucas theroem
*/

// 首先本题要用到上面写过的求逆法解组合数的函数

ll lucas(ll n, ll m){
    if(m == 0){
        return 1;
    }
    return (C(n % mod, m % mod) * lucas(n / mod, m / mod)) % mod;
}




int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    ll sum = 0, input;
    for(int i = 0; i < m; ++i){
        cin >> input;
        sum += (input);
    }
    if(sum + m > n){
        cout << 0 << endl;
        return 0;
    }
    init();
    // cout << lucas(n - sum - 1, m - 1) % mod << endl;
    cout << C(n - sum - 1, m - 1) << endl;
    return 0;
}