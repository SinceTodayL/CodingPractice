#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
void solve(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    double m = b - a;
    double n = d - c;
    cout << a << " " << d << endl;
    if(b - a > d - c){
        cout << a + 1 <<  " " << d << endl;
        double ans = n - (sqrt((m - 0.5)*(m - 0.5) - 0.25));
        int temp = static_cast<int>(ans);
        if(temp < 0){
            cout << b << " " << c << endl;
        }
        else if(fabs((temp + 1) - ans) > fabs((temp - ans))){
            cout << b << " " << c + temp << endl;
        }
        else{
            cout << b << " " << c + temp + 1 << endl;
        }
    }
    else{
        cout << b << " " << c + 1 << endl;
        double ans = m - (sqrt((n - 0.5)*(n - 0.5) - 0.25));
        // cout << ans << endl;
        int temp = static_cast<int>(ans);
        if(temp < 0){
            cout << a << " " << d << endl;
        }
        else if(fabs((temp + 1) - ans) > fabs((temp - ans))){
            cout << a + temp << " " << d << endl;
        }
        else{
            cout << a + temp + 1 << " " << d << endl;
        }
    }
}
*/

void solve(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    double m = b - a;
    double n = d - c;
    if(m > n){
        cout << a << " " << d << endl;
        cout << a + 1 << " " << d << endl;
        cout << b << " " << d - 1 << endl;
    }
    else{
        cout << b << " " << c << endl;
        cout << b << " " << c + 1 << endl;
        cout << b - 1 << " " << d << endl;
    }
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