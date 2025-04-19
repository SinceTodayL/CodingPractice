#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

/*

ll factor[200000];
ll euler[200000];
ll n;
int cnt = 1;

void fact(){
    factor[1] = 1;
    for(int i = 2; i * i <= n; ++i){
        if(n % i == 0){
            factor[++cnt] = i;
            factor[++cnt] = n / i;
        }
    }
    factor[++cnt] = n;
}

int Euler(ll x){
    int ans = x;
    for(int i = 2; i * i <= x; ++i){
        if(x % i == 0){
            ans = (ans / i) * (i - 1);
            while(x % i == 0){
                x /= i;
            }
        }
    }
    if(x != 1){
        ans = (ans / x) * (x - 1);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    fact();
    for(int i = 1; i <= cnt; ++i){
        euler[i] = Euler(n / factor[i]);
        //cout << euler[i] << " " ;
    }
    //cout << endl;
    ll ans = 0;
    for(int i = 1; i <= cnt; ++i){
        ans += factor[i] * euler[i];
        //cout << factor[i] << " ";
    }
    //cout << endl;
    cout << ans << endl;

    return 0;
}
    */



ll calc(ll n) {
    ll ans = n;
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            int b = 0;
            while (n % i == 0) {
                ++b;
                n /= i;
            }
            ans /= i;
            ans *= b * i - b + i;
        }
    }
    if (n > 1) {
        ans /= n;
        ans *= n + n - 1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    cout << calc(n) << '\n';

    return 0;
}
