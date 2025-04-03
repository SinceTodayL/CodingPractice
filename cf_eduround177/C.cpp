#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int find(int x, vector<int>& bing) {
    if(x != bing[x])
        bing[x] = find(bing[x], bing);
    return bing[x];
}

void merge(int x, int y, vector<int>& bing) {
    x = find(x, bing);
    y = find(y, bing);
    if(x != y)
        bing[x] = y;
}

void solve(){
    int n;
    cin >> n;
    vector<int> p(n + 1), d(n + 1);
    for(int i = 1; i <= n; i++) cin >> p[i];
    for(int i = 1; i <= n; i++) cin >> d[i];
    vector<int> bing(n + 1);
    for(int i = 1; i <= n; i++) bing[i] = i;
    for(int i = 1; i <= n; i++){
        merge(i, p[i], bing);
    }
    unordered_map<int, int> record;
    for(int i = 1; i <= n; i++){
        int rep = find(i, bing);
        record[rep]++;
    }
    ll cur = 0;
    unordered_set<int> used;
    for(int i = 1; i <= n; i++){
        int rep = find(d[i], bing);
        if(used.find(rep) == used.end()){
            cur += record[rep];
            used.insert(rep);
        }
        cout << cur << " ";
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
