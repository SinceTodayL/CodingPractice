#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int num;
    cin >> num;
    int last, cur;
    cin >> last;
    int cnt = 0;
    for(int i = 1; i < num; ++i){
        cin >> cur;
        if(last != cur){
            cnt++;
        }
        last = cur;
    }
    cout << cnt + 1 << endl;
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