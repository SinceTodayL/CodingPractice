#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int t;
int n;
int a[10010];
int b[10010];
double c[10010];
double d[10010];

int main()
{
    scanf("%d", &t);
    while(t--){
    	scanf("%d", &n);
    	for(int i = 1; i <= n; ++i){
    	    scanf("%d %d %lf", &a[i], &b[i], &c[i]);
			d[i] = a[i]*(1 - c[i]) + (a[i] + b[i])*c[i];
		}
    	sort(d + 1, d + n + 1);
    	
        double tmp = 0;
        double res = 0;
        for(int i = 1; i <= n; ++i){
        	tmp += d[i];
        	res += tmp;
		}
		printf("%lf\n", res); 
	} 
    return 0;
}

