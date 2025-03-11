#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100010;

int tmp[N*2];
int a[N];
int b[N];
int bing[N*2];
int height[N*2];
int eq[N];

void init(){
	for(int i = 1; i <= 2*N; ++i)
	{
		bing[i] = i;
		height[i] = 0;
	}
}

int find(int x){
	return x==bing[x] ? x : find(bing[x]);
}

void merge(int x, int y){
	x = find(x);
	y = find(y);
	if(height[x] == height[y]){
		height[x]++;
		bing[y] = x;
	}
	else{
		if(height[x] < height[y])
		    bing[x] = y;
		else
		    bing[y] = x;
	}
}

int main()
{
    int t;
	cin >> t;
	int n;
	while(t--){
		scanf("%d", &n);
		bool flag = true;
	    for(int k = 1; k <= n; ++k){
	    	scanf("%d %d %d",&a[k], &b[k], &eq[k]);
	    	tmp[2*k-1] = a[k];
	    	tmp[2*k] = b[k];
		}
		sort(tmp+1, tmp+2*n+1);
		for(int k = 1; k <= n; ++k){
			a[k] = lower_bound(tmp + 1, tmp + n + 1, a[k]) - tmp;
			b[k] = lower_bound(tmp + 1, tmp + n + 1, b[k]) - tmp;
		}
		init();
		for(int k = 1; k <= n; ++k){
			if(eq[k]){
				merge(a[k], b[k]);
			}
		}
		for(int k = 1; k <= n; ++k){
			if(!eq[k]){
				if(find(a[k]) == find(b[k]))
				{
					flag = false;
				}
			}
		}
		if(flag)
		    cout<<"YES"<<endl;
		else
		    cout<<"NO"<<endl;
	} 
    return 0;
}

