#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int m[100010];

int check(int a, int b, int c, int d){
	int num[4]={a,b,c,d};
	int ans = 0;
	for(int i=0; i<4; ++i){
		ans =0;
		for(int j=0; j<4; ++j){
			if(j != i && num[i]==num[j])
			    ans++;
		}
		if(ans == 3)
		return 2;
		else if(ans == 2)
		return 1;
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=1; i<=n; ++i)
		cin>>m[i];
		vector<pair<int,int>> mm;
		int ans = 0;
		if(n&1){
			int mid = m[n/2 + 1];
			for(int i=1; i<= n/2; ++i){
				mm.push_back(make_pair(m[i], m[n-i+1]));
			}
			for(int i=1; i<= (n/2 - 1); ++i){
				ans += check(mm[i-1].first, mm[i-1].second, mm[i].first, mm[i].second);
			}
			if(mid == mm[n/2-1].first && mid==mm[n/2-1].second)
			ans+=2;
			else if(mm[n/2-1].first == mid)
			ans +=1;
			else if(mm[n/2-1].second == mid)
			ans += 1;
			 
		}
		else{
			auto mid = make_pair(m[n/2],m[n/2+1]);
			for(int i=1; i<= n/2 ; ++i){
				mm.push_back(make_pair(m[i], m[n-i+1]));
			}
			for(int i=1; i<= (n/2 - 1); ++i){
				ans += check(mm[i-1].first, mm[i-1].second, mm[i].first, mm[i].second);
			}
			if(mid.first == mid.second)
			ans++;
		}
		cout<<ans<<endl;
	}
    return 0;
}

