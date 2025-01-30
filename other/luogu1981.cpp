#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define mod 10000


int main()
{
	ll tmp1;
	char tmp2;
	ll res = 0;
	ll cheng = 0;
	char tmp3 = '+';
	while(1){
		scanf("%lld", &tmp1);
		tmp2 = getchar();
		res %= mod;
		if(tmp2 == '+'){
			if(tmp3 != '*')
			    res = (res + tmp1%mod) % mod;
			else{
				cheng = ((cheng%mod)* (tmp1%mod))%mod;
				res = (res + cheng%mod) % mod;
				cheng = 0;
			}
		}
		else if(tmp2 == '*'){
			if(tmp3 == '+'){
				cheng = tmp1%mod;
			}
			else{
				cheng = (cheng*(tmp1%mod))%mod;
			}
		}
		else{
			if(tmp3 == '+'){
				res = (res + (tmp1%mod))%mod;
			}
			else{
				cheng = ((cheng%mod)* (tmp1%mod))%mod;
				res = (res + cheng%mod) % mod;
			}
			break;
		}
		tmp3 = tmp2;
	}
	cout << res%mod << endl;
    return 0;
}

