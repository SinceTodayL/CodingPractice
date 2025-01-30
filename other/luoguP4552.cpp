#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, sum = 0;
ll pos = 0, neg = 0;
int a[100010];
int b[100010];
int c[100010];

int main()
{
    scanf("%lld", &n);
    int m = 1;
    for(int i = 1; i <= n; ++i){
    	scanf("%d", &c[i]);
	}
	a[1] = c[1];
	for(int i = 2; i <= n; ++i){
		if(a[i] != a[i - 1]){
			a[++m] = c[i];
		}
	}
	b[1] = a[1];
	for(int i = 2; i <= m; ++i){
		b[i] = a[i] - a[i-1];
		sum += b[i];
		if(b[i] > 0)
		    pos += b[i];
		if(b[i] < 0)
		    neg += (-b[i]);
	}
	ll res1 = max(pos, neg);
	ll res2 = abs(sum) + 1;
	cout << res1 << endl <<  res2;
    return 0;
}

