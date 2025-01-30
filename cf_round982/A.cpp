#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int num;
		cin>>num;
		int maxa = 0, maxb = 0;
		int a, b;
		for(int i=0; i<num; ++i){
			cin>>a>>b;
			maxa = max(maxa, a);
			maxb = max(maxb, b);
		}
		cout<<2*(maxa+maxb)<<endl;
	}
    return 0;
}

