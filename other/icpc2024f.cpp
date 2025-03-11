#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node{
	int val;
	ll times;
}a[200010];
ll ans = 0;
int n;

int main()
{
    int t;
    scanf("%d", &t);
    stack<node> tmp;
    while(t--){
    	while(!tmp.empty())
    	    tmp.pop();
    	ans = 0;
    	scanf("%d", &n);
    	for(int i = 1; i <= n; ++i){
    	    scanf("%d", &a[i].val);
    	    a[i].times = 0;
    	}
    	for(int i = 1; i <= n; ++i){
    		if(tmp.empty()){
    			tmp.push(a[i]);
    			continue;
			}
			if(a[i].val < tmp.top().val)
				tmp.push(a[i]);
			else if(a[i].val > tmp.top().val){
				ll t = 0;
				while(!tmp.empty() && (a[i].val > tmp.top().val)){
					t += tmp.top().times;
					t += 1;
			        ans += t; 
			        tmp.pop();
				}
				if(!tmp.empty() && a[i].val == tmp.top().val)
				    tmp.top().times += (1 + t);
				else{
			     	a[i].times = t;
			    	tmp.push(a[i]);
			    }
			}
			else{
				tmp.top().times += 1;
			}
		}
		ll tmpVal = 0;
		while(tmp.size() > 1){
			tmp.top().times += 1;
			tmpVal += tmp.top().times;
			ans += tmpVal;
			tmp.pop();
		}
		printf("%lld\n", ans);
	}
    return 0;
}

