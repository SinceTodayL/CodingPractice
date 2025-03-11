#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int n;
	cin>>n;
	if(n <= 4){
		cout<<"-1"<<endl;
		return;
	}
	for(int i=1; i<=n; ++i){
		if(i&1 && i != 5){
			cout<<i<<" ";
		}
	}
	cout<<"5 4 ";
	for(int i=1; i<=n; ++i){
		if(i%2==0 && i!=4){
			cout<<i<<" ";
		}
	}
	cout<<endl;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
    return 0;
}

