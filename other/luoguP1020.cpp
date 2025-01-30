#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[100010];
int dc[100010];
int m[100010];

int main()
{
    int tmp;
    int all=0;
    int ans=0;
    int Ans=0;
    int sum=0;
    dc[0]=INT_MAX;
    while(cin>>tmp){
    	a[++all]=tmp;
	}
    for(int i=1; i<=all; ++i){
		
		if(a[i]<=dc[ans]){
			dc[++ans]=a[i];
			continue;
		}
		if(a[i]>dc[1]){
			dc[1]=a[i];
			continue;
		}
		int l=1, r=ans, mid;
		while(l<r){
			mid=(l+r)/2;
			if(dc[mid]<a[i])
			    r=mid;
			else
			    l=mid+1;
		}
		if(dc[l]==a[i])
		    l++;
		dc[l]=a[i];
	}
    
    m[1]=a[1];
    Ans=1;
    for(int i=2; i<=all; ++i){
    	if(a[i]>m[Ans]){
    		m[++Ans]=a[i];
    		continue;
		}
		int l=1; 
		int r=Ans;
		int mid;
		while(l<r){
			mid=(l+r)/2;
			if(m[mid]>=a[i])
			    r=mid;
			else
			    l=mid+1;
		}
		if(m[l]==a[i])
		   continue;
		m[l]=a[i];
	}
    cout<<ans<<endl<<Ans;
    return 0;
}

