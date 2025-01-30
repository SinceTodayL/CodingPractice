#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int n, i1, i2;
	cin>>n;
	string s(n+1, '0');
	vector<int> nums(n+1, 0);
	int index = 0;
	for(int i=2; i<=n; ++i){
		cout<<"? 1 "<<i<<endl;
		cin>>i1;
		nums[i]=i1;
		if(i1!=0 && index == 0)
		index = i;
	}
	if(index == 0){
		cout<<"! IMPOSSIBLE"<<endl;
		return;
	}
	
    for(int i=1; i<=index - 1 - nums[index]; ++i)
		s[i]='1';
	for(int i=index-nums[index]; i<index; ++i)
	    s[i]='0';
	for(int i=index;i<=n; ++i){
		if(nums[i]>nums[i-1]){
			s[i]='1';
		}
		else
			s[i]='0';
	}	 
	cout<<"! "<<s.substr(1)<<endl;

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

