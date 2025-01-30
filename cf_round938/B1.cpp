#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, c, d, tmp, min_ele=INT_MAX; 
int a[250010];
int my[250010];

int main()
{
	int t;
	scanf("%d", &t);
    while(t--){
        scanf("%d%d%d", &n, &c, &d);
        for(int i=1; i<=n*n; ++i){
        	scanf("%d", &tmp);
        	a[i]=tmp;
		}
		sort(a+1, a+n*n+1);
		min_ele=a[1];
		int num=1;
		for(int i=1; i<=n; ++i){
			int st=min_ele+(i-1)*c;
			for(int j=1; j<=n; ++j){
				my[num++]=st+(j-1)*d;
			}
		}
		sort(my+1, my+n*n+1);
		bool flag=true;
		for(int i=1; i<=n*n; ++i){
			if(a[i]!=my[i])
			    flag=false;
		}
		
		if(flag)
		    cout<<"yes"<<endl;
		else
		    cout<<"no"<<endl;
	}
    
    return 0;
}

