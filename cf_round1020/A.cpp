#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    string s;
    cin >> n >> s;
    int count1 = count(s.begin(), s.end(), '1');
    int count0 = n - count1;
    cout << n * count1 - count1 + count0 << '\n';
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