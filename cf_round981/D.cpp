#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int m[100010];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n, tmp;
		cin>>n;
		for(int i=1; i<=n; ++i){
			cin>>tmp;
			m[i]=m[i-1]+tmp;
		}
		unordered_set<int> rec;
		rec.insert(0);
		int ans=0;
		for(int i=1; i<=n; ++i){
			if(rec.find(m[i]) != rec.end()){
				ans++;
				rec.clear();
				rec.insert(m[i]);
				continue;
			}
			rec.insert(m[i]);
		}
		cout<<ans<<endl;
	}
    return 0;
}

