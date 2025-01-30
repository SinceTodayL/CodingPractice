#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){

    int n;
    cin >> n;
    vector<double> p(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> p[i];
    }
    double ans = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = i + 1; j <= n; ++j){
            ans += 2.0 * (p[i]*p[j])/(p[i] + p[j]);
        }
    }
    printf("%.6lf", ans);
    return 0;
}