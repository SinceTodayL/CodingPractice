#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string s1; 
stack<int> kh;
unordered_map<int, int> res;
void print(int st, int ed){
	int num, tmp=st;
	if(s1[st+1]<='9' && s1[st+1]>='0'){
		num=(s1[st]-'0')*10 + s1[st+1]-'0';
		tmp+=2;
	}
	else{
		num=(s1[st]-'0');
		tmp+=1;
	}
	while(num--){
		int i=tmp;
		while(i<=ed){
		    if(s1[i]!='[' && s1[i]!=']')
			    cout<<s1[i++];
			else if(s1[i]=='['){
			    print(i+1,res[i]-1);
		    	i+=(res[i]-i);
		   }
		    else
		        i++;
		}
	}
}

int main()
{
    cin>>s1;
    int num=0, tmp;
    for(int i=0; i<s1.size(); ++i){
    	if(s1[i]=='['){
    		kh.push(i);
		}
		if(s1[i]==']'){
			tmp=kh.top();
			res[tmp]=i;
			kh.pop();
		}
	}
    for(int i=0; i<s1.size();++i){
    	if(s1[i]!='[' && s1[i]!=']')
    	    cout<<s1[i];
    	else if(s1[i]=='['){
    		print(i+1,res[i]-1);
    		i+=(res[i]-i);
		}
	}
    return 0;
}

