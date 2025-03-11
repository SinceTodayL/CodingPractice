#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[60];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		bool flag = true;
		for(int i =0; i<n; ++i){
			cin>>a[i];
			if(i >= 1 && abs(a[i]-a[i-1]) != 5 && abs(a[i]-a[i-1]) != 7)
			flag = false;
		}
		if(flag)
		cout<<"yes"<<endl;
		else
		cout<<"no"<<endl;
		
	}
    return 0;
}

