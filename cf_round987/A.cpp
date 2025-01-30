#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int n;
	cin >> n;
	vector<int> nums(n, 0);
	for(int i = 0; i < n; ++i)
	    cin>>nums[i];
	int times = 1;
	int ans = 1;
	for(int i = 0; i < n - 1; ++i){
		 while(i < n - 1 && nums[i] == nums[i + 1]){
		 	times++;
		 	i++;
		 }
		 ans = max(ans, times);
		 times = 1;
	}
	cout << n - ans <<endl;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
    return 0;
}

