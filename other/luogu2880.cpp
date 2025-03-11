#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, q, h[50010]; 
int dp_min[50010][20];
int dp_max[50010][20];

int Find(int a, int b){
	int k = log2(b - a + 1);
	int tmp_min = min(dp_min[a][k], dp_min[b-(1<<k)+1][k]);
	int tmp_max = max(dp_max[a][k], dp_max[b-(1<<k)+1][k]);
	return tmp_max - tmp_min;
}

int main()
{
    cin >> n >> q;
    for(int i = 1; i <= n; ++i)
        scanf("%d", &h[i]);
    
    for(int i = 1; i <= n; ++i){
    	dp_min[i][0] = h[i];
    	dp_max[i][0] = h[i];
	}
        
    for(int j = 1; 1 << j <= n; ++j)
        for(int i = 1; i <= n && i + (1 << j) - 1 <= n; ++i)
       {
       	    dp_min[i][j] = min(dp_min[i][j-1], dp_min[i+(1<<(j-1))][j-1]);
       	    dp_max[i][j] = max(dp_max[i][j-1], dp_max[i+(1<<(j-1))][j-1]);
       }
    
    int a, b;
    while(q--){
    	scanf("%d %d",&a, &b);
    	printf("%d\n", Find(a, b));
	}

    return 0;
}

