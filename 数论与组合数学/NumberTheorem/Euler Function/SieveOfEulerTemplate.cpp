#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e7;
int prime[N + 1];
bool isprime[N + 1];
void EulerSieve(){
    int cnt = 0;
    memset(prime, 0, sizeof(prime));
    memset(isprime, true, sizeof(isprime));
    for(int i = 2; i <= N; ++i){
        if(isprime[i]){
            prime[cnt++] = i;
        }
        for(int j = 0; j < cnt; ++j){
            if(i * prime[j] > N)
                break;
            isprime[i * prime[j]] = false;
            if(i % prime[j] == 0)
                break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    

    return 0;
}