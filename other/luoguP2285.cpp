#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 10005;
int n, m;
struct node{
    int x, y, time;
}a[N];

int dp[N];

int distance(node& n1, node& n2){
    return abs(n1.x - n2.x) + abs(n1.y - n2.y);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m ; ++i){
        cin >> a[i].time >> a[i].x >> a[i].y;
        dp[i] = 1;
    }
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j < i; ++j){
            if(distance(a[i], a[j]) <= abs(a[i].time - a[j].time)){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= m; ++i){
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;

    return 0;
}