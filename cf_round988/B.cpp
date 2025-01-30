#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int k, input;
	cin>>k;
	map<int, int> nums;
	for(int i=0; i<k; ++i){
		cin>>input;
		nums[input]++;
	}
	int nm = k-2;
	int n=1, m=1;
	
	for(n=1; n-sqrt(nm)<1e-6; ++n){
		if(nm%n)
   			continue;
   		else if(fabs(n-sqrt(nm))<1e-6){
   			if(nums.find(n) != nums.end() && nums[n]>=2){
   				m=n;
   				break;
			   }
		   }
   		else{
   			if(nums.find(n) == nums.end())
   				continue;
   			m=nm/n;
   			if(nums.find(m)!=nums.end()){
   				break;
			   }
		}
	}
	cout<<n<<" "<<m<<endl;
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

