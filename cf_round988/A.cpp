#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int n, input;
	cin>>n;
	unordered_map<int, int> nums;
	for(int i=0; i<n; ++i){
		cin>>input;
		if(nums.find(input)!=nums.end())
		nums[input]+=1;
		else
		nums[input]=1;
	}
	int ans=0;
    for(auto ele:nums){
    	ans += ele.second/2;
	} 
	cout<<ans<<endl;
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

