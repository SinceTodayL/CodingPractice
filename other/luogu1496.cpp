#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int st[20010];
int ed[20010];
int cb[40010];
bool flag[40010];

int main()
{
    cin >> n;
    int cnt = 0;
    for(int i = 0; i < n; ++i){
    	scanf("%d", &st[i]);
    	cb[cnt++] = st[i];
    	scanf("%d", &ed[i]);
    	cb[cnt++] = ed[i];
	}
	sort(cb, cb + cnt);
	for(int i = 0; i < n; ++i){
		st[i] = lower_bound(cb, cb + cnt, st[i]) - cb;
	    ed[i] = lower_bound(cb, cb + cnt, ed[i]) - cb;
	}
	int ans = 0;
	for(int i = 0; i < n; ++i){
		for(int j = st[i]; j < ed[i]; ++j)
		    flag[j] = true;
	}
	for(int i = 0; i < cnt; ++i)
		if(flag[i])
		    ans += cb[i + 1] - cb[i];
	cout<<ans;
    return 0;
}

