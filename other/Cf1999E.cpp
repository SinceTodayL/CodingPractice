#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll l, r, num, xx;
ll p3[22];

void init()
{
	p3[0] = 1;
	p3[1] = 3;
	for(int i = 2; i <= 20; i++)
	{
		p3[i] = p3[i-1] * 3;
	}
}

ll get(ll x)
{
	
}

void solve()
{
	num = 0;
	scanf("%lld %lld", &l, &r);
	
	
	ll tl=l;
	while(tl>0){
		num+=2ll;
		tl/=3ll;
	}
	ll tleft,tright;
	++l;
	for(ll i=0;i<=19;++i){
		if(r<p3[i]||l>=p3[i+1]) continue;
		tleft=max(p3[i],l);
		tright=min(r,p3[i+1]-1);
		num+=(tright-tleft+1)*(i+1);
	}
	
	printf("%lld\n",num);
}

int main()
{
	int t;
	init();
	scanf("%lld", &t);
	while(t--)solve();
    return 0;
}

