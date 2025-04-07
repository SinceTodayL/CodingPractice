#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 5000000;
vector<ll> nums(N + 2);
vector<ll> prefix(N + 2);
vector<ll> pow2(40);
void init(){
    ll temp = 1;
    for(ll i = 0; i <= 39; ++i){
        pow2[i] = temp;
        temp *= 2;
    }
    nums[0] = 1;
    for(ll i = 1; i <= N; ++i){
        ll index = upper_bound(pow2.begin(), pow2.end(), i) - pow2.begin();
        nums[i] = index;
    }
    prefix[0] = nums[0];
    for(ll i = 1; i <= N; ++i){
        prefix[i] = prefix[i - 1] + nums[i];
    }
    cout << prefix[N] << endl;
}

void solve(){
    ll k;
    cin >> k;
    ll index = lower_bound(prefix.begin(), prefix.end(), k) - prefix.begin();
    cout << index << endl;
    if(k == 1){
        cout << 0 << '\n';
    }
    if(k == 2){
        cout << 1 << '\n';
    }
    else if(find(pow2.begin(), pow2.end(), index) == pow2.end()){
        cout << nums[index] << '\n';
    }
    else{
        cout << nums[index + 1] << '\n';
    }

}

int main(){
    int t;
    cin >> t;
    init();
    while(t--){
        solve();
    }
    return 0;
}