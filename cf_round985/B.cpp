#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	int n;
	string a, b;
	cin>>t;
	while(t--){
		cin>>n;
		cin>>a>>b;
		int cnta1=0, cnta0=0, cntb1=0, cntb0=0;
		for(int i = 0; i < a.size(); ++i){
			if(a[i] == '1')
			    cnta1++;
			else
			    cnta0++; 
		}
		for(int i = 0; i < b.size() - 1; ++i){
			if(b[i] == '1')
			    cntb1++;
			else
			    cntb0++;
		}
		bool flag = true;
		if(cnta1 == 0 || cnta0 == 0){
			flag = false;
			cout<<"no"<<endl;
			continue; 
		}
		if(cnta0==cntb1+1 && cnta1==cntb0+1)
		    flag = true;
		else{
		    flag = false;
			cout<<"no"<<endl;
			continue;
		}
		if(flag)
		cout<<"yes"<<endl;
	}
    return 0;
}

