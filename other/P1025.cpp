#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k; 
ll ans=0;


void dfs(int kk, int left, int m){
	if(kk==k-1){
		if(left>=m)
		    ans++;
		return;
	}
	for(int s=m; s<=left-k+kk; ++s){
		dfs(kk+1, left-s, s);
	}
	
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n>>k;
	int ck=0;
	for(int i=1; i<=n-k+1; ++i){
		dfs(1, n-i, i);
	}
	cout<<ans<<endl;
    return 0;
}

