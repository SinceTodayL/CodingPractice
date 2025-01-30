#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int t;
double distance_1(double x1, double y1, double x2, double y2){
	return abs(x2-x1) + abs(y2-y1);
}
double cal_diag(double x, double y){
	return (x*x) + (y*y);
}


int main()
{
	scanf("%d", &t);
    double x11, x12, y11, y12, x21, x22, y21, y22;
    double mid_x1, mid_y1, mid_x2, mid_y2;
    while(t--){
    	scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &x11,&y11,&x12,&y12,&x21,&y21,&x22,&y22);
    	mid_x1 = (x11+x12)/2.0;
    	mid_y1 = (y11+y12)/2.0;
    	mid_x2 = (x21+x22)/2.0;
    	mid_y2 = (y21+y22)/2.0;
    	double diag_R2 = cal_diag(mid_x2-x22, mid_y2-y22);
    	double res = distance_1(mid_x1, mid_y1, mid_x2,mid_y2) - sqrt(2.0*diag_R2);
    	printf("%.10lf\n", res);
	}
	    
    return 0;
}

