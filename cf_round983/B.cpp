#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		if(n==1){
			cout<<"1"<<endl<<"1"<<endl;
			continue;
		}
		if(k == n || k == 1){
			cout<<"-1"<<endl;
			continue;
		}
		cout<<"3"<<endl;
		if(k >= (n+1)/2)
		cout<<"1 "<<2*k+1-n<<" "<<n<<endl;
		else
		cout<<"1 2 "<<2*k-1<<endl;
	} 
	
    return 0;
}

