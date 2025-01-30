#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int mod = 1e9+7;
int n[100010];
int k[100010];

int fp(int x){
	if(x==0)
	 return 1;
	if(x==1)
	 return 2;
     
    int tmp = fp(x/2)%mod;
    if(x&1)
        return ((((tmp%mod)*tmp)%mod)*2)%mod;
    else
        return ((tmp%mod)*tmp)%mod;
	 
}

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin>>t;
	for(int i=1; i<=t; ++i){
		cin>>n[i];
	}
	for(int i=1; i<=t; ++i){
		cin>>k[i];
	}
	for(int i=1; i<=t; ++i)
	    cout<<fp(k[i])<<endl;
    return 0;
}

