#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int L, N;
int pos[5010];
int m[5010];

int main()
{
    cin>>L>>N;
    for(int i=1; i<=N; ++i){
    	cin>>pos[i];
	}
	int Min = 0;
	for(int i = 1; i <= N; ++i){
		Min = max(Min, min(pos[i], L+1-pos[i]));
	}
	sort(pos+1, pos+N+1);
	int max_ = L+1-pos[1];
	cout<<Min<<" "<<max_;
    return 0;
}

