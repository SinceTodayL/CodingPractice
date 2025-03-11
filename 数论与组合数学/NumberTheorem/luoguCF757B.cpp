#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
bool isprime[100010];
int s[100010];
int n;
const int N = 100010;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> s[i];
    }
    
    for(int i = 1; i <= N; ++i){
        isprime[i] = true;
    }
    for(int i = 2; i * i <= N; ++i){
        if(isprime[i]){
            for(int j = i * i; j <= N; j += i){
                isprime[j] = false;
            }
        }
    }
    vector<int> prime;
    for(int i = 2; i <= N; ++i){
        if(isprime[i]){
            prime.push_back(i);
        }
    }
    int size = prime.size();
    cout << size << endl;
    vector<int> cnt(prime.size(), 0);
    for(int i = 1; i <= n; ++i){
        int temp = s[i];
        for(int j = 0; j < size; ++j){
            if(temp % prime[j] == 0){
                cnt[j]++;
                while(temp % prime[j] == 0){
                    temp /= prime[j];
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < size; ++i){
        ans = max(ans, cnt[i]);
    }
    cout << ans << endl;
    return 0;
}
*/

int n;
const int N = 100010;
int s[N];
int cnt[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int ans = 1;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> s[i];
    }

    for(int i = 1; i <= n; ++i){
        int num = s[i];
        for(int j = 2; j * j <= num; ++j){
            if(num % j == 0){
                cnt[j]++;
                if (j != num / j)
                    cnt[num / j]++;
            }
        }
        cnt[num]++;
    }

    for(int i = 2; i <= N; ++i){
        ans = max(ans, cnt[i]);
    }
    cout << ans << endl;
}