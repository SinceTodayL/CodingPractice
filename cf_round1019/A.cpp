#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n, input;
    set<int> s;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> input;
        s.insert(input);
    }
    cout << s.size() << endl;
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