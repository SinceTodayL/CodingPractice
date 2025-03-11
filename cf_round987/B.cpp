#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int n;
    cin>>n;
    vector<int> nums(n+1);
    for(int i=1; i<=n; ++i)
        cin>>nums[i];
    bool flag = true;
    for(int i=1; i<n; ++i){
    	if(nums[i] != i){
    		if(nums[i]==i+1 && nums[i+1]==i){
    			i+=1;
    			continue;
			}
			else{
				flag = false;
				break;
			}
		}
	}
	if(flag)
	    cout<<"yes"<<endl;
	else
	    cout<<"no"<<endl;
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

