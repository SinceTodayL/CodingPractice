#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll p50, p95, p99;
	cin>>p50>>p95>>p99;
	cout<<100<<endl;
	for(int i=1; i<=50; ++i)
	cout<<p50<<" ";
	for(int i=51; i<=95; ++i)
	cout<<p95<<" ";
	for(int i=96; i<=99; ++i)
	cout<<p99<<" ";
	
	cout<<static_cast<int>(1e9);
    return 0;
}

