#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

set<int> Solve(const vector<tuple<int, int, int>>& a){
    auto [x, y, z] = a[0];
    set<int> res;
    auto Try = [&](int x){
        if(x < 0){
            return;
        }
        for (auto [u,v,w]:a){
            if (1LL*u*x+v==w) continue;
            if (1LL*u*x+w==v) continue;
            if (1LL*v*x+u==w) continue;
            if (1LL*v*x+w==u) continue;
            if (1LL*w*x+u==v) continue;
            if (1LL*w*x+v==u) continue;
            return;
          }
        res.insert(x);
    };
    Try((x-y)/z);
    Try((x-z)/y);
    Try((y-x)/z);
    Try((y-z)/x);
    Try((z-x)/y);
    Try((z-y)/x);
    return res;
}

void solve(){
    int n;
    cin >> n;
    vector<tuple<int, int, int>> a(n);
    for(auto& [x, y, z] : a){
        cin >> x >> y >> z;
    }
    auto t = Solve(a);
    assert(t.size() == 1U);
    cout << *t.begin() << endl;
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