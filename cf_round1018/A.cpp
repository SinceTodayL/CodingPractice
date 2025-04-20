#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int big = 0, sma = 0;
    for(int i = 0; i < n - 1; ++i){
        if(s[i] == '>'){
            big++;
        }
        else{
            sma++;
        }
    }
    int bi = n - big, sm = sma;
    vector<int> ans;
    ans.push_back(bi);
    bi++;
    for(int i = 0; i < n - 1; ++i){
        if(s[i] == '>'){
            ans.push_back(bi);
            bi++;
        }
        else{
            ans.push_back(sm);
            sm--;
        }
    }
    for(int i = 0; i < n; ++i){
        cout << ans[i] << " ";
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