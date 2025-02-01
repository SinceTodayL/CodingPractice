#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 3;

// 求 1-n 之间所有值的欧拉函数
vector<int> Euler;
void EulerN(){
    Euler.resize(N, 0);
    for(int i = 1; i <= N; ++i){
        Euler[i] = i;
    }
    for(int i = 2; i <= N; ++i){
        if(Euler[i] == i){
            for(int j = i; j <= N; j += i){
                Euler[j] = (Euler[j] / i) * (i - 1);  
            }
        }
    }
}

// 求单个数的欧拉函数
int Euler1(int n){
    int ans = n;
    for(int i = 2; i * i <= n; ++i){
        if(n % i == 0){
            ans = (ans / i) * (i - 1);
            while(n % i == 0){
                n /= i;  // 去掉n的质因数分解中所有关于i的部分
            }
        }
    }
    if(n != 1){
        ans = (ans / n) * (n - 1);
    }
    return ans;
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    

    return 0;
}