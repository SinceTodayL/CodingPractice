#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int a1, a2, a4, a5;
    cin >> a1 >> a2 >> a4 >> a5;
    int a = a1 + a2;
    int b = a4 - a2;
    int c = a5 - a4;
    if(a == b || b == c || a == c){
        if(a == b && b == c){
            cout << 3 << endl;
            return;
        }
        cout << 2 << endl;
        return;
    }
    cout << 1 << endl;
    return;
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