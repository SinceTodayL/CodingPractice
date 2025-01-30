#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int l = 0, r = 100;
    for(int i = l; i <= r; ++i){
        for(int j = l ; j <= r; ++j){
            if(i + j == (i ^ j) + (i & j) + (i | j)){
                cout << i << " " << j << endl;
            }
        }
    }

    return 0;
}