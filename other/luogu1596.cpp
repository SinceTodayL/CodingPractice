#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int water[101][101];
int n, m; 
bool flag[101][101];
int ans = 0;

bool dfs(int i, int j){
	if(i <= 0 || i > n || j <= 0 || j > m)
	    return false;
	if(flag[i][j])
	    return false;
	flag[i][j] = true;
	if(!water[i][j])
	    return false;
	dfs(i - 1, j - 1);
	dfs(i - 1, j);
	dfs(i - 1, j + 1);
	dfs(i, j - 1);
	dfs(i, j + 1);
	dfs(i + 1, j - 1);
	dfs(i + 1, j);
	dfs(i + 1, j + 1);
	return true;
}

int main()
{
    scanf("%d %d", &n, &m);
    char tmp;
    for(int i = 1; i <= n; ++i){
        getchar();
        for(int j = 1; j <= m; ++j){
        	scanf("%c", &tmp);
        	if(tmp == 'W')
        	    water[i][j] = 1;
			else
			    water[i][j] = 0; 
		}
	}
		
    for(int i = 1; i <= n; ++i){
	    for(int j = 1; j <= m; ++j)
	        cout << water[i][j]<<' ';
	    cout << endl;
	}
    
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j){
        	if(dfs(i, j))
        	    ans++;
		}
	cout << ans;

	
    return 0;
}

