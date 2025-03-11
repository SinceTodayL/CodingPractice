#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
    	ll k, res;
    	scanf("%lld", &k);
    	ll sq = static_cast<ll>(sqrt(k));
    	ll tmp = static_cast<ll>(sqrt(k+sq));
    	if(tmp>sq){
    		printf("%lld\n", tmp+k);
		}
		else{
			printf("%lld\n", sq+k);
		}
	}
    return 0;
}

