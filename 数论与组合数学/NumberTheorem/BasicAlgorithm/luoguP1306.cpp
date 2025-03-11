#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e8;

vector<vector<ll>> cal_mat(vector<vector<ll>> a, vector<vector<ll>> b){
    vector<vector<ll>> res(a.size(), vector<ll>(b[0].size(), 0));
    for(int i = 0; i < a.size(); ++i)
        for(int j = 0; j < b[0].size(); ++j){
            for(int k = 0; k < a[0].size(); ++k){
                res[i][j] += a[i][k]*b[k][j];
                res[i][j] %= mod;
            }
        }

    return res;
}

ll cal_fibo(ll k){
     vector<vector<ll>> a(2, vector<ll>(2, 0));
     a[0][0] = 1;
     a[0][1] = 1;
     a[1][0] = 1;
     a[1][1] = 0;
     vector<vector<ll>> res(2, vector<ll>(2, 1));
     res[0][1] = 0;
     res[1][0] = 0;
     while(k){
        if(k & 1){
             res = cal_mat(res, a);
        }
        a = cal_mat(a, a);
        k >>= 1;
     }
     return res[1][0];
}

ll gcd(ll m, ll n){
    if(m % n == 0 || n == 1){
        return n;
    }
    else
        return gcd(n, m%n);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;
    cout << cal_fibo(gcd(m, n)) % mod << endl;
    return 0;
}