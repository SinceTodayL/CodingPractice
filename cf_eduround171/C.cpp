#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin>>t;
	while(t--){
		int n;
		string a;
		cin>>n;
		cin>>a;
		vector<ll> res;
		int cnt=0;
		ll all = 0;
		
		for(int i=0; i<n;++i){
			all +=(i+1);
			if(a[i]=='1'){
			    res.push_back(i+1);
			    cnt++;
			}
		}
		
		for(int i=n-1; i>=0; --i){
			if(a[i] == '0'){
				if(i < res[cnt - 1] && cnt > 0){
					all -= res[cnt-1];
					cnt--;
				}
			}
		}
	
        for(int i=cnt; i>cnt-cnt/2; --i){
        	all -= res[i - 1];
		}	
		cout<<all<<endl;
	}
	
    return 0;
}

