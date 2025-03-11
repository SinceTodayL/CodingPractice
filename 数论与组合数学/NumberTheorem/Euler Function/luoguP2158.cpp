#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 40010;
vector<int> Euler;
void EulerSolve(){
    Euler.resize(N + 1, 0);
    for(int i = 1; i < N; ++i){
        Euler[i] = i;
    }
    for(int i = 2; i < N; ++i){
        if(Euler[i] == i){
            for(int j = i; j <= N; j += i){
                Euler[j] = (Euler[j]/i)*(i - 1);
            }
        }
    }
    for(int i = 1; i < N; ++i){
        Euler[i] += Euler[i - 1];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    EulerSolve();
    int n;
    cin >> n;
    if(n != 1)
    cout << 2 * Euler[n-1] + 1 << endl;
    else
    cout << 0 << endl;
    return 0;
}