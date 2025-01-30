#include<bits/stdc++.h>
using namespace std;

int s[5], min_time[5];
int times[21];
int time1 = 0, time2 = 0, tmp, res = 0;

void dfs(int i, int k)
{
	if(k > s[i])
	    return;
	    
	dfs(i, k+1);
	tmp = max(time1, time2);
	min_time[i] = min(min_time[i], tmp);
	
	time1 -= times[k];
	time2 += times[k];
	dfs(i, k+1);
	tmp = max(time1, time2);
	min_time[i] = min(min_time[i], tmp);
	time1 += times[k];
	time2 -= times[k];
}

int main()
{
	cin>>s[1]>>s[2]>>s[3]>>s[4];
	for(int i = 1; i <= 4; ++i)
	{
		time1 = 0;
		time2 = 0;
		min_time[i] = INT_MAX;
		for(int j = 1; j <= s[i]; ++j)
		{
			scanf("%d", &times[j]);
			time1 += times[j];
		}
        dfs(i, 1);
        res += min_time[i];
    }
    cout<<res;
    return 0;
}

