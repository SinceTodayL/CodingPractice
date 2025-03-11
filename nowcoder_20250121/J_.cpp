#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
const int N = 2e5 + 10;
const int k = 20;
int a[N][k];
int flag[N];
int cal[N];
int n;
int two[20];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    two[0] = 1; 
    for(int i = 1; i <= 19; ++i){
        two[i] = 2 * two[i - 1];
    }

    cin >> n;
    int input;
    int max_ele = 0;
    for(int i = 1; i <= n; ++i){
        cin >> input;
        flag[input]++;
        int temp = 0;
        int t = input;
        max_ele = max(max_ele, input);
        while(input){
            if(input&1){
                a[t][temp] = 1;
            }
            temp++;
            input>>=1;
        }
        cal[t] = temp;
    }
    ll ans = 0;
    for(int i = 1; i <= max_ele; ++i){
        if(flag[i]){
            for(int j = 0; j < cal[i]; ++j){
                if(a[i][j] == 1){
                    // if(two[j] >= i - two[j])
                       // break;
                    ans += (flag[i] * flag[i - two[j]]);
                    break;
                    //cout << "i: " << i << endl;
                    //cout << ans << endl;
                }
                else{
                    ans += (flag[i] * flag[i + two[j]]);
                    //cout << i + two[j] << endl;
                    //cout << "i: " << i << endl;
                    //cout << ans << endl;
                }
            }
        }
    }
    cout << ans / 2 << endl;
    return 0;
}