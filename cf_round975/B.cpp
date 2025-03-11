#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, q;
ll cal_i(ll x){
	return -(x*x) + (n+1)*x -1;
}

ll cal_l(ll x){
	return (n-x+1)*(x-1);
}


int main()
{
    int t;
    scanf("%d", &t);
	ll tmp;
    ll num[200010];
    unordered_map<ll, ll> times;
    while(t--){
    	times.clear();
    	scanf("%lld %lld", &n, &q);
    	for(int i=1; i<=n; ++i)
    	    scanf("%lld", &num[i]);
    	    
        for(ll i=1; i<=n; ++i){
        	times[cal_i(i)]+=1;
		}
		for(ll i=2; i<=n; ++i){
			times[cal_l(i)] +=(num[i]-num[i-1]-1);
		}
		
		ll tmp;
		while(q--){
			scanf("%lld", &tmp);
			if(times.find(tmp) == times.end())
			    printf("0 ");
			else
			    printf("%lld ", times[tmp]);
		}
		printf("\n");
	}
    return 0;
}

