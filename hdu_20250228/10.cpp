#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
ll ans;
ll input;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> input;
        ans += ((n - i + 1) * abs(input)); 
    }
    cout << ans << endl;

    return 0;
}