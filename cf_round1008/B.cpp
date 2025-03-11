#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n, k;
    cin >> n >> k;
    if(k % 2 == 0){
        for(int i = 1; i <= n - 2; ++i){
            cout << n - 1 << " ";
        }
        cout << n << " " << n - 1 << endl;
    }
    else{
        for(int i = 1; i <= n - 1; ++i){
            cout << n << " ";
        }
        cout << n - 1 << endl;
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