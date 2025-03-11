#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string s;
    cin >> n >> s;
    s = "#" + s;

    int cnt;
    int ans = 0;
    int temp_ans;
    for(int i = 0; i < 26; ++i){
        char ch = 'a' + i;
        cnt = 0;
        vector<int> pos;
        pos.push_back(0);
        for(int i = 1; i <= n; ++i){
            if(s[i] == ch){
                cnt++;
                pos.push_back(i);
            }
        }
        if(cnt >= 2){
            temp_ans = max(n - pos[2] + 1, pos[cnt - 1]);
        }
        ans = max(ans, temp_ans);
    }
    if(ans > 1)
        cout << ans << endl;
    else{
            cout << 0 << endl;
        }
    return 0;
}