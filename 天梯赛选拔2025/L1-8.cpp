#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

int n, m;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    vector<int> buff(m);
    vector<int> day(n);
    for(int i = 0; i < m; ++i){
        cin >> buff[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> day[i];
    }
    sort(buff.begin(), buff.end());
    ll ans = 0;
    for(int i = 0; i < n; ++i){
        int index = upper_bound(buff.begin(), buff.end(), day[i]) - buff.begin();
        if(index == 0){
            ans += abs(buff[0] - day[i]);
        }
        else if(index == n){
            ans += abs(day[i] - buff[m - 1]);
        }
        else{
            ans += min(abs(day[i] - buff[index]), abs(day[i] - buff[index - 1]));
        }
    }
    cout << ans << endl;
    return 0;
}