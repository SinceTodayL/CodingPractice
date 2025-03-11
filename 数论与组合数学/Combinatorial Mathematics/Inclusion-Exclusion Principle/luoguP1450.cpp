#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
    本题的暴力写法，但是还是利用了容斥原理的思想
        cin>>d[1]>>d[2]>>d[3]>>d[4]>>s;
        LL ans = dp[s];
        if(s >= f(1)) ans -= dp[s - f(1)];
        if(s >= f(2)) ans -= dp[s - f(2)];
        if(s >= f(3)) ans -= dp[s - f(3)];
        if(s >= f(4)) ans -= dp[s - f(4)];
        if(s >= f(1) + f(2)) ans += dp[s - f(1) - f(2)];
        if(s >= f(1) + f(3)) ans += dp[s - f(1) - f(3)];
        if(s >= f(1) + f(4)) ans += dp[s - f(1) - f(4)];
        if(s >= f(2) + f(3)) ans += dp[s - f(2) - f(3)];
        if(s >= f(2) + f(4)) ans += dp[s - f(2) - f(4)];
        if(s >= f(3) + f(4)) ans += dp[s - f(3) - f(4)];
        if(s >= f(1) + f(2) + f(3)) ans -= dp[s - f(1) - f(2) - f(3)];
        if(s >= f(1) + f(2) + f(4)) ans -= dp[s - f(1) - f(2) - f(4)];
        if(s >= f(1) + f(3) + f(4)) ans -= dp[s - f(1) - f(3) - f(4)]; 
        if(s >= f(2) + f(3) + f(4)) ans -= dp[s - f(2) - f(3) - f(4)];
        if(s >= f(1) + f(2) + f(3) + f(4)) ans += dp[s - f(1) - f(2) - f(3) - f(4)];

*/

const int N = 100005;
ll dp[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int c[4], d[4];
    for(int i = 0; i < 4; ++i){
        cin >> c[i];
    }
    dp[0] = 1;
    
    /*
        完全背包
        即本题在没有任何限制的情况下
        已知有 c[4] 共4种货币面值，每种货币的数量不限，给定 s，求 s 元的组成方案数
    */
    for(int i = 0; i < 4; ++i){
        for(int j = c[i]; j < N; ++j){
            dp[j] += dp[j - c[i]];  
        }
    }

    int t;
    cin >> t;
    while(t--){
        for(int i = 0; i < 4; ++i){
            cin >> d[i];
        }
        int s;
        cin >> s;
        ll ans = dp[s];
        for(int i = 1; i < (1 << 4); ++i){
            int now = s;
            int temp = i;
            int flag = 0;
            for(int j = 0; temp > 0; ++j){
                if(temp & 1){
                    flag ^= 1;  // 反转奇偶
                    now -= (d[j] + 1) * c[j];
                }
                temp >>= 1;
            }
            if(now < 0){
                continue;
            }
            if(flag == 0)  {  // 代表最终集合内元素为偶数
                ans += dp[now];
            }
            else{
                ans -= dp[now];
            }
        }
        cout << ans << endl;
    }

    return 0;
}