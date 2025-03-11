#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

char a[10100][10100];
int n, k;

void print(){
	for(int i=0; i<n; i+=k){
		for(int j=0; j<n; j+=k){
			printf("%c",a[i][j]);
		}
		printf("\n");
	}
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
    	scanf("%d%d", &n, &k);
    	getchar();
    	for(int i=0; i<n; ++i){
    	    for(int j=0; j<n; ++j)
    	        scanf("%c", &a[i][j]);
    	    getchar();
    	}
    	print();
	} 
    return 0;
}

