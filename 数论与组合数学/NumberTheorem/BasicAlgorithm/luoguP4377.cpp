#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 255;
const int WW = 1005;
const int INF = 0x3f3f3f3f;
int n, w;
struct node{
   int a, b;
   double y;
}point[N];
double dp[WW];

bool check(double x){
    for(int i = 0; i < n; ++i){
        point[i].y = -x*point[i].a + point[i].b*1.0;
    }
    for(int i = 0; i <= w; ++i){
        dp[i] = -INF;
    }
    dp[0] = 0;
    for(int i = 0; i < n; ++i){
        for(int j = w; j >= 0; --j){
            if(j + point[i].a >= w){
                dp[w] = max(dp[w], dp[j] + point[i].y);
                // cout << dp[w] << endl;
            }
            else{
                dp[j + point[i].a] = max(dp[j + point[i].a], dp[j] + point[i].y);
            }
        }
    }

    return dp[w]<0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> w;
    double r = 0, l = 0;
    for(int i = 0; i < n; ++i){
         cin >> point[i].a >> point[i].b;
         r += point[i].b;
    }
    while(fabs(r - l) > 1e-6){
        double mid = (r - l) / 2 + l;
        if(check(mid)){
            r = mid;
        }
        else{
            l = mid;
        }
        cout << mid << endl;
    }
    cout << static_cast<int>(1000* (l + 1e-6)) << endl;
    return 0;
}

/*
题后思考：
这题使用了二分法、01动态规划（背包问题）
本题中对二分法的使用很巧妙，先假定一个数，再去慢慢二分，探索，用check函数判断假定的数是否合理
能这样用的前提是：单调性

还有01动态规划的背景，实际上是一个优化问题，不一定非要是在m容量下的最大价值
也可以像本题一样，限定最小背包使用容量，在此基础上求最大值
好题！
*/

