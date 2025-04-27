#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n, k;
    cin >> n >> k;
    int maxa = INT_MIN, mina = INT_MAX;
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        maxa = max(maxa, a[i]);
        mina = min(mina, a[i]);
    }
    bool flag = false;
    for(int i = 1; i <= n; ++i){
        cin >> b[i];
        if(b[i] != -1){
            flag = true;
        }
    }
    if(!flag){
        if(maxa > k){
            cout << 0 << endl;
        }
        else{
            cout << k - (maxa - mina) + 1 << endl;
        }
    }
    else{
        set<int> s;
        for(int i = 1; i <= n; ++i){
            if(a[i] != -1 && b[i] != -1){
                s.insert(a[i] + b[i]);
                if(s.size() > 1){
                    cout << 0 << endl;
                    return;
                }
            }
        }
        int ele = *s.begin();
        for(int i = 1; i <= n; ++i){
            if(b[i] == -1){
                if(ele - a[i] > k || ele < a[i]){
                    cout << 0 << endl;
                    return;
                }
            }
        }
        cout << 1 << endl;
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