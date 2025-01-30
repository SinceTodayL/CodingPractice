#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node{
	int a, b;
	node(int x, int y){
		this->a = x;
		this->b = y;
	}
};
bool cmp(node n1, node n2){
	if(max(n1.a, n1.b) != max(n2.a, n2.b))
	return max(n1.a, n1.b) < max(n2.a, n2.b);
	else
	return min(n1.a, n1.b) < min(n2.a, n2.b);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		vector<node> st;
		int n; int tmpa, tmpb;
		cin>>n;
		for(int i=0; i<n; ++i){
			cin>>tmpa>>tmpb;
			st.push_back(node(tmpa, tmpb));
		}
		sort(st.begin(), st.end(), cmp);
		for(int i=0; i<n; ++i){
			cout<<st[i].a<<" "<<st[i].b<<" ";
		}
		cout<<endl;
	}
    return 0;
}

