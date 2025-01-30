#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fp(ll n, ll x){
	if(x==0)
	return 1;
	ll tmp=fp(n, x/2);
	if(x&1)
	return tmp*tmp*n;
	else
	return tmp*tmp;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
    	ll m, k;
    	cin>>m>>k;
    	if(k==1){
    		cout<<m<<endl;
    		continue;
		}
		ll r=0, tmpValue=1;
		while(tmpValue<=m){
			tmpValue*=k;
			r++;
		}
		r--;
		tmpValue=m;
		int res=0;
		while(tmpValue>0){
			if(fp(k, r)>tmpValue){
				r--;
				continue;
			}
			ll power=fp(k, r);
			res+=tmpValue/power;
			tmpValue%=power;
			r--;
		}
		cout<<res<<endl;
	}
    return 0;
}

