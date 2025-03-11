#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n, m;
    cin >> n >> m;
    int a = m, b = m;
    int input1, input2;
    for(int i = 0; i < n; ++i){
        cin >> input1 >> input2;
        if(i){
            a += input1;
            b += input2;
        }
    }
    cout << 2 * (a + b) << endl;
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