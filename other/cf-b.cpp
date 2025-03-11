#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int find(char* tmp){
	for(int i = 0; i < 4; ++i){
		if(tmp[i] == '#')
		    return i + 1;
	}
}

int main()
{
    int t, n;
    cin >> t;
    int ans[510];
    while(t--){
    	cin >> n;
    	for(int i = 1; i <= n; ++i){
    		char tmp[4];
    		getchar();
    		for(int j = 0; j < 4; ++j)
    		    scanf("%c", &tmp[j]);
    		ans[i] = find(tmp);
		} 
	for(int i = n; i >=1; i--)
	    printf("%d ",ans[i]);	
    printf("\n");
	}
    return 0;
}

