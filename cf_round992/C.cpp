#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pow2[50];
void init(){
    ll a = 1;
    for(int i = 0; i < 49; ++i){
        pow2[i] = a;
        a *= 2;
    }
}
vector<int> to_bin(ll x, ll n){
    vector<int> bin;
    while(x){
        if(x & 1){
            bin.push_back(1);
        }
        else{
            bin.push_back(0);
        }
        x >>= 1;
    }
    while(bin.size() <= n - 1){
        bin.push_back(0);
    }
    reverse(bin.begin(), bin.end());
    return bin;
}

void solve(){
    ll n, k;
    cin >> n >> k;
    if(n < 50 && k > pow2[n - 1]){
        cout << -1 << endl;
        return;
    }
    k--;
    vector<int> ans(n + 1);
    vector<int> bin = to_bin(k, n);
    int len = n - 1;
    int l = 1, r = n;
    for(int i = 1; i <= len; ++i){
        if(bin[i] == 0){
            ans[l] = i;
            l++;
        }
        else{
            ans[r] = i;
            r--;
        }
    } 
    ans[l] = n;
    for(int i = 1; i <= len + 1; ++i){
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}