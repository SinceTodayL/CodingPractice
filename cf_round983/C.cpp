#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[200010];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0; i<n; ++i)
		cin>>a[i]; 
		sort(a, a+n);
		int ans = INT_MAX;
		for(int i=0; i<=n-3; ++i){
			int tmp = a[i]+a[i+1];
			int t = (a+n)-lower_bound(a, a+n, tmp);
			ans = min(ans, i+t);
		}
		cout<<ans<<endl;
		
	}
    return 0;
}

