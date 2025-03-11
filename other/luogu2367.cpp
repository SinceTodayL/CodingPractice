#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, p;
ll sscore[5000010];
ll score[5000010];
int main()
{
    cin >> n >> p;
    for(int i = 1; i <= n; ++i){
    	scanf("%lld", &sscore[i]);
	}
	for(int i = 1; i <= n; ++i){
		score[i] = sscore[i] - sscore[i-1];
	}
	int x, y, z;
	while(p--){
		scanf("%d %d %d", &x, &y, &z);
		score[x] += z;
		score[y + 1] -= z;
	}
	ll min_score = INT_MAX;
	for(int i = 1; i <= n; ++i){
		score[i] = score[i] + score[i-1];
		min_score = min(min_score, score[i]);
	}
	cout<<min_score;
    return 0;
}

