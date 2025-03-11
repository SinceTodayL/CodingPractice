#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5010;
int relatives[N];
int n, m, p;

void init(){
	for(int i = 1; i <= N; ++i)
	    relatives[i] = i;
}

int find(int x){
	if(x != relatives[x])
	    relatives[x] = find(relatives[x]);
	return relatives[x];
}

void merge(int x, int y){
	x = find(x);
	y = find(y);
	relatives[x] = relatives[y];
}

int main()
{
    cin >> n >> m >> p;
    init();
    int a, b;
    while(m--){
    	scanf("%d %d", &a, &b);
    	merge(a, b);
	}
    while(p--){
    	scanf("%d %d", &a, &b);
    	if(find(a) == find(b))
    	    printf("Yes\n");
    	else
    	    printf("No\n");
	}

    return 0;
}

