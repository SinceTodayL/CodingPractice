#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isPrime(int x) {
    if(x < 2) return false;
    for (int i = 2; i*i <= x; i++) {
        if(x % i == 0) return false;
    }
    return true;
}

void solve(){
    ll n;
    cin >> n;
    if(n == 2){
        cout << "1 2" << endl;
        return;
    }
    int half = n / 2;
    int k = -1;
    for (int x = half; x >= 2; x--){
        if(isPrime(x)){
            k = x;
            break;
        }
    }
    if(k == -1) k = 2;

    vector<int> S;
    int L = 1, R = 2*k - 1;
    while(L <= R) {
        S.push_back(L);
        if(L != R)
            S.push_back(R);
        L++; R--;
    }

    vector<int> perm;
    for (int x : S)
        perm.push_back(x);
    for (int i = 2*k; i <= n; i++){
        perm.push_back(i);
    }
    
    for (size_t i = 0; i < perm.size(); i++){
        cout << perm[i] << " ";
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
