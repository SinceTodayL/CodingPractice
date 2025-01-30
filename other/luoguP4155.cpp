#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 4e5 + 1;
int n, m, n2;
int go[N][20];

struct pos{
	int l, r;
	int number;
	bool operator < (const pos pos_tmp) const{
		return l < pos_tmp.l;
	}
}p[N*2];

void init(){
	int nxt = 1;
	for(int i = 1; i <= n2; ++i){
		while(nxt <= n2 && p[nxt].l <= p[i].r)
		    nxt++;
		go[i][0] = nxt - 1;
	}
	for(int i = 1; (1 << i) <= n; ++i)
		for(int k = 1; k <= n2; ++k)
		     go[k][i] = go[go[k][i-1]][i-1];
}

int res[N];

void getans(int x){
	int len = p[x].l + m;
	int cur = x;
	int ans = 1;
	for(int i = log2(N); i >= 0; --i){
		int pos = go[cur][i];
		if(pos && p[pos].r < len){
			ans += 1 << i;
			cur = pos;
		}
	}
	res[p[x].number] = ans + 1;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
    	p[i].number = i;
    	scanf("%d%d",&p[i].l, &p[i].r);
    	if(p[i].l>p[i].r)
    	    p[i].r+=m;
	}
	sort(p + 1, p + n + 1);
	n2 = n;
	for(int i = 1; i <= n; ++i){
		n2++;
		p[n2] = p[i];
		p[n2].l = p[i].l + m;
		p[n2].r = p[i].r + m;
	}
	init();
	for(int i = 1; i <= n; ++i)
		getans(i);
    for(int i = 1; i <= n; ++i)
        printf("%d ", res[i]);
    return 0;
}

