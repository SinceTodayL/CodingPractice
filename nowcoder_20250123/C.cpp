#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n, m;
    cin >> n >> m;
    if(n == m || n - m > 26){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for(int i = 0; i < n - m; ++i){
        cout << (char)(i + 'a');
    }
    for(int i = 0; i < m; ++i){
        cout << (char)(i % 26 + 'a');
    }
    cout << endl;
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