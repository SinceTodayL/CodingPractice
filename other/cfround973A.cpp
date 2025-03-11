#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t, n, x, y, z, ans;
	cin >> t;
	while(t--){
		scanf("%d %d %d", &n, &x, &y);
		z = min(x, y);
		ans =( n % z == 0 )? n/z: n/z + 1;
		printf("%d\n", ans);
	} 
    return 0;
}

