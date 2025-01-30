#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10;
int a[N];

int gcd(int x, int y){
    return y == 0 ? x : gcd(y, x % y);
}

int cal(int x, int y){
    y += x;
    int ans = 0;
    if(gcd(x, y) == (x ^ y)){
        ans += (a[x]*a[y]);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, input;
    cin >> n;
    ll ans = 0;
    for(int i = 1; i <= n; ++i){
        cin >> input;
        a[input]++;
    }
    for(int i = 1; i <= N; ++i){
        if(a[i]){
            for(int j = 1; j * j <= i; ++j){
                if(i % j == 0){
                    ans += cal(i, j);
                    if(j * j < i){
                        ans += cal(i, i / j);
                    }
                } 
            }
        }
    }
    cout << ans << endl;
    return 0;
}