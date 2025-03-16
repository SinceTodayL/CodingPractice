#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

int phi(int x){
    int ans = x;
    for(int i = 2; i * i <= x; ++i){
        if(!(x % i)){
            ans /= (i);
            ans *= (i - 1);
            while(x % i == 0){
                x /= i;
            }
        }
    }
    if(x != 1){
        ans /= x;
        ans *= (x - 1);
    }
    return ans;
}
int a, m, b;
int fp(int a, int x){
    int ans = 1;
    while(x){
        if(x & 1){
            ans = (ans * a) % m;
        }
        a = (a * a) % m;
        x >>= 1;
    }
    return ans % m;
}


inline int fread(int mod){
    int x = 0;
    bool g = false; 
    char c = getchar();
    while(c < '0' || c > '9'){
        c = getchar();
    }
    while(c >= '0' && c <= '9'){
        x = (x << 3) + (x << 1) + (c - '0');
        if(x >= mod){
            g = true;
            x %= mod;
        }
        c = getchar();
    }
    if(g){
        return (x + mod);
    }
    else{
        return x;
    }
}

signed main(){

    cin >> a >> m;
    int p = phi(m);
    b = fread(p);
    cout << fp(a, b);

    return 0;
}