#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int m[1010][1010];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0; i<n; ++i)
		for(int j = 0; j<n; ++j)
		cin>>m[i][j];
		
	    ll ans = 0;
	    for(int all = 0; all <=n-1; ++all){
	    	int tmp = 0;
	    	for(int i = all; i<n; ++i){
	    		tmp = min(tmp, m[i][i-all]);
			}
						ans += abs(tmp);
		}
		for(int all = 1-n; all<0; ++all){
			int tmp = 0;
			for(int i = 0; i<n+all; ++i){
				tmp = min(tmp, m[i][i-all]);
			}
			ans += abs(tmp);
		}
		cout<<ans<<endl;
	}
	
    return 0;
}

