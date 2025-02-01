#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

struct Matrix{
    ll mat[3][3];
    Matrix(){
        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < 3; ++j){
                mat[i][j] = 0;
            }
        }
    }
    Matrix operator* (Matrix& other){
        Matrix result;
        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < 3; ++j){
                for(int k = 0; k < 3; ++k){
                     result.mat[i][j] += (this->mat[i][k]*other.mat[k][j])%mod;
                     result.mat[i][j] %= mod;
                }
            }
        }
        return result;
    }
};

Matrix aa;

ll cal_ans(ll n, Matrix a){
    Matrix res;
    for(int i = 0; i < 3; ++i){
        res.mat[i][i] = 1;
    }
    while(n){
        if(n & 1){
            res = res*a;
        }
        a = a*a;
        n >>= 1;
    }
    return (((res.mat[0][0] + res.mat[1][0]) % mod) + res.mat[2][0]) % mod;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    aa.mat[0][0] = 1;
    aa.mat[0][1] = 1;
    aa.mat[1][2] = 1;
    aa.mat[2][0] = 1;

    ll n; cin >> n;
    while(n--){
        ll k;
        cin >> k;
        if(k == 1 || k == 2 || k == 3)
            cout << 1 << endl;
        else
            cout << cal_ans(k - 3, aa) << endl;
    }

    return 0;
}