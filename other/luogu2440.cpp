#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll length[100010];
ll n, k;

ll cal(ll x){
	ll res = 0;
	if (x == 0)
	    return INT_MAX;
	for(ll i = 1; i <= n; ++i){
		res += length[i]/x;
	}
	return res;
} 

int main()
{
	cin>>n>>k;
	ll max_length = 0;
	for(ll i = 1; i <= n; ++i){
	    scanf("%d", &length[i]);
	    max_length = max(max_length, length[i]);
    }
    ll left = 0;
    ll right = max_length;
    ll mid, tmp;
    
    while(left < right){
    	mid = (left + right + 1)>>1;
    	tmp = cal(mid);
    	if(tmp >= k)
    		left = mid;
		else if(tmp < k)
			right = mid - 1;

	}
    
	cout<<left;
    return 0;
}

