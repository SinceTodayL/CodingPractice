#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t, n;
	string a;
	cin >> t;
	while(t--){
		cin >> n;
		cin >> a;
		int flag = 0;
		bool f = true;
		for(int i = 1; i < n-1; ++i){
			if(a[i] == 's'){
				if(flag == 2){
				    f = false;
			    	break;
			    }
			    flag = 1;
			}
			else if(a[i] == 'p'){
				if(flag == 1){
				    f = false;
					break; 
				}
				flag = 2;
			}
		}
		if(flag == 1 && a[0] == 'p')
		f = false;
		if(flag == 2 && a[n-1] == 's')
		f = false;
		if(a[0] == 'p' && a[n-1] == 's')
		f = false;
		if(f)
		cout << "yes" << endl;
		else
		cout << "no" << endl;
	}
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
char s[505];
int main(){
	int n,t,sr,pl,snum,pnum;
	cin>>t;
	while(t--){
		cin>>n;
		scanf("%s",s);
		snum=0;
		pnum=0;
		sr = -1; pl = 1000;
		for(int i=0;i<n;++i){
			if(s[i]=='p'){
				pnum++;
				pl = min(pl,i); 
			}
			else if(s[i]=='s'){
				snum++;
				sr = max(sr,i); 
			}
		}
		if(sr>pl){
			printf("No\n");
		}
		else{
			if(pnum>=2&&snum>=2){
				printf("No\n");
			}
			else{
				if(pnum==0||snum==0){
					printf("Yes\n");
				}
				else{
					if(pnum==1){
						if(pl==n-1)
							printf("Yes\n");
						else if(snum>=2||(sr!=0)){
							printf("No\n");
						}
						else
							printf("Yes\n");
					}
					else{
						if(sr==0)
							printf("Yes\n");
						else if(pnum>=2||(pl!=n-1)){
							printf("No\n");
						}
						else
							printf("Yes\n");
					}
				}
			}
		}
	}
	return 0;
}*/
