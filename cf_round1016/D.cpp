#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string a[4] = {"00", "01", "10", "11"};
ll pow2[63];

void init(){
    ll a = 1;
    for(int i = 0; i <= 62; ++i){
        pow2[i] = a;
        a *= 2;
    }
}

vector<int> dis(int x, int n){
    vector<int> ans(n, 0);
    int cnt = 0;
    while(x){
        if(x & 1){
            ans[cnt] = 1;
        }
        x /= 2;
        cnt++;
    }
    return ans;
}

void solve(){
    int n, q;
    string s;
    cin >> n >> q;
    while(q--){
        cin >> s;
        if(s == "->"){
            int x, y;
            cin >> x >> y;
            x--; 
            y--;
            ll ans = 0;
            vector<int> xx = dis(x, n);
            vector<int> yy = dis(y, n);
            for(int i = 0; i < n; ++i){
                if(xx[i] == 1 && yy[i] == 0){
                    ans += 2 * pow2[i * 2];
                }
                else if(xx[i] == 1 && yy[i] == 1){
                    ans += pow2[i * 2];
                }
                else if(xx[i] == 0 && yy[i] == 1){
                    ans += 3 * pow2[i * 2];
                } 
            }
            cout << ans + 1 << endl;

        }
        else{
            ll value, x = 0, y = 0;  
            cin >> value;
            value--;
            int cnt = 0;
            while(value){
                int mod = value % 4;
                if(mod == 1){
                    x += pow2[cnt];
                    y += pow2[cnt];
                }
                else if(mod == 2){
                    x += pow2[cnt];
                }
                else if(mod == 3){
                    y += pow2[cnt];
                }
                cnt++;
                value /= 4;
            }
            cout << x + 1 << " " << y + 1 << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}