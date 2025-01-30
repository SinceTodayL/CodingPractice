#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

const ll mod = 1e9+7;
int cha[200010];
unordered_map<int, ll> rec;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		string a;
		rec.clear();
		bool zhaocha=true;
		getline(cin, a);
		cha[0]=0;
		for(int i=0; i<a.size(); ++i){
			if(a[i]=='1'){
			    cha[i+1]=cha[i]+1;
			    zhaocha=false;
			}
			else
			    cha[i+1]=cha[i]-1;
		}
		if(zhaocha){
			cout<<"0"<<endl;
			continue;
		}
		ll ans=0;
		for(int i=0; i<=a.size(); ++i){
		    ans = (ans + (rec[cha[i]])*(a.size()-i+1))%mod;
		    rec[cha[i]]+=(i+1);
		}
		
		cout<<ans%mod<<endl;
	}
    return 0;
}

