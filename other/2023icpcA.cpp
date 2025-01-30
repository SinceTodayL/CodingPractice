#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m; 
vector<string> rk1;
vector<string> rk2;
vector<string> rk;

int main()
{
    scanf("%d %d", &n, &m);
    string tmp;
    for(int i = 1; i <= n; ++i){
    	cin >> tmp;
    	if(find(rk1.begin(), rk1.end(), tmp) == rk1.end()){
    		rk1.push_back(tmp);
		}
	}
	
	for(int i = 1; i <= m; ++i){
		cin >> tmp;
		if(find(rk2.begin(), rk2.end(), tmp) == rk2.end()){
			rk2.push_back(tmp);
		} 
    }
	m = rk1.size();
	n = rk2.size();
	
	for(int i = 0; i < min(m, n); i++){
		rk.push_back(rk1[i]);
		rk.push_back(rk2[i]);
	}
	
	if(m > n){
		for(int i = n; i < m; ++i){
			rk.push_back(rk1[i]);
		}
	}
	else{
		for(int i = m; i < n; ++i){
			rk.push_back(rk2[i]);
		}
	}

	unordered_set<string> flag;
	for(int i = 0; i < m + n; ++i){
		if(flag.find(rk[i]) == flag.end()){
			cout << rk[i] << endl;
		}
		flag.insert(rk[i]);
	}
    return 0;
}

