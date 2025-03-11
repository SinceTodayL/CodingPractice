#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int n;
	cin>>n;
	vector<int> nums(n+1, 0);
	vector<int> max_num(n+1, 0);
	int max_ele = 0;
	for(int i=1; i<=n; ++i){
	    cin>>nums[i];
	    max_ele = max(max_ele, nums[i]);
	    max_num[i]=max_ele;
    }
    vector<int> res(n+1, 0);
    res[n] = max_ele;
	int min_ele = nums[n];
	for(int i= n - 1; i>=1; --i){
		min_ele = min(min_ele, nums[i+1]);
		if(max_num[i]>min_ele){
			res[i]=res[i+1];
		}
		else{
			res[i]=max_num[i];
		}
	}
	for(int i=1; i<=n; ++i)
		cout<<res[i]<<" ";
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

