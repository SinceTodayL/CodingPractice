#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string s;
    cin >> n >> s;
    int volocity = 0;
    ll ans = 0;
    for(int i = 0; i < n; ++i){
        if(s[i] == '0'){
            volocity += 10;
            ans += volocity;
        }
        else if(s[i] == '1'){
            volocity = max(volocity - 5, 0);
            ans += volocity;
        }
        else{
            ans += (max(0, volocity - 10));
        }
    }
    cout << ans << endl;

    return 0;
}