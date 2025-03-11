#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
    	int n, k;
    	scanf("%d %d", &n, &k);
    	int tmp = max(1, n - k + 1);
    	tmp = n - tmp + 1;
    	if( (n&1)&&((tmp%4==0 || tmp%4==3)) || !(n&1)&&(tmp%4==0||tmp%4==1) ){
    	    cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
    return 0;
}

