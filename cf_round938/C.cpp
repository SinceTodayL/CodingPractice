#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll num[200010];
ll pre[200010];
ll bac[200010];
ll n, tmp;
ll k;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
    	scanf("%lld %lld", &n, &k);
    	for(int i=1; i<=n; ++i){
    		scanf("%lld", &tmp);
    		num[i]=tmp;
    		pre[i]=tmp+pre[i-1];
		}
        
        if(pre[n]<=k){
        	printf("%lld\n", n);
        	continue;
		}
        
		for(int i=1; i<=n; ++i){
			bac[i]=bac[i-1]+num[n+1-i];
		}
		
		ll obj1=upper_bound(pre+1, pre+n+1, (k+1)/2) - pre-1;
		ll obj2=upper_bound(bac+1, bac+n+1, k/2)-bac-1;
		printf("%lld\n", min(n, obj1+obj2));
	}
    return 0;
}

