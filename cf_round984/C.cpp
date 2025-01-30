#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		string a;
		cin>>a;
		int q;
		cin>>q;
		int len = a.size();
		
		vector<int> rec(len-3, 0);
		int cnt = 0;
		for(int i=0; i<len-3; ++i){
			if(a.substr(i, 4) == "1100"){
			    rec[i] = 1;
			    cnt++;
			}
		}
		int m, kk;
		while(q--){
			cin>>m>>kk;
			char k = (kk == 1)?'1':'0';
			if(len<4){
				cout<<"no"<<endl;
				continue;
			}
			if(a[m-1] == k)
			{
				cout<<(cnt == 0?"no":"yes")<<endl;
				continue;
			}
			a[m-1]=k;
			if(m<=len-3&&rec[m-1]){
				rec[m-1]= 0;
				cnt--;
			}
			else if(m<=len-2&&m>=2&&rec[m-2]){
				rec[m-2]=0;
				cnt--;
			}
			else if(m<=len-1&&m>=3&&rec[m-3]){
				rec[m-3] = 0;
				cnt--;
			}
			else if(m<=len&&m>=4&& rec[m-4]){
				rec[m-4] = 0;
				cnt--;
			}
			if(m>=4 && a.substr(m-4, 4)=="1100"){
				rec[m-4]=1;
				cnt++;
			}
			else if(m>=3 && m<=len-1 &&a.substr(m-3, 4)=="1100"){
				rec[m-3]=1;
				cnt++;
			}
			else if(m>=2 && m <= len-2 && a.substr(m-2, 4)=="1100"){
				rec[m-2]=1;
				cnt++;
			}
			else if(m>=1 && m<=len-3 && a.substr(m-1, 4)=="1100"){
				rec[m-1]=1;
				cnt++;
			}
			cout<<(cnt == 0?"no":"yes")<<endl;

		}
	} 
    return 0;
}

