#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, all = 0;
struct node{
	int st, ed, jo;
}a[5010];
int c[10010];
int bing[20010];

int find(int x){
	return x==bing[x]? x: bing[x]=find(bing[x]);
}

void merge(int x, int y){
	int xx=find(x);
	int yy=find(y);
	bing[xx]=bing[yy];
}

void init(){
	for(int i=1; i<=2*all; ++i){
		bing[i]=i;
	}
}

int main(){
	cin>>n>>m;
	string tmp;
	for(int i=1; i<=m; ++i){
		cin>>a[i].st>>a[i].ed>>tmp;
		a[i].st--; 
		c[++all]=a[i].st;
		c[++all]=a[i].ed;
		if(tmp=="even")
		    a[i].jo=1;
		else
		    a[i].jo=0;
	}
	sort(c+1, c+all+1);
	all=unique(c+1,c+all+1)-c-1;
	for(int i=1; i<=m; ++i){
		a[i].st=upper_bound(c+1, c+all+1, a[i].st)-c;
		a[i].ed=upper_bound(c+1, c+all+1, a[i].ed)-c;
	}
	init();
	for(int i=1; i<=m; ++i){
		if(a[i].jo){
			if(find(a[i].st)==find(a[i].ed+all)){
				cout<<i-1;
				return 0;
			}
			else{
				merge(a[i].st, a[i].ed);
				merge(a[i].st+all, a[i].ed+all);
			}
		}
		else{
			if(find(a[i].st)==find(a[i].ed)){
				cout<<i-1;
				return 0;
			}
			else{
				merge(a[i].st, a[i].ed+all);
				merge(a[i].ed, a[i].st+all);
			}
		}
	}

	cout<<m;
	return 0;
}
