#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 1e9 + 7;

int fp(int a, int x){
    int ans = 1;
    while(x){
        if(x & 1){
            ans  = (ans * a) % N;
        }
        a = (a * a) % N;
        x >>= 1;
    }
    return ans % N;
}

int cal(int p){
    int q = fp(2, N - 2);
    int ans = (p * q) % N;
    return ans;
}

void solve(){
    int n;
    string s;
    cin >> n >> s;
    reverse(s.begin(), s.end());
    int ans = 0;
    int i = 0;
    int len = s.size();
    while(i < len - 1){
        if(s[i] == '0'){
            ans += 2;
        }
        else{
            if(s[i + 1] == '0'){
                ans += 1;
                s[i + 1] = '1';
            }
            else{
                int j = i + 1;
                ans += 1;
                while(j < s.size() && s[j] == '1'){
                    s[j] = '0';
                    j++;
                }
                if(j < s.size()){
                    s[j] = '1';
                }
                else{
                    s.push_back('1');
                }
            }
        }
        ++i;
        len = s.size();
    }
    cout << cal(ans) << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}