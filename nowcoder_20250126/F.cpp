#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int temp = a + b + c;
    if(temp >= n && temp <= 2 * n){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
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