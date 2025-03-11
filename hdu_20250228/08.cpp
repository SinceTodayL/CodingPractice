#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    unordered_map<string, int> mp;
    string input;
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> input;
        mp[input]++;
    }
    cout << min(mp["Cu"], mp["Ag"]) + mp["Au"] << endl;
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