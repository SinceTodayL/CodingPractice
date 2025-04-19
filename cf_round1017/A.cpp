#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    vector<string> s(3);
    for(int i = 0; i < 3; ++i){
        cin >> s[i];
        cout << s[i][0];
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