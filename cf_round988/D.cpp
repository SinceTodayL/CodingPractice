#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int n, m, L, i1, i2;
	cin>>n>>m>>L;
	bool flag = true;
	vector<pair<int, int>> a;
	for(int i=1; i<=n; ++i){
		cin>>i1>>i2;
		a.push_back({i1-1, i2-i1+2});
	}
	vector<pair<int ,int>> b;
	for(int i=1; i<=m; ++i){
		cin>>i1>>i2;
		b.push_back({i1, i2});
	}
	priority_queue<int, vector<int>, less<int>> c;
	
	int index =0;
	int ans = 0;
	int value = 1;
	
	for(int i=0; i<n; ++i){
		while(index<m && b[index].first<=a[i].first){
			c.push(b[index++].second);
		}
		while(value<a[i].second && !c.empty()){
			value+=c.top();
			ans++;
			c.pop();
		}
		if(value<a[i].second){
			cout<<"-1"<<endl;
			return;
		}
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

