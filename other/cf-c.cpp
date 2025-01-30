#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    int x, y, k, ans;
    while(t--){
    	scanf("%d %d %d", &x, &y ,&k);
    		int a1 = (x + k - 1)/k;
    		int a2 = (y + k - 1)/k;
    	if(a1 <= a2){
    		ans = 2 * a2;
		}
		else{
			ans = 2 * a1 - 1;
		}
		printf("%d\n",ans);
	}
    return 0;
}

