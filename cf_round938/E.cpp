#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string str;
int n;
int flip[5010];

bool check(int x){
	memset(flip, 0, (n+1)*sizeof(int));
	int cnt=0; 
	bool valid=true;
	for(int i=0; i+x<=n; ++i){
		cnt+=flip[i];
		if((!(cnt&1))&&str[i]=='0' || (cnt&1)&&str[i]=='1'){
            cnt++;
			flip[i+x]--;
		}
	}
	for(int i=n-x+1; i<=n-1; ++i){
		cnt+=flip[i];
		if((!(cnt&1))&&str[i]=='0' || (cnt&1)&&str[i]=='1'){
            valid=false;
            break;
		}
	}
	return valid;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        cin>>n>>str;
    	int i;
    	for(i=n; i>=1; --i){
    		if(check(i))
    		    break;
		}
		printf("%d\n", i);
	}
    return 0;
}

