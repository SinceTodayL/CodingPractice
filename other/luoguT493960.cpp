#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, s, v, x; 

bool judge(ll m){
	ll max_n = 0;
	ll tmp_x = x + 1;
	ll tmp_v = v;
	while(tmp_x--){
		max_n += m/tmp_v ;
        tmp_v += s;
	}
	if(max_n < n)
	    return false;
	else
	    return true;
}

int main()
{
	cin >> n >> s >> v >> x;
	ll left = 1, right = v * n;
	
	while(left < right){
		ll mid = left + (right - left)/2;
		if(judge(mid))
		    right = mid;
		else
		    left = mid + 1;
	}
	cout<<left;
    return 0;
}

