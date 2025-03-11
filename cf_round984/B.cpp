#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n, k, tmp1, tmp2;
		cin>>n>>k;
		map<int, int> rec;
		for(int i = 0; i<k; ++i){
			cin>>tmp1>>tmp2;
			rec[tmp1]+=tmp2;
		}
		vector<int> cnt;
		for(auto pair:rec){
			cnt.push_back(pair.second);
		}
		sort(cnt.begin(), cnt.end(), greater<int>());
		ll res = 0;
		for(int i = 0; i<min(n, static_cast<int>(cnt.size())); ++i){
			res += cnt[i];
		}
		cout<<res<<endl;
	}
    return 0;
}

