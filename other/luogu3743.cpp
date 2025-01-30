#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define max_num 1e8

double n, p, sum_a;
double a[100010];
double b[100010];

bool check(double x){
	double all = 0;
	for(int i = 1; i <= n; ++i){
		if(b[i] - x*a[i] < 0)
		    all += -(b[i] - x*a[i]);
	}
	if(all - x*p > 1e-6)
	    return false;
	else
	    return true;
} 

int main()
{
    scanf("%lf %lf", &n, &p);
    for(int i = 1; i <= n; ++i){
    	scanf("%lf", &a[i]);
    	scanf("%lf", &b[i]);
    	sum_a += a[i];
	}
	if(sum_a <= p){
		cout<<"-1";
		return 0;
	}
	double l = 0;
	double r = max_num;
	while(r - l > 1e-6){
		double mid = (l + r) / 2;
		bool tmp = check(mid);
		if(tmp)
		    l = mid;
		else
		    r = mid;
	}
	cout << fixed << l;
    return 0;
}

