#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n,tmp, prefix_n = 0;
	cin >> n;
	vector<ll> prefix_num(n + 1, 0);
	for(int i = 1; i <= n; ++i){
		cin >> tmp;
		prefix_n += tmp;
		prefix_num[i] = prefix_n;
	}
	ll t, a, b;
	cin >> t;
	while(t--){
	    scanf("%lld %lld", &a, &b);
	    printf("%lld\n", prefix_num[b] - prefix_num[a-1]);
	}
    return 0;
}

