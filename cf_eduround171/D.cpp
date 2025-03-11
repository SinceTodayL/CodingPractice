#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define int long long

int a[300010];
int pa[300010];
int ppa[300010];
int pppa[300010];
int pppppa[300010];

int prefix[300010];

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n, tmp;
	cin>>n;
	for(int i=1; i<=n; ++i){
		cin>>a[i];
	}
	for(int i=1; i<=n; ++i){
		pa[i] = a[i] + pa[i-1];
	}

	
	for(int i=1; i<=n; ++i){
		ppa[i] = ppa[i-1]+(n+1-i)*a[i];
	}
	
	pppa[1] = ppa[n];
	for(int i=2; i<=n; ++i){
		pppa[i] = pppa[i-1] - ppa[i-1];
	}
	
	for(int i=1; i<=n; ++i){
		ppppa[i] = pppp[i-1]+ppp[i];
	}
	
    for(int i=1; i<=n; ++i){
    	prefix[i]=prefix[i-1]+(n+1-i);
	}
     

	int q;
	cin>>q;
	while(q--){
		
		int l, r;
		cin>>l>>r;
	    int posl = lower_bound(prefix, prefix+n+1, l) - prefix;
		int posr = lower_bound(prefix, prefix+n+1, r) - prefix;
		int delta_l = l - prefix[posl];
		int delta_r = r - prefix[posr];
		
		int ans1 = 0, ans2 = 0, ans3 = 0;
		if(posl!=0)
		    ans1 = ppppa[posr]-ppppa[posl-1];
		else
		    ans1 = ppppa[posr];
		
		ans2 = pa[posr+delta_r]-pa[posr];
		ans3 = pa[posl+delta_l-1]-pa[posl];
		cout<<ans1+ans2-ans3<<endl;
	}
	
		
    return 0;
}

