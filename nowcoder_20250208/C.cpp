#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string a, b ,c;
ll n, x, y;
ll type[4][2];
ll cost = 1e16;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    bool flag = false;
    ll cnt = 0;
    cin >> n >> x >> y;
    cin >> a >> b >> c;
    for(int i = 0; i < n; ++i){
        int m = static_cast<int>(a[i] - '0');
        int n = static_cast<int>(b[i] - '0');
        int q = static_cast<int>(c[i] - '0');
        if(m == 1 && n == 0){
            if(q == 1){
                type[0][0]++;
                flag = true;
            }
            else
                type[0][1]++;
                cnt++;
        }
        else if(m == 0 && n == 1){
            if(q == 1){
                type[1][0]++;
                flag = true;
            }
            else
                type[1][1]++;
                cnt++;
        }
        else if(m == 1 && n == 1){
            if(q == 0){
                type[2][0]++;
                flag = true;
            }
            else
                type[2][1]++;
                cnt++;
        }
        else if(m == 0 && n == 0){
            if(q == 0){
                type[3][0]++;
                flag = true;
            }
            else
                type[3][1]++;
                cnt++;
        }
    }

    cost = min(cost, )

    return 0;
}