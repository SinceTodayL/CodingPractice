#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[2010];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t, n;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0; i<n; ++i){
			cin>>a[i];
		}
		if(n == 1){
			cout<<"1"<<endl;
			continue;
		}
		ll ans = 1000000000000000000;
		if(n&1){

		for(int i=0; i<n; i+=2){
			ll k = 0;
			for(int j = 0; j<n; ){
				if(j == i){
					k = max(1ll, k);
					++j;
				}
				else{
					k = max(a[j+1]-a[j], k);
					j+=2;
				}
			}
			ans = min(k, ans);
		}
	}
	else{
		ans = 0;
		for(int i=0; i<n; i+=2){
			ans = max(ans, a[i+1]-a[i]);
		}
	}
	cout<<ans<<endl;
	}
    return 0;
}

