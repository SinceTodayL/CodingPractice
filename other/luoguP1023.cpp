#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1000010;
int expect, cb, delta;
double num[N];

int main()
{
    scanf("%d", &expect);
    int tmp1, tmp2, cnt=0;
    while(1){
    	scanf("%d%d",&tmp1, &tmp2);
    	if(tmp1==-1 && tmp2==-1) break;
    	if(cnt==0) {
		    cb=tmp1;
		    num[0]=tmp2;
		    cnt++;
		    continue;
		}
		int dd = (num[cnt-1]-tmp2)/(tmp1-cb-(cnt-1));
    	for(int i=cnt; i<=tmp1-cb; ++i){
    		num[i]=num[i-1]-dd;
		}
		cnt=tmp1-cb+1;
	}
	scanf("%d", &delta);
	while(1){
		num[cnt]=num[cnt-1]-delta;
		if(num[cnt]<0) break;
		cnt++;
	}
	expect -= cb;
	double l = INT_MIN, r = INT_MAX;
	for(int i=0; i<expect; ++i){
		double tmp = num[expect]*expect - num[i]*i;
		r = min(r, tmp/(num[i]-num[expect]));
	}
	for(int i=expect+1; i<cnt; ++i){
		double tmp = num[i]*i - num[expect]*expect;
		l = max(l, tmp/(num[expect]-num[i]));
	}
	double ans;
	if(fabs(l)>fabs(r)){
		ans = r;
	}
	else 
	    ans = l;
	if(ans>=0)
	    cout<<ceil(ans);
	else
	    cout<<floor(ans);
    return 0;
}

