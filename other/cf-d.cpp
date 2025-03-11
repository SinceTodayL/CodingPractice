#include<iostream>

#include<unordered_set>
using namespace std;
typedef long long ll;

unordered_set<int> y1;
unordered_set<int> y0;

ll find(){
	ll ans = 0;
	for(auto ele:y1){
		if(y1.find(ele + 2) != y1.end() && y0.find(ele + 1) != y0.end())
		    ans++;
	}
	for(auto ele:y0){
		if(y0.find(ele + 2) != y0.end() && y1.find(ele + 1) != y1.end())
		    ans++;
	}
	for(auto ele:y1){
		if(y0.find(ele) != y0.end())
		    ans = ans + y1.size() - 1 + y0.size() - 1;
	}
	return ans;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
    	int n;
    	scanf("%d", &n);
    	int x, y;
    	for(int i = 1; i <= n; ++i){
    		scanf("%d %d",&x, &y);
    		if(y)
    		    y1.insert(x);
    		else
    		    y0.insert(x);
		}
		printf("%lld\n", find());
		y1.clear();
		y0.clear();
	}
    return 0;
}

