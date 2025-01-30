#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


inline gcd(int x, int y){
	return y==0? x : gcd(y, x%y);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin>>n;
	int ans = 0, tmp;
	for(int i=0; i<n; ++i){
		cin>>tmp;
		if(tmp<0) tmp = -tmp;
		ans = gcd(ans, tmp);
	}
	cout<<ans<<endl;
    return 0;
}

