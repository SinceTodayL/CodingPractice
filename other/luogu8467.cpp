#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
int l[100010];
int c[100010];

bool judge(int x){
	int all=0;
	for(int i=1; i<=n; ++i){
		all+=(l[i]/x)*(c[i]/x);
	}
	if(all<k)
	    return false;
	else
	    return true;
} 

int main()
{
    scanf("%d%d", &n,&k);
    for(int i=1; i<=n; ++i){
    	scanf("%d%d", &l[i], &c[i]);
	}
	int left=1, right=100010, mid;
	while(left < right){
		mid=(left+right+1)/2;
		if(!judge(mid))
		    right = mid-1;
		else
		    left = mid;
	}
	cout<<left;
    return 0;
}

