#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string a, b;
string am[10], bm[10];
int num = 0;

struct node{
	string ele;
	int step;
	node(const string& element){
		this->ele = element;
		step = 0;
	}
	node(const string& element, int step){
		this->ele = element;
		this->step = step;
	}
};

vector<int> check(string s, string sbs){
	string tmp;
	vector<int> result;
	if(sbs.size()>s.size())
	return result;
	for(int i=0; i<=s.size()-sbs.size(); ++i){
		tmp = s.substr(i, sbs.size());
		if(tmp==sbs)
		    result.push_back(i);
	}
	return result;
}

string change(string s, int pos, int index){
    if (pos < 0 || pos >= s.size() || pos + am[index].size() > s.size()) {
        return s;
    }
    string tmp1 = (pos >= 1 ? s.substr(0, pos) : "");
    string tmp2 = (pos + am[index].size() < s.size() ? s.substr(pos + am[index].size()) : "");
    string res= tmp1 + bm[index] + tmp2;
    
    
    return res;
}

int bfs(){
	deque<node> cur;
	cur.push_back(node(a));
	
	while(!cur.empty()){
		node tmp = cur.front();
		string tmp_str = tmp.ele;
		cur.pop_front();
		
		for(int i=0; i<num; ++i){
			vector<int> result = check(tmp_str, am[i]);
			if(result.size()>0)
			for(int j:result){
				string ss=change(tmp_str,j,i);

				if(ss==b){
					return tmp.step+1;
				}
				else{
					if(tmp.step<=9){
						cur.push_back(node(ss, tmp.step+1));
					}
				}
			}
		}
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>a>>b;

	while(cin>>am[num]>>bm[num]){
		++num;
	}
	
	int res = bfs();
	if(res>=0)
	cout<<res<<endl;
	else
	cout<<"NO ANSWER!"<<endl;
	
    return 0;
}

