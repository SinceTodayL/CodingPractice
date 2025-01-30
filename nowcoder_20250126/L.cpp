#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int pos(int i, int j){
    if(j > i){
        cout << "Wrong!" << endl;
        return -1;
    }
    int ans = 0;
    for(int k = 1; k <= i - 1; ++k){
        ans += k;
    }
    ans += j;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cout << "Yes" << endl;
    for(int i = 1; i <= n; ++i){
        for(int j = i; j <= n + 1; ++j){
            cout << pos(j, i) << " ";
        }
        for(int j = n + 1; j >= i + 2; --j){
            cout << pos(j, i + 1) << " " << pos(j - 1, i) << " ";
        }
    }
    for(int i = n + 1; i >= 1; --i){
        cout << pos(i, i) << " " ;
    }
    cout << endl;

    return 0;
}