#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2001;

struct node{
    int index;
    int nums[N];
    int mod;
}a[N];
bool cmp(node l, node r){
    return l.mod < r.mod;
}

void solve(){
    int m, n;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        a[i].index = i;
        for(int j = 1; j <= m; ++j){
            cin >> a[i].nums[j];
        }
    }
    for(int i = 1; i <= n; ++i){
        a[i].mod = a[i].nums[1] % n;
        for(int j = 2; j <= m; ++j){
            if(a[i].nums[j] % n != a[i].mod){
                cout << -1 << endl;
                return;
            }
        }
    }
    sort(a + 1, a + n + 1, cmp);
    for(int i = 1; i <= n; ++i){
        cout << a[i].index << " ";
    }
    cout << endl;
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