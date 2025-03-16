#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int x, n, m;
    cin >> x >> n >> m;
    n = min(100, n);
    m = min(m, 100);
    int n1 = n, m1 = m, x1 = x;
    int max_value, min_value;
    while(x1 != 0 && !(n1 == 0 && m1 == 0)){
        if(x1 & 1){
            if(m1 > 0){
                x1 = (x1 + 1) / 2;
                m1--;
            }
            else{
                x1 = x1 / 2;
                n1--;
            }
        }
        else{
            if(n1 > 0){
                x1 = x1 / 2;
                n1--;
            }
            else{
                x1 = (x1 + 1) / 2;
                m1--;
            }
        }
    }
    max_value = x1;
    n1 = n; m1 = m; x1 = x;
    while(x1 != 0 && !(n1 == 0 && m1 == 0)){
        if(x1 % 2 == 0){
            if(m1 > 0){
                x1 = (x1 + 1) / 2;
                m1--;
            }
            else{
                x1 = x1 / 2;
                n1--;
            }
        }
        else{
            if(n1 > 0){
                x1 = x1 / 2;
                n1--;
            }
            else{
                x1 = (x1 + 1) / 2;
                m1--;
            }
        }
    }
    min_value = x1;
    if(1){
        n1 = n; m1 = m; x1 = x;
        while(x1 != 0 && !(n1 == 0 && m1 == 0)){
            if(n1 > 0){
                x1 = x1 / 2;
                n1--;
            }
            else{
                x1 = (x1 + 1) / 2;
                m1--;
            }
        }
        max_value = max(max_value, x1);
        n1 = n; m1 = m; x1 = x;
        while(x1 != 0 && !(n1 == 0 && m1 == 0)){
            if(m1 > 0){
                x1 = (x1 + 1) / 2;
                m1--;
            }
            else{
                x1 = x1 / 2;
                n1--;
            }
        }
        min_value = min(min_value, x1);
    }
    cout << min_value << " " << max_value << endl;
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