#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t, n, num = 0;
	cin>>t;
	while(t--){
		string a;
		cin>>n>>a;
	    for(int i=1; i<n; ++i){
	    	if(i&1){
	    		if(a[i]=='1'||a[i-1]=='1'){
	    			a[i]=='1';
				}
			}
			else{
				if(a[i]=='0'||a[i-1]=='0'){
					a[i]=='0';
				}
			}
		}
		for(char ele:a){
			cout<<(int)ele<<" ";
		}
		cout<<endl;
		if(a[n-1]=='1')
		cout<<"yes"<<endl;
		else
		cout<<"no"<<endl;
	}
    return 0;
}

