#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> SolveEuler(int n) {
    vector<int> spf(n + 1, 0);  
    vector<int> Euler(n + 1, 0); 

    for (int i = 2; i <= n; i++) {
        if (spf[i] == 0) { 
            spf[i] = i;
            Euler[i] = 1; 
        }
        for (int j = 2; j * i <= n; j++) {
            if (spf[i * j] == 0) {
                spf[i * j] = i;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        int x = i;
        int unique_prime_count = 0;
        while (x > 1) {
            int p = spf[x];  
            unique_prime_count++;
            while (x % p == 0) x /= p; 
        }
        Euler[i] = unique_prime_count;
    }
    
    return Euler;
}

void solve(){
    int n;
    cin >> n;
    ll ans = 0;
    vector<int> Euler = SolveEuler(n);
    for(int i = 1; i <= n; ++i){
        ans += Euler[i];
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