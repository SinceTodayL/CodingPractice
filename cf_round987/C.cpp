#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	int n;
	cin>>n;
	if(n%2 == 0){
		int cnt=1;
		for(int i=1; i<=n; i+=2){
			cout<<cnt<<" "<<cnt<<" ";
			cnt++;
		}
		cout<<endl;
		return;
	}
	else if(n < 27){
		cout<<"-1"<<endl;
		return;
	}
	else if(n == 27){
		cout<<"1 2 2 3 3 4 4 5 5 1 13 6 6 7 7 8 8 9 9 10 10 11 11 12 12 1 13"<<endl;
		return;
	}
	else{
		cout<<"1 2 2 3 3 4 4 5 5 1 6 6 7 7 8 8 9 9 10 10 11 11 12 12 13 1 14 14 13 ";
		int cnt=15;
		for(int i=30; i <= n; i+=2){
			cout<<cnt<<" "<<cnt<<" ";
			cnt++;
		}
		cout<<endl;
		return;
	}
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

