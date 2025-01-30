#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, ans = 0;
struct node{
	int x, y, t;
	bool operator < (const node& other) const{
		return t < other.t;
	}
}cun[1010];
int bing[1010];

void init(){
	for(int i=1;i<=n;++i)
	    bing[i] = i;
}

int find(int x){
	if(bing[x] != x)
	    bing[x] = find(bing[x]);
	return bing[x];
}

void merge(int x, int y){
	x = find(x);
	y = find(y);
	bing[x] = y;
}

int main(){
	cin >> n >> m;
	init();
	for(int i = 1; i <= m; ++i){
		scanf("%d%d%d", &cun[i].x, &cun[i].y, &cun[i].t);
	} 
	sort(cun + 1, cun + m + 1);
	int cnt = 0;
	for(int i = 1; i <= m; ++i){
		if(find(cun[i].x) == find(cun[i].y))
		    continue;
		else{
			merge(cun[i].x, cun[i].y);
			ans = max(ans, cun[i].t);
		}
	}
	for(int i =1; i <=n; ++i){
		if(bing[i] == i)
		    cnt++;
	}
	if(cnt==1)
	    cout<<ans;
	else
	   cout<<"-1";

    return 0;
}

