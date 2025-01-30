#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n, tmp;
		cin>>n;
		int cnt = 0;
		for(int i=0; i<2*n; ++i){
			cin>>tmp;
			if(tmp)
			    cnt++;
		}
		int max_, min_;
		if(cnt&1)
		    min_ = 1;
		else
		    min_ = 0;
		max_ = n-abs(n-cnt);
		cout<<min_<<" "<<max_<<endl;
	}
    return 0;
}

