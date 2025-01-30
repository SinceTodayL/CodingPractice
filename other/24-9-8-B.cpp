#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const string str = "rioi";

bool Check(string a){
	int f = 0;
	int s = 0;
	bool flag = false;
	while(f < a.size()){
		if(a[f] == 'r' || a[f] == 'R'){
            bool sign = true;
			for(int i = 1; i <= 3; ++i){
				f++;
				if(!(a[f] == str[i] || a[f] == str[i] - 32 || a[f] == str[i] + 32)){
					sign = false;
					break;
				}
			}
			if(sign)
			{
				flag = true;
				break;
			}
		continue;   
	}
		f++;
		s = f;
	}
	if(flag)
	    return true;
	else
	    return false;
}

int main()
{
    string a, b;
    cin >> a >> b;
    bool check_a = Check(a);
    bool check_b = Check(b);
    if(check_a && check_b)
        cout << "Either is ok!";
    else if( !check_a && !check_b)
        cout << "Try again!";
    else if(check_a && ! check_b)
        cout << a << " for sure!";
    else
        cout << b << " for sure!";
    return 0;
}

