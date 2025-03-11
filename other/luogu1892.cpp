#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2000;
int n, m;
int bing[N*2];
/*
int val[N];

void init(){
	for(int i = 1; i <= N; ++i){
		bing[i] = i;
		val[i] = 1;
	}
}

int _find(int x){
	if(x != bing[x]){
		int tmp = bing[x];
		bing[x] = find(bing[x]);
		val[x] *= val[tmp];
	}
	return bing[x];
}

void _merge(int x, int y, int flag){
	int rootx = find(x);
    int rooty = find(y);
    bing[rootx] = bing[rooty];
	if((flag*val[x]*val[y]) == -1)
	    val[rootx] = -val[rootx];
}

int main()
{
    cin >> n >> m;
    init();
    int a, b;
    char c;
    while(m--){
    	getchar();
    	scanf("%c %d %d", &c, &a, &b);
    	if(c == 'F')
    	    merge(a, b, 1);
    	else
    	    merge(a, b, -1);
    	for(int i = 1; i <= n; ++i)
    	    cout << bing[i] << ' ';
    	cout << endl;
    	for(int i = 1; i <= n; ++i)
    	    cout << val[i] << ' ';
		cout << endl; 
	}
	
	for(int i = 1; i <= n; ++i)
	    find(i);
	    
	map<int, pair<int, int>> res;
	for(int i = 1; i <= n; ++i){
		if(val[i] == -1)
		    res[bing[i]].second++;
		else
		    res[bing[i]].first++;
	}
	int ans = 0;
	for(auto ele : res){
		if(ele.second.second)
		    ans += 2;
		else
		    ans += 1;
	}
	for(int i = 1; i <= n; ++i)
    	    cout << bing[i] << ' ';
    	cout << endl;
    	for(int i = 1; i <= n; ++i)
    	    cout << val[i] << ' ';
		cout << endl; 
	cout << ans;
    return 0;
}
*/

int eum[N];
int find(int x){
	if(x != bing[x]){
		bing[x] = find(bing[x]);
	}
	return bing[x];
}
void merge(int x, int y){
	int rootx = find(x);
	int rooty = find(y);
	bing[rootx] = rooty;
}

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= 2*n; ++i)
	    bing[i] = i;
	int a, b;
    char c;
    while(m--){
    	getchar();
    	scanf(" %c %d %d", &c, &a, &b);
    	if(c == 'F'){
    		merge(a, b);
		}
    	else{
    		if(eum[a] == 0)
    		    eum[a] = b;
    		else
    		    merge(eum[a], b);
    		if(eum[b] == 0)
    		    eum[b] = a;
    		else
    		    merge(eum[b], a);
		}
    }
	int cnt = 0;
	for(int i = 1; i <= n; ++i)
	    if(bing[i] == i)
		    cnt++;  
    cout<<cnt;
	return 0;
}
