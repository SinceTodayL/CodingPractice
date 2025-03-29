#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> skill(n);
    for(int i = 0; i < n; ++i)
        cin >> skill[i];
    sort(skill.begin(), skill.end());
    int index = lower_bound(skill.begin(), skill.end(), k) - skill.begin();
    int cnt = n - index;
    index--;
    int now = 0, skip = 0;
    while(index >= 0){
        skip++;
        now = skip * skill[index];
        index--;
        if(now >= k){
            skip = 0;
            cnt++;
        }
    }
    cout << cnt << endl;
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