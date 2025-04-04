#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e6 + 10;

void solve(){
    int n;
    cin >> n;
    if(n == 1){
        cout << "impossible" << '\n';
    }
    else if(n == 2){
        cout << "1 0" << '\n';
    }
    else{
        vector<int> ans(n + 1, 0);
        ans[0] = 1;
        ans[1] = 0;
        for(int i = 2; i <= n; ++i){
            ans[i] = i;
        }
        int flag = 1;
        for(int i = 2; i < n; ++i){
            if((flag ^ ans[i]) == 0){
                swap(ans[i], ans[i + 1]);
                flag = flag ^ ans[i] ^ ans[i + 1];
                ++i;
                if(i >= n){
                    cout << "impossible" << '\n';
                    return;
                }
            }
            else{
                flag ^= ans[i];
            }
        }
        for(int i = 0; i < n; ++i){
            cout << ans[i] << " ";
        }
        cout << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}