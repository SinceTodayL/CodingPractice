#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int nums, posa, posb;
    cin >> nums >> posa >> posb;
    if(abs(posa - posb) & 1){
        cout << "no" << endl;
    }
    else{
        cout << "yes" << endl;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}