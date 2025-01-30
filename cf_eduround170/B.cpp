#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin>>t;
	string a, b;
	while(t--){
		cin>>a>>b;
		int cnt=0;
		for(int i=0; i<a.size()&&i<b.size(); ++i){
			if(a[i]==b[i])
			    cnt++;
			else
			    break;
		}
		if(cnt==0)
		    cout<<a.size()+b.size()<<endl;
		else
		    cout<<a.size()+b.size()-cnt+1<<endl;
		}
    return 0;
}

