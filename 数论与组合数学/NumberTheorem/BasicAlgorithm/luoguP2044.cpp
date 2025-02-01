#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

ll m, a, c, x0, n, g;

ll multi(ll x, ll y){

    ll ans = 0;
    while(y){
        if(y & 1) 
            ans = (ans + x) % m;
        x = (x + x) % m;
        y >>= 1;
    }
    return ans;
}

vector<vector<ll>> cal_mat(vector<vector<ll>> a, vector<vector<ll>> b){
    vector<vector<ll>> result(a.size(), vector<ll>(b[0].size(), 0));
    for(int i = 0; i < a.size(); ++i)
        for(int j = 0; j < b[0].size(); ++j){
            for(int k = 0; k < a[0].size(); ++k){
                result[i][j] += multi(a[i][k], b[k][j]);
                result[i][j] %= m;
            }
        }
    return result;
}


ll cal_ans(){
    vector<vector<ll>> aa(2, vector<ll>(2, 0));
    vector<vector<ll>> result(2, vector<ll>(2, 0));
    for(int i = 0; i < 2; ++i){
        result[i][i] = 1;
    }
    aa[0][0] = a;
    aa[1][0] = c;
    aa[1][1] = 1;
    while(n){
        if(n & 1){
             result = cal_mat(result, aa);
        }
        aa = cal_mat(aa, aa);
        n >>= 1;
    }
    ll ans = ((multi(result[0][0],x0)%m + result[1][0]) % m) % g;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> a >> c >> x0 >> n >> g;
    a %= m;
    c %= m;
    cout << cal_ans();

    return 0;
}