#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    string a, b, tmp_a, tmp_b;
    cin>>tmp_a>>tmp_b;
    if(tmp_a.size()<tmp_b.size()){
    	a = tmp_b;
    	b = tmp_a;
	}
	else{
		a = tmp_a;
		b = tmp_b;
	}
    int len1 = a.size();
    int len2 = b.size();
    int ptr1 = len1-1;
    int ptr2 = len2-1;
    	vector<int> res(len1+1, 0);
    	bool flag = false;
    	int tmp;
    	while(ptr2>=0){
    		if(flag)
    			tmp = 1;
    		else
    		    tmp = 0;
    		if(tmp + a[ptr1]-'0' + b[ptr2]-'0' > 9){
    			flag = true;
    			tmp = tmp + a[ptr1]-'0' + b[ptr2]-'0' - 10;
			}
			else{
				flag = false;
				tmp = tmp + a[ptr1]-'0' + b[ptr2]-'0';
			}
			res[ptr1+1] = tmp;
			ptr1--;
			ptr2--;
		}
		while(ptr1>=0){
			if(flag)
    			tmp = 1;
    		else
    		    tmp = 0;
    		if(tmp + a[ptr1]-'0' > 9){
    			flag = true;
    			tmp = tmp + a[ptr1]-'0' - 10;
			}
			else{
				flag = false;
				tmp = tmp + a[ptr1]-'0';
			}
			res[ptr1+1] = tmp;
			ptr1--;
		}
		if(flag)
			res[0] = 1;
		else
		    res.erase(res.begin());
		    
		for(int i = 0; i < res.size(); ++i)
		    cout<<res[i];
    return 0;
}

