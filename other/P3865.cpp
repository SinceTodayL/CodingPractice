#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
vector<int> num; 


int main()
{
    cin >> n >> m;
    num.resize(n + 1);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &num[i]);
    
    int LOG2N = log2(n) + 1;
    vector<vector<int>> st(n + 1, vector<int> (LOG2N, 0));
    for(int i = 1; i <= n; ++i)
        st[i][0] = num[i];
    for(int j = 1; j < LOG2N; ++j)
        for(int i = 1; i <= n && i + (1 << j) - 1 <= n; ++i){
        	st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
		}	
	
	int sa, ed, ans;
    while(m--){
    	scanf("%d %d", &sa, &ed);
    	int length = ed - sa + 1;
    	int tmp = log2(length);
    	ans = max(st[sa][tmp], st[ed - (1 << tmp) + 1][tmp]);
    	printf("%d\n", ans);
	}
    return 0;
}

