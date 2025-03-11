#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n = 321;
    vector<int> mod(n);
    for(int i = 1; i <= n; ++i){
        mod[n % i]++;
    }
    int r;
    for(int i = 1; i <= n; i = r + 1){
        r = n / (n / i);
        cout << i << "--" << r << " : " << n / r << endl;
        for(int j = i; j <= r; ++j){
            cout << mod[j] << " ";
        }
        cout << endl;
    }
    return 0;
}