#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int t, n;
int a[110];

int main()
{
    cin>>t;
    while(t--){
    	cin>>n;
    	for(int i=1; i<=n; ++i)
    	    cin>>a[i];
    	int num=(n+1)/2;
        int max_ele=0;
    	bool flag=false;
    	for(int i=1; i<=n; ++i){
    		if(a[i]>max_ele)
    		{
			    max_ele=a[i];
    		}
		} 
		for(int i=1; i<=n; ++i){
			if(a[i]==max_ele){
				if(i&1)
				    flag=true;
			}
		}
		
    	if(flag){
    	    cout<<num+max_ele<<endl;
		}
		else{
			if(n&1){
				cout<<num-1+max_ele<<endl;
			}
			else{
				cout<<num+max_ele<<endl;
			}
		}
		
	}
    return 0;
}

