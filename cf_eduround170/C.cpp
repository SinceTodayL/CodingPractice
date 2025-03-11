#include<bits/stdc++.h>
using namespace std;
#define int long long

struct node{
	int key, value;
	node(int x, int y){
		key = x;
		value = y;
	}
};
bool cmp(node a, node b){
	return a.key<b.key;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    map<int, int> mp;
    vector<node> vec;
    
    while (t--) {
        mp.clear();
        vec.clear();
        int n, k, tmp;
        cin >> n >> k;

        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            mp[tmp]++;
        }

        for(auto ele:mp){
        	vec.push_back(node(ele.first, ele.second));
	    }
		
		sort(vec.begin(), vec.end(), cmp);
		
		
		
		int fp = 1, bp = 0, last = vec[0].value, ans = last;
		
		while(fp<vec.size()){
		    
		    while(fp<vec.size() && vec[fp].key - vec[fp-1].key == 1 && fp-bp<k){
		    	last += vec[fp++].value;
			}
		
	    	ans = max(ans, last);
		
		    if(fp-bp == k){
		    	last -= vec[bp].value;
		    	bp++;
			}
			
			else if(fp>=vec.size()){
				break;
			}
			
			else{
				bp = fp;
				fp++;
				last = vec[bp].value;
			}
			ans = max(ans, last);
			
		}


        cout << ans << endl;
    }

    return 0;
}

