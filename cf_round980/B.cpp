#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

int n, k, a[200010], b[200010];

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i=0; i<n; ++i)
		cin>>a[i];
		sort(a, a+n);
		for(int i=1; i<n; ++i){
			b[i]=a[i]-a[i-1];
		}
		
		int ptr = 0, cnt = n;
		if(n*a[0]>=k){
			cout<<k<<endl;
			continue;
		}
		int all = n*a[0];
		while(ptr<n){
			while(b[ptr]==0 && ptr<n){
				ptr++;
				cnt--;
			}
			all += b[ptr]*cnt;
			if(k<=all){
				break;
			}
			ptr++;
			cnt--;
		}
		cout<<k+ptr<<endl;
	}
    return 0;
}

