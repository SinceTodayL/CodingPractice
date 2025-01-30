#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int n, m, k, w, input;
	cin>>n>>m>>k>>w;
	
	vector<int> red(n, 0);
	vector<int> black(m, 0);
	for(int i=0; i<n; ++i){
		cin>>red[i]; 
	}
	sort(red.begin(), red.end());
	for(int i=0; i<m; ++i){
		cin>>black[i];
	}
	sort(black.begin(), black.end());
	
	int redptr=0;
	vector<vector<int>> interval;
	
    vector<int> tmp;
	while(red[redptr]<black[0] && redptr<n){
		tmp.push_back(red[redptr++]);
	}
	interval.push_back(tmp);
	tmp.clear();
	for(int i=1; i<m; ++i){
		while(redptr<n&&red[redptr]<black[i]){
			tmp.push_back(red[redptr++]); 
		}
		interval.push_back(tmp);
		tmp.clear();
	}
	while(redptr<n){
		tmp.push_back(red[redptr++]);
	}
	interval.push_back(tmp);
	
	
	ll ans = 0;
	int bg, ed;
	vector<int> ans_pos;
    for(int i=0; i<m+1; ++i){	
        tmp = interval[i];
    	if(tmp.empty())
    	    continue;
    	    
    	if(i==0){
    		bg = 0; ed = black[0];
		}
		else if(i==m){
			bg = black[m-1]; ed=w+1;
		}
		else{
			bg = black[i-1]; ed=black[i];  // ±ß½ç²»ÄÜ´¥Åö 
		}
		
		/*
		cout<<"size: "<<endl;
		for(auto ele:interval){
			cout<<ele.size()<<" ";
		}
		*/
		
		int left_room = 0, ptr = 0, cur_ed = 0, exceed = 0;
		left_room += (tmp[0]-bg-1);
		vector<int> room;
		room.push_back(tmp[0]-bg-1);
		vector<int> tmpans;
		
		while(ptr < tmp.size()){
			cur_ed = tmp[ptr]+k-1;
			ans++;
			tmpans.push_back(tmp[ptr]);
			while(ptr < tmp.size() && tmp[ptr]<=cur_ed){
				ptr++;
			}
			if(cur_ed >= ed){
				exceed = cur_ed-ed+1;
				break;
			}
			room.push_back(ptr<tmp.size()?tmp[ptr]-cur_ed-1:ed-cur_ed-1);
			left_room += (ptr<tmp.size()?tmp[ptr]-cur_ed-1:ed-cur_ed-1);
		}
		
		/*
		cout<<"exceed and left_room:";
		cout<<exceed<<" "<<left_room<<endl;
		*/
		
		if(exceed > left_room){
			cout<<"-1"<<endl;
			return;
		}
		if(exceed != 0){
		
		    tmpans[tmpans.size()-1]-=exceed;
	      
	    	for(int i=tmpans.size()-2; i>=0; --i){
	    		exceed -= room[i+1];
	    		if(exceed<=0)
	    		    break;
			    tmpans[i]-=exceed;
	     	}
        } 
        
        for(int ele:tmpans){
        	ans_pos.push_back(ele);
		}
	}
	
	cout<<ans<<endl;
	for(int ele:ans_pos){
		cout<<ele<<" ";
	}
	cout<<endl;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
    return 0;
}

