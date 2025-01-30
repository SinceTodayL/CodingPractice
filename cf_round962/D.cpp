#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n, x;
		cin>>n>>x;
		ll ans=0;
		for(int a=1; a<=min(n, x); ++a){
			for(int b=1; a*b<n and a+b<x; ++b){
				ans += min(x-a-b, (n-a*b)/(a+b));
			}
		}
		cout<<ans<<endl;
	}
    return 0;
}

