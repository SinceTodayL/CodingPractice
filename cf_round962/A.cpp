#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin>>t;
    while(t--){
    	int num;
    	cin>>num;
    	if(num%4==0)
    	    cout<<num/4<<endl;
    	else
    	    cout<<num/4+1<<endl;
	} 
    return 0;
}

