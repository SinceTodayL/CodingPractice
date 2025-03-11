#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
string s;
const int N = 4e5 + 20;
int dp[N];
int dp1[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, 0, sizeof(dp));
    memset(dp1, 0, sizeof(dp1));
    cin >> n >> s;
    s = "0" + s;
    if(s[n - 1] == s[n]){
        dp[n - 1] = 1;
    }
    for(int i = n - 2; i >= 1; --i){
        int temp = i;
        if(s[i] == s[n - dp[i + 1]]){
            dp[i] = dp[i + 1] + 1;
        }
        else{
        while(s[temp] != s[n - dp[temp + 1]] && temp < n - 1){
            temp = n - dp[temp + 1];
        }
        if(s[i] == s[temp])
            dp[i] = dp[temp + 1] + 1;
        }
    }
    int ans = 0;
    bool flag = false;
    for(int i = 1; i <= n - 1; ++i){
        if(dp[i] != 0){
            flag = true;
            ans = max(ans, i - 1 + dp[i]);
        }
    }
    if(s[1] == s[2]){
        dp1[2]= 1;
    }
    for(int i = 3; i <= n; ++i){
        int temp = i;
        if(s[i] == s[dp1[i - 1] + 1]){
            dp1[i] = dp1[i - 1] + 1;
        }
        else{
        while(s[temp] != s[dp1[temp - 1] + 1] && temp > 2){
            temp = dp1[temp - 1] + 1;
        }
        if(s[i] == s[temp])
            dp1[i] = dp1[temp - 1] + 1;
        }

        
    }

/*
    for(int i = 1; i <= n; ++i){
        cout << dp1[i] << " ";
    }
    */

   for(int i = 2; i <= n; ++i){
        if(dp1[i] != 0){
            flag = true;
            ans = max(ans, n - i + dp1[i]);
        }
    }

    if(flag && ans > 1){
        cout << ans << endl;
    }
    else{
        cout << 0 << endl;
    }
    return 0;
}