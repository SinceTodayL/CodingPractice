#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    string name;
    cin >> n >> name;
    vector<string> s(n);
    for(int i = 0; i < n; ++i){
        cin >> s[i];
    }
    for(int i = 0; i < n; ++i){
        if(s[i] == name){
            cout << i + 1 << endl;
            return;
        }
    }
    cout << -1 << endl;
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