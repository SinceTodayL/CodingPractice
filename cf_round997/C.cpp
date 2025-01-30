#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    int temp = 2;
    cout << "1 1 2 3 1 ";
    for(int i = 6; i <= n; ++i){
       cout << temp << " ";
       i++;
       if(i <= n){
        cout << temp + 1 << " ";
        i++;
       }
       if(i <= n){
        cout << temp + 2 << " ";
       }
       temp++;
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