#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[25];
int n;

int check(int x){
	int pos_0 = 1000, pos_1 = 1000;
	for(int i = 1; i <= x; ++i){
		if(!a[i])
		    pos_0 = i;
	}
	for(int i = 1; i <= x; ++i)
	    if(a[i] == 1)
	        pos_1 = i;
	
	if(pos_0 == 1)
	    return 2;
	if(pos_0 <= a[1] || pos_1 <= a[1])
	    return 1;
	int tmp = min(pos_0, pos_1);
	int ans = 0;
	for(int i = 1; i < tmp && i <= x; ++i){
		if(a[i] < tmp)
		    ans++;
	}
	if(ans & 1)
	    return 1;
	else
	    return 2;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
    	scanf("%d", &n);
    	for(int i = 1; i <= n; ++i)
    	    scanf("%d", &a[i]);
        if(check(n) == 1)
            printf("Alice\n");
        else
            printf("Bob\n"); 
	}
    return 0;
}

