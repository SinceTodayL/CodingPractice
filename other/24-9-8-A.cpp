#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int q[5][5];

bool Check(){
	int cnt = 0;
	for(int i = 0; i < 5; ++i){
		bool flag = true;
		for(int j = 0; j < 5; ++j){
			if(!q[i][j])
			    flag = false;
		}
		if(flag)
		    cnt++;
	}
	for(int i = 0; i < 5; ++i){
		bool flag = true;
		for(int j = 0; j < 5; ++j){
			if(!q[j][i])
			    flag = false;
		}
		if(flag)
		    cnt++;
	}
	bool flag = true;
	for(int i = 0; i < 5; ++i){
		if(!q[i][i])
		    flag = false;
	}
	if(flag)
	    cnt++;
    flag = true;
	for(int i = 0; i < 5; ++i){
		if(!q[i][4-i])
		    flag = false;
	}
	if(flag)
	    cnt++;
	if(cnt >= 1)
        return true;
    else
        return false;
}

int main()
{
    for(int i = 0; i < 5; ++i)
	    for(int j = 0; j < 5; ++j)
		    scanf("%d", &q[i][j]); 
	bool res = Check();
	if(res)
	    cout << "Yes";
	else
	    cout << "No";
    return 0;
}

