#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

stack<int> num;  // false 0; true 1
stack<int> nta; // not 1; and 2; or 3 
int or_num = 0;

int main()
{
    string tmp;
    bool flag = true;
    while(cin >> tmp && flag){
    	if(tmp == "not"){
    		nta.push(1); 
    		continue;
		}
    	else if(tmp == "and"){
    		nta.push(2);
		}
		else if(tmp == "or"){
			nta.push(3);
			or_num++;
			continue;
		}
		else if(tmp == "false"){
			next2:
			if(!nta.empty() && nta.top() == 1){
				nta.pop();
				goto next1;
			}
			if(num.empty()){
				num.push(0);
				continue;
			}
			if(!num.empty() && nta.empty()){
				flag = false;
				break;
			}
			if(nta.top() == 2){
				if(num.empty()){
					flag = false;
					break;
				}
				num.top() = 0;
				nta.pop();
			}
			else{
				num.push(0);
			}
		}
		else if(tmp == "true"){
			next1:
			if(!nta.empty() && nta.top() == 1){
				nta.pop();
				goto next2;
			}
			if(num.empty()){
				num.push(1);
				continue;
			}
			if(!num.empty() && nta.empty()){
				flag = false;
				break;
			}

			else if(nta.top() == 2){
				if(num.empty()){
					flag = false;
					break;
				}
				num.top() = (num.top() == 1?1:0);
				nta.pop();
			}
			else{
				num.push(1);
			}
		}
	if(num.size() != or_num + 1){
		flag = false;
		break;
	}
	}
	if(num.size() != nta.size() + 1){
		flag = false;
	}
	bool f = false;
	while(!num.empty()){
		int ele = num.top();
		num.pop();
		if(ele){
			f = true;
			break;
		}
	}
	if(f&&flag)
	    cout << "true";
	else if(!f&&flag)
	    cout << "false";
	else
	    cout << "error";
    return 0;
}

