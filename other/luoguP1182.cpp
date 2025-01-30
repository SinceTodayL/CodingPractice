#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int M, N;
ll length[100010];
ll sum = 0, max_n = 0;

bool judge(ll x){
	int ptr = 1;
	ll tmp = 0;
	ll cnt = 0;
	while(ptr <= N){
		tmp += length[ptr];
		if(ptr != N && tmp + length[ptr + 1] > x){
			tmp = 0;
			cnt++;
		}
        ptr++; 
	}
    cnt++;
	if(cnt > M)
	    return true;
	else
	    return false;
}

int main()
{
    cin >> N >> M;
    for(int i = 1; i <= N; ++i){
    	scanf("%lld", &length[i]);
    	sum += length[i];
    	max_n = max(max_n, length[i]);
	}
     
    ll left = max_n;
    ll right = sum;
    
    while(left < right){
    	ll mid = left + (right - left)/2;
    	if(judge(mid))
    	    left = mid + 1;
    	else
    	    right = mid;
	}
    
    cout<<left;
    
    return 0;
}

