#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
int pfa[26][200010][50];
int pfb[26][200010][50];
int lasta[26][5000];
int lastb[26][5000];
bool flaga[26][5000];
bool flagb[26][5000];


int check(int l, int r, int s){
	int ans = 0;
	for(int i=0; i<26; ++i){
		if(!flaga[i][s]) continue;
		int ll=l-1;
		while(ll>=0 && pfa[i][ll][s]==0){
			ll--;
		}
		pfa[i][l-1][s]=pfa[i][ll][s];
		int rr = r;
		while(rr>=0 && pfa[i][rr][s]==0){
			rr--;
		}
		pfa[i][r][s]=pfa[i][rr][s];
	}
	for(int i=0; i<26; ++i){
		if(!flagb[i][s]) continue;
		int ll=l-1;
		while(ll>=0 && pfb[i][ll][s]==0){
			ll--;
		}
		pfb[i][l-1][s]=pfb[i][ll][s];
		int rr = r;
		while(rr>=0 && pfb[i][rr][s]==0){
			rr--;
		}
		pfb[i][r][s]=pfb[i][rr][s];
	}
	for(int i=0; i<26; ++i){
		ans+=min(pfa[i][r][s]-pfa[i][l-1][s], pfb[i][r][s]-pfb[i][l-1][s]);
	}
	return ans;
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int s=0; s<t; ++s){
    	int len, q, l, r;
    	string a, b;
    	scanf("%d%d",&len, &q);
    	cin>>a;
    	cin>>b;
    	for(int i=1; i<=len; ++i){
    		pfa[a[i-1]-'a'][i][s] = pfa[a[i-1]-'a'][lasta[a[i-1]-'a'][s]][s] + 1;
    		lasta[a[i-1]-'a'][s]=i;
    		flaga[a[i-1]-'a'][s]=true;
		}
		
		for(int i=1; i<=len; ++i){
    		pfb[b[i-1]-'a'][i][s] = pfb[b[i-1]-'a'][lastb[b[i-1]-'a'][s]][s] + 1;
    		lastb[b[i-1]-'a'][s]=i;
    		flagb[b[i-1]-'a'][s]=true;
		}
		
		while(q--){
			scanf("%d%d",&l, &r);
			
			printf("%d\n", r-l+1-check(l, r, s));
		}
	}
    return 0;
}
*/
int l, r, len, q;
string a, b;
void solve(){
	scanf("%d %d", &len,&q);
	char tmp;
	
	vector<vector<int>> pre1(len+1, vector<int>(26, 0));
	vector<vector<int>> pre2(len+1, vector<int>(26, 0));
	for(int i=1; i<=len; ++i){
		cin>>tmp;
		pre1[i][tmp-'a']++;
		for(int j=0; j<=25; j++){
			pre1[i][j] += pre1[i-1][j];
		}
	}
	for(int i=1; i<=len; ++i){
		cin>>tmp;
		pre2[i][tmp-'a']++;
		for(int j=0; j<=25; j++){
			pre2[i][j] += pre2[i-1][j];
		}
	}
	while(q--){
	scanf("%d %d", &l, &r);
	int ans=0;
	
	for(int i=0; i<26; ++i){
		ans += min(pre1[r][i]-pre1[l-1][i], pre2[r][i] - pre2[l-1][i]);
	}
	printf("%d\n", r-l+1-ans);
}
}
		
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		solve();
	}
	return 0;
}
