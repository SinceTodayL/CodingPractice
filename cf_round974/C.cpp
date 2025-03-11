#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t, object, n;
    double lt = 0, aver, sum = 0;
    int a[200010];
    scanf("%d", &t);
    while(t--){
    	scanf("%d", &n);
    	sum = 0, aver = 0;
    	for(int i = 1; i <= n; ++i){
    		scanf("%d", &a[i]);
    		sum += a[i];
		}
		if(n == 1 || n == 2){
    		printf("-1\n");
    		continue;
		}
		aver = sum/(n);
		sort(a + 1, a + n + 1);
		object = a[n/2 + 1];
		lt = (2*object - aver) * n;
		if(lt <= -1e-6){
			cout<<"0"<<endl;
			continue;
		}
		else{
			int ft = lt- static_cast<int>(lt) < 1e-6? (int)lt : (int)lt+1;
			aver = (sum+ft)/(n);
			if(aver/2 - object > 1e-6)
			    cout << ft << endl;
			else 
			    cout << ft + 1 <<endl;
		}
	}
    return 0;
}

