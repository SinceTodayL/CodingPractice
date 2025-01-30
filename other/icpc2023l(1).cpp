#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int t;

long double cal_diag(double x, double y){
	return (x*x) + (y*y);
}

int main()
{
	scanf("%d", &t);
    long double x11, x12, y11, y12, x21, x22, y21, y22;
    long double mid_x1, mid_y1, mid_x2, mid_y2;
    long double cs_x;
    long double diag;
    long double k;
    
    while(t--){
    	scanf("%Lf%Lf%Lf%Lf%Lf%Lf%Lf%Lf", &x11,&y11,&x12,&y12,&x21,&y21,&x22,&y22);
    	mid_x1 = (x11+x12)/2.0;
    	mid_y1 = (y11+y12)/2.0;
    	mid_x2 = (x21+x22)/2.0;
    	mid_y2 = (y21+y22)/2.0;
    	k = (mid_y2-mid_y1)/(mid_x2-mid_x1);
    	long double diag_R2 = cal_diag(mid_x2-x22, mid_y2-y22);
    	
    	long double l = mid_x1;
    	long double r = mid_x2;
    	while(abs(l - r) >= 1e-15){
    	    long double mid = (l + r) / 2.0;
    		cout << mid << endl;
    		long double tmp = cal_diag(mid_x2 - mid, ((mid_y2-mid_y1)/(mid_x2-mid_x1))*(mid_x2 - mid));
    		if(diag_R2 > tmp)
    		    r = mid;
    		else
    		    l = mid;
		}
		long double x3 = r;
	    long double y3 = mid_y1 + ((x3 - mid_x1)*(mid_y2-mid_y1))/(mid_x2 - mid_x1);
    	
    	cout << x3 << ' '<< y3 << endl;
    	
		long double res = abs(x3 - mid_x1) + abs(y3 - mid_y1);
    	printf("%.10Lf",res);
		}
	    
    return 0;
}

