#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    int tmp;
    int n, k;
    int have = 0, cnt = 0;
    cin >> t;
    while(t--){
    	cnt = 0;
    	have =0;
    	scanf("%d %d", &n, &k);
    	for(int i = 1; i <= n; ++i){
    		scanf("%d", &tmp);
    		if(tmp >= k){
    			have += tmp;
			}
			else if(tmp == 0 && have != 0){
				cnt++;
				have--;
			}
		}
		printf("%d\n",cnt);
	}
    return 0;
}

