#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int x, y, k;
		cin>>x>>y>>k;
		int res = min(x, y);
		cout<<"0 0 "<<res<<" "<<res<<endl;
		cout<<"0 "<<res<<" "<<res<<" 0 "<<endl;
	}
    return 0;
}

