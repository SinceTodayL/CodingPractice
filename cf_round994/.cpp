#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[100];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t, n, count;
	cin >> t;
	while(t--){
		cin >> n;
		count = 0;
		for(int i = 1; i <= n; ++i){
			cin >> a[i];
		}
		for(int i = 0; i < n; ++i){
			if(a[i] == 0 && a[i+1] != 0){
				count++;
			}
		}
		
		if(count == 0){
			cout << 0 << endl;
		}
		else if(count == 1){
			cout << 1 << endl;
		}
		else if(count >= 2){
			cout << 2 << endl;
		}
	} 
    return 0;
}

