#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, C;
ll point[100010];

bool judge(ll distance){
    ll tmp = 1, ptr = 1, cnt = 1;
    while(ptr <= N){
    	tmp = ptr;
    	while(ptr <= N && (point[ptr] - point[tmp])<distance)
    	    ptr++;
    	if(ptr <= N)
    	    cnt++;
	}
	if(cnt >= C)
	    return true;
    else
        return false;
}

int main()
{
    cin >> N >> C;
    for(int i = 1; i <= N; i++)
        scanf("%d",&point[i]);
    sort(point+1,point+N+1);
    
    ll left = 1, right = point[N]-point[1];
    while(left < right){
    	int mid = left + (right - left + 1)/2;
    	if(judge(mid))
    	    left = mid;
    	else
    	    right = mid - 1;
	}
	cout<<left;

    return 0;
}

