#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < m; ++i){
        cin >> b[i];
    }
    vector<int> l(m, n), r(m, -1);
    int p1 = 0, p2 = 0;
    while(p2 < m && p1 < n){
        while(p1 < n && a[p1] < b[p2]){
            p1++;
        }
        l[p2] = p1;
        p2++;
        p1++;
    }
    p1 = n - 1, p2 = m - 1;
    while(p1 >= 0 && p2 >= 0){
        while(p1 >= 0 && a[p1] < b[p2]){
            p1--;
        }
        r[p2] = p1;
        p2--;
        p1--;
    }

    if(l[m - 1] != n || r[0] != -1){
        cout << 0 << endl;
        return;
    }
    if(m == 1){
        cout << b[0] << endl;
        return;
    }
    int ans = INT_MAX;
    for(int i = 0; i < m; ++i){
        if(i == 0){
            if(m > 1){
                if(r[1] != -1){
                    ans = min(ans, b[i]);
                }
            }
        }
        else if(i == m - 1){
            if(m > 1){
                if(l[m - 2] != n){
                    ans = min(ans, b[i]);
                }
            }
        }
        else{
            if(l[i - 1] < r[i + 1]){
                ans = min(ans, b[i]);
            }
        }
    }
    if(ans == INT_MAX){
        cout << -1 << endl;
    }
    else{
        cout << ans << endl;
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