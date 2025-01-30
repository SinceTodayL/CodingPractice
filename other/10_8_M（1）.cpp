#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

int an[5010];
int am[5010];
int dp[5010][5010];  // dp[i][j]表示在an的前i个元素中选择j个元素 与 am的前j个元素匹配 
int n, m; 

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; ++i)
	    cin>>an[i];
	for(int i=1; i<=m; ++i)
	    cin>>am[i];
	    
	sort(an+1, an+n+1);
	sort(am+1, am+m+1);
	for(int i=0; i<=n; ++i)
	    for(int j=0; j<=m; ++j)
	        dp[i][j]=static_cast<ll>(1e14);
	for(int i=0; i<=n; ++i)
	    dp[i][0]=0;
	    
	for(int i=1; i<=n; ++i)
	    for(int j=1; j<=min(i,m); ++j)
	        dp[i][j] = min(dp[i-1][j-1]+abs(an[i]-am[j]), dp[i-1][j]);
	        
	cout<<dp[n][m]<<endl;
	
    return 0;
}

