#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int x, int y){
    return x%y==0 ? y : gcd(y, x%y);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll m, n;
	cin>>m>>n;
	ll mn = m*n;
	ll ans=0;
	for(int i=1; i<=n; ++i){
		if(mn%i == 0){
			if(gcd(i, mn/i)==m)
			    ans++;
		}
	}
	cout<<ans<<endl;
    return 0;
}

