#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

ll solve(int n){
	
	vector<int> factor(1, 0);
	for(int i = 1; i <= sqrt(n); ++i){
		if(n%i==0){
			factor.push_back(i);
		}
	}
	vector<int> res(factor);
	if(fabs(sqrt(n) - factor[factor.size()-1])>1e-6){
		res.push_back(n/factor[factor.size() - 1]);
	}
	for(int i = factor.size() - 2; i >= 1; --i){
		res.push_back(n/factor[i]);
	}
	int s = res.size()-1;
	ll ans = 0;
	for(int i = 2; i <= s; ++i){
		ans += res[i]*res[s+2-i];
	}
	ans -= n*(s-1);
	ans += 1;
	return ans;
}

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<solve(n)<<endl;
	} 
	
    return 0;
}

