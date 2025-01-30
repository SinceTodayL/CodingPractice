#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[2010];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin>>t;
	while(t--){
		int num;
		cin>>num;
		for(int i=0; i<num; ++i){
			cin>>a[i];
		}
		int ans = INT_MAX;
		for(int i=0; i<num; ++i){
			int cnt=0;
			for(int j = i + 1; j<num; ++j){
				if(a[j]>a[i])
				    cnt++;
			}
			ans = min(ans, i + cnt);
		}
		cout<<ans<<endl;
	}
	
    return 0;
}

