#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, q, t, input;
	cin>>t;
	while(t--){
		cin>>n>>q;
		vector<int> inver(n + 1);
		for(int i=1; i<=n; ++i){
			cin>>input;
			inver[input] = i;
		}
		
		string record;
		cin>>record;
		record = " "+record;
		
		vector<int> diff(n + 1, 0);
		for(int i=1; i<=n; ++i){
			diff[max(i, inver[i])]--;
			diff[min(i, inver[i])]++;
		}
		for(int i=1; i<=n; ++i)
		    diff[i] += diff[i-1];
		
		set<int> prob;
		for(int i=1; i<n-1; ++i){
			if(record[i]=='L' && record[i+1]=='R' && diff[i] != 0)
			    prob.insert(i);
		}
		
		while(q--){
			cin>>input;
			record[input] = (record[input]=='L')?'R':'L';
			if(record[input]=='L' && record[input + 1]=='R' && diff[input] != 0){
				prob.insert(input);
			}
			else{
				prob.erase(input);
			}
			
			if(record[input-1]=='L' && record[input]=='R' && diff[input - 1] != 0){
				prob.insert(input-1);
			}
			else{
				prob.erase(input-1);
			}
			
			if(prob.empty()){
				cout<<"yes"<<endl;
			}
			else{
				cout<<"no"<<endl;
			}
		}
	}
    return 0;
}

