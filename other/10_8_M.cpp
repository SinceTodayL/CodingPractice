#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

int m ,n;
int am[5010];
int an[5010];
int flag[5010];

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; ++i){
	    cin>>an[i];
	    flag[i]=0;
	}
	
	for(int i=1; i<=m; ++i)
	    cin>>am[i];
	
	sort(am+1, am+m+1);
	sort(an+1, an+n+1);
	
	ll ans1=0;
	for(int i=1; i<=m; ++i){
		ll cha=INT_MAX, record;
		
		for(int j=1; j<=n; ++j){
			if(!flag[j]){
				if(cha>abs(am[i]-an[j])){
				    record=j;
					cha=abs(am[i]-an[j]);
				}
			}
		}
		flag[record]=1;
		ans1 += cha;
	}
	
	ll aans1=0, cnt=0;
	for(int i=1; i<=n; ++i){
		if(flag[i]){
			aans1+=(abs(an[i]-am[++cnt]));
		}
	}

	
	for(int i=1; i<=n; ++i)
	     flag[i]=0;
	
	ll ans2=0;
	for(int i=m; i>=1; --i){
		ll cha=INT_MAX, record;
		for(int j=n; j>=1; --j){
			if(!flag[j]){
				if(cha>abs(am[i]-an[j])){
				    record=j;
					cha=abs(am[i]-an[j]);
				}
			}
		}
		flag[record]=1;
		ans2 += cha;
	}
	
	ll aans2=0;
    cnt=0;
	for(int i=1; i<=n; ++i){
		if(flag[i]){
			aans2+=(abs(an[i]-am[++cnt]));
		}
	}
	
	cout<<min(aans1, aans2)<<endl;
    return 0;
}

