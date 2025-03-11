#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10;
int flag[N];

void solve(){
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<vector<int>> F(n + 1);
    vector<vector<int>> G(n + 1);
    int x, y;
    for(int i = 1; i <= m1; ++i){
        cin >> x >> y;
        if(x > y){
            swap(x, y);
        }
        F[x].push_back(y);
    }
    for(int i = 1; i <= m2; ++i){
        cin >> x >> y;
        if(x > y){
            swap(x, y);
        }
        G[x].push_back(y);
    }
    int overlap = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            flag[j] = 0;
        }
        for(int ele:F[i]){
            flag[ele] = 1;
        }
        for(int ele:G[i]){
            if(flag[ele]){
                overlap++;
            }
        }
    }
    cout << m1 + m2 - 2 * overlap << endl;
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