#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int t;
int n;
int a[500010];
int p[500010];
#define N 1e5
double dp[500010];
bool flag[500010];

double dfs(int x){
	if(flag[x])
	    return dp[x];
	
	dp[x] = min(1 + dfs(x+1),(((N - p[x])/N)*(dfs(a[x]) + 1) + (p[x]/N)*1));
	flag[x] = true;
	cout << x << "    "<< dp[x] << endl;
	return dp[x];
}

int main()
{
    scanf("%d", &t);
    while(t--){
    	scanf("%d", &n);
    	for(int i = 0; i < n; ++i){
    		scanf("%d", &a[i]);
		}
		for(int i = 0; i <= n; ++i){
			flag[i] = false;
		}
		for(int i = 0; i < n; ++i){
			scanf("%d", &p[i]);
		}
		
		dp[n] = 0;
		flag[n] = true;
		dp[n - 1] = 1;
		flag[n-1] = true;
		
		
		printf("%lf\n", dfs(0));
		cout << endl;
	}
    return 0;
}

