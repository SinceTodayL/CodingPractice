#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[200010];

unordered_map<int, int> at;
unordered_map<int, int> bt;

int main()
{
    int t, n, m, k, tmp;
    scanf("%d", &t);
    while(t--){
    	bt.clear();
    	at.clear();
    	int ans=0, cur=0;
    	scanf("%d%d%d", &n, &m, &k);
    	for(int i=1; i<=n; ++i){
    		scanf("%d", &a[i]);
		}
		for(int i=1; i<=m; ++i){
			scanf("%d", &tmp);
		    bt[tmp]++;
		    at[tmp]++; 
		}
		
		for(int i=1; i<=m; ++i){
			if(bt.find(a[i])!=bt.end() )
			{
				if(bt[a[i]]>0)
				{
			   	cur++;
			   	bt[a[i]]--;
			   }
			   at[a[i]]--;
			}

		}
		if(cur>=k)
		    ans++;
		int bp=2,  fp=m+1;
		
		while(fp<=n){
			if(bt.find(a[bp-1])!=bt.end()){
				at[a[bp-1]]++;
				if(at[a[bp-1]]>0){
				    bt[a[bp-1]]++;
				    cur--;
		    	}
			}
			
			if(bt.find(a[fp])!=bt.end() )
			{
				if(bt[a[fp]]>0)
				{
			   	cur++;
			   	bt[a[fp]]--;
			   }
			   at[a[fp]]--;
			}
			bp++;
			fp++;
			if(cur>=k)
			    ans++;
		} 
		
		printf("%d\n", ans);
	}
    return 0;
}

