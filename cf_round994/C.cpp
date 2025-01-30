#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

ll a[210][420];
ll dp[210][210][210];
ll ans[210][210];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll t;
	cin >> t;
	ll n, m, k;
	while(t--){
		cin >> n >> m >> k;
		
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				cin >> a[i][j];
				a[i][j + m] = a[i][j];
			}
		}
		
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
			    ans[i][j] = 1ll << 60; 
			}
		}
		for(int i = 0; i < n; ++i)
		    for(int j = 0; j < m; ++j)
		        for(int s = 0; s < m; ++s){
		        	dp[i][j][s] = 1ll << 60;
				}
		
		for(int i = 0; i < n; ++i){
			if(i != 0){
				for(int j = 0; j < m; ++j){
					if(j == 0){
						for(int s = 0; s < m; ++s){
							dp[i][j][s] = k*s + ans[i - 1][j] + a[i][j + s];
						}
					}
					else{
						for(int s = 0; s < m; ++s){
							dp[i][j][s] = min(ans[i - 1][j] + k*s + a[i][j + s], dp[i][j - 1][s] + a[i][j + s]);
						}
					}
				}
			}
			else{
				for(int j = 0; j < m; ++j){
					if(j == 0){
						for(int s = 0; s < m; ++s){
							dp[i][j][s] = k*s + a[i][j + s];
						}
					}
					else{
						for(int s = 0; s < m; ++s){
							dp[i][j][s] = dp[i][j - 1][s] + a[i][j + s];
						}
					}
				}
			}

			for(int j = 0; j < m; ++j)
			    for(int p = 0; p < m; ++p){
			    	ans[i][j] = min(ans[i][j], dp[i][j][p]);
			   
		    	}
		    }
	cout << ans[n - 1][m - 1] << endl;
	}
    return 0;
}

