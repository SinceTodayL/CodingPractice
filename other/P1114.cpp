#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int l[200010];
#define N 100010

int main()
{
    int n;
    cin >> n;
    int tmp, num0 = 0, num1 = 0; 
    int ans = 0;
    l[N] = 0;
    for(int i = 1; i <= n; ++i){
    	scanf("%d", &tmp);
    	if(tmp)
    	    num1++;
    	else
    	    num0++;
    	if(num1 != num0 &&l[N + num1-num0] == 0)
    	    l[N + num1-num0] = i;
    	ans = max(ans, i-l[N + num1-num0]);
	}
    cout << ans;
    return 0;
}

