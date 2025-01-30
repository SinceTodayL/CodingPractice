#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int n, k;
const int N = 2e5 + 1;
int a[N];
bool flag[N];
 
void solve(){
    cin >> n >> k;
    for(int i = 1; i <= k; ++i){
        a[i] = 0;
    }
    for(int i = 1; i <= k; ++i){
        flag[i] = false;
    }
    int input;
    for(int i = 1; i <= n; ++i){
        cin >> input;
        a[input]++;
        flag[input] = true;
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        if(i > k){
            continue;
        }
        if(flag[i]){
            if(!(k & 1) && i == k / 2){
                ans += a[i] / 2;
                continue;
            }
            ans += min(a[i], a[k - i]);
            flag[k - i] = false;
        }
    }
    cout << ans << endl;
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