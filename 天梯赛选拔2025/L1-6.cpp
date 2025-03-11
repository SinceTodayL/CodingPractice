#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
const int N = 2e5 + 10;
int a[N];
ll sum[50];
ll fp(ll a, ll p){
    ll ans = 1;
    while(p){
        if(p & 1){
            ans *= a;
        }
        p >>= 1;
        a = a * a;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    int max_depth = 0;
    for(int i = 0; i <= 50; ++i){
        if(fp(2, i) > n){
            max_depth = i;
            break;
        }
        for(int j = fp(2, i); j <= min(int(fp(2, i + 1)) - 1, n); ++j){
            sum[i] += a[j];
        }
    }
    int depth = 0;
    int max_value = INT_MIN;
    for(int i = 0; i < max_depth; ++i){
        if(max_value < sum[i]){
            max_value = sum[i];
            depth = i + 1;
        }
    }
    cout << depth << endl;


    return 0;
}