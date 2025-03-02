#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int mod = 998244353;
const int N = 300010;
int father[N];
int step[N];
int res[N];

void solve(){
    int n;
    cin >> n;
    for(int i = 0; i <= n + 1; ++i){
        father[i] = 0;
        step[i] = 0;
        res[i] = 1;
    }
    for(int i = 2; i <= n; ++i){
        cin >> father[i];
    }
    step[1] = 0;
    int max_step = 0;
    for(int i = 2; i <= n; ++i){
        step[i] = step[father[i]] + 1;
        max_step = max(max_step, step[i]);
    }
    vector<vector<int>> bystep(max_step + 1);
    vector<vector<int>> node(n + 1);
    for(int i = 2; i <= n; ++i){
        node[father[i]].push_back(i);
    }
    for(int i = 1; i <= n; ++i){
        bystep[step[i]].push_back(i);
    }
    int tot = bystep[max_step].size();
    int next = 0;
    
    for(int i = max_step - 1; i >= 1; --i){
        for(int ele : bystep[i]){
            int temp = tot;
            for(int element : node[ele]){
                temp -= res[element];
            }
            res[ele] = (res[ele] + temp) % mod;
            next += res[ele];
        }
        tot = next;
        next = 0;
    }
    for(int ele : bystep[1]){
        res[1] += res[ele];
        res[1] %= mod;
    }
    cout << res[1] % mod << endl;
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