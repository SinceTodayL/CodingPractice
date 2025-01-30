#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m;
ll k;
ll x[200010], y[200010];
ll max_num = 0;

int main()
{
    scanf("%lld %lld", &n, &m);
    scanf("%lld", &k);
    for(int i=1; i<=k; ++i){
    	scanf("%lld %lld", &x[i], &y[i]);
    	if(x[i]<=y[i])
    	    max_num++;
	}
	printf("%lld", max_num);
    return 0;
}

