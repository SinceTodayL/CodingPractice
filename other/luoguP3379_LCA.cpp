#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, q, root;
const int N = 500010;

struct Edge{
	int to;
	int next;
}edge[2*N]; 
int head[2*N];
int cnt;   // 用链式向前星存储图

void init(){
	for(int i = 0; i < 2*N; ++i){
		edge[i].next = -1;
		head[i] = -1;
		cnt = 0;
	}
} 

void add_edge(int u, int v){
	edge[cnt].to = v;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}// 要理解链式向前星的操作 

int fa[N][20];
int deep[N];

void dfs(int x, int father){
	deep[x] = deep[father] + 1;
	fa[x][0] = father;
	
	for(int i = 1; (1 << i) <= deep[x]; ++i){
		fa[x][i] = fa[fa[x][i-1]][i-1];
	}
	
	for(int i = head[x]; i != -1; i = edge[i].next){
		if(edge[i].to != father){
			dfs(edge[i].to, x);
		}
	}
}

int LCA(int x, int y){
	if(deep[x] < deep[y]){
		swap(x, y);
	}
	for(int i = 19; i >= 0; --i){
		if(deep[x] - (1 << i) >= deep[y]){
			x = fa[x][i];
		}
	}
	
	if(x == y){
		return x;
	}
	
	for(int i = 19; i >= 0; --i){
		if(fa[x][i] != fa[y][i]){
			x = fa[x][i];
			y = fa[y][i];
		}
	}
	return fa[x][0];
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q >> root;
	init();
	
	for(int i = 1; i <= n - 1; ++i){
		int u, v;
		cin >> u >> v;
		add_edge(u, v);
		add_edge(v, u);
	}
	dfs(root, 0);
	while(q--){
		int a, b;
		cin >> a >> b;
		cout << LCA(a, b) << endl;
	}
    return 0;
}

