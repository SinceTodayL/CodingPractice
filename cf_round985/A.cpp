#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin>>t;
	int l, r, k;
	while(t--){
		cin>>l>>r>>k;
		cout<<max(0, r/k - l + 1)<<endl;
	}
    return 0;
}

