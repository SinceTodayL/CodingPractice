#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a; 

int main()
{
    cin >> a;
    double b = sqrt(2*a);
    ll ans = 0;
    for(int i = 1; i < b ; ++i){
    	if(i & 1){
    		if(!(a % i))
    		    ans++;
		}
		else{
			if(a % i == i/2)
			    ans++;
		}
	} 
	cout << ans;
    return 0;
}

