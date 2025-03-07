#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

double f(int n, vector<double>& pa, vector<double>& pb, vector<double>& pc, double x){
    vector<double> res(n + 1);
    for(int i = 1; i <= n; ++i){
        res[i] = pa[i] * x * x + pb[i] * x + pc[i];
    }
    double max_res = INT_MIN;
    for(int i = 1; i <= n; ++i){
        max_res = max(max_res, res[i]);
    }
    return max_res;
}

void solve(){
    int n;
    cin >> n;
    vector<double> pa(n + 1);
    vector<double> pb(n + 1);
    vector<double> pc(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> pa[i] >> pb[i] >> pc[i];
    }
    double L = 0, R = 1000, l, r;
    while(fabs(L - R) > 1e-8){
        double k = (R - L) / 3;
        l = L + k;
        r = R - k;
        if(f(n, pa, pb, pc, l) > f(n, pa, pb, pc, r)){
            L = l;
        }
        else{
            R = r;
        }
    }
    cout << fixed << setprecision(4) << f(n, pa, pb, pc, L) << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}