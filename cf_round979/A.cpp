#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int arr[1010];
int n;
int max_num, min_num;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		max_num = 0; min_num = INT_MAX;
		for(int i=0; i<n; ++i){
			cin>>arr[i];
			max_num = max(max_num, arr[i]);
			min_num = min(min_num, arr[i]);
		}
		cout<<(n-1)*(max_num-min_num)<<endl;
	} 
    return 0;
}

