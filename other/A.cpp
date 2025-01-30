#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin>>t;
    int n, a, b;
    while(t--){
    	cin>>n>>a>>b;
    	if(b>=2*a){
    		cout<<n*a<<endl;
		}
		else{
			if(n&1){
				cout<<(n/2)*b + a<<endl;
			}
			else{
				cout<<(n/2)*b<<endl;
			}
		}
	}
    return 0;
}

