#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
char a[N],b[N];
int main()
{
	int cnt1,cnt2,t,len1,len2; bool ok;
	cin>>t;
	int i;
	while(t--){
		scanf("%s",a);
		scanf("%s",b);
		len1=strlen(a);
		len2=strlen(b);
		cnt2=0; ok=0;
		if(len1<len2){
			printf("No\n");
			continue;
		}
		for(i=0;i<len1;++i){
			if(a[i]==b[cnt2]){
				++cnt2;
				if(cnt2>=len2){
					ok=1;
					break;
				}
				continue;
			}
			if(a[i]=='?'){
				a[i]=b[cnt2];
				++cnt2;
				if(cnt2>=len2){
					ok=1;
					break;
				}
			}
		}
		for(i=0;i<len1;++i){
			if(a[i]=='?')
				a[i]='a';
		} 
		if(ok==0){
			printf("No\n");
		}
		else{
			printf("Yes\n%s\n",a);
		}
	}
    return 0;
}

