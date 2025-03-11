#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int h[100010];

int main()
{
	int n;
    scanf("%d", &n); 
    for(int i = 1; i <= n; ++i)
        scanf("%d", &h[i]);
    stack<int> tmp;
    for(int i = 1; i <= n; ++i){
    	if(tmp.empty()){
    		tmp.push(i);
    		continue;
		}
		if(!tmp.empty() && h[i] > h[tmp.top()]){
			while(!tmp.empty() && h[i] > h[tmp.top()]){
				h[tmp.top()] = i;
				tmp.pop();
			}
			tmp.push(i);
		}
		else{
			tmp.push(i);
	}
	}
	while(!tmp.empty()){
			h[tmp.top()] = 0;
			tmp.pop();
		}
	for(int i = 1; i <= n; ++i)
    	    printf("%d\n", h[i]);
    return 0;
}

