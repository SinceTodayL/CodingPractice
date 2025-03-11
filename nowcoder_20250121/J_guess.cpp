#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int x, int y){
    return y == 0 ? x : gcd(y, x % y);
}

const int N = 100;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 1; i <= N; ++i){
        for(int j = i; j <= N; ++j){
            if(gcd(i, j) == (i ^ j)){
                cout << "gcd(" << i << "," << j << ") == " << i << " ^ " << j  << " == " << (i^j) << endl;
            }
        }
    }

    return 0;
}