#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

double a[4];
int cal(double x){
	double tmp = 1;
	double res = a[3];
	for(int i = 1; i <= 3; ++i){
		tmp *= x;
		res += tmp*a[3-i];
	}
	if(res < -1e-6)
	    return -1;
	else if(res > 1e-6)
	    return 1;
	else
	    return 0;
}

int main()
{
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    
    vector<pair<int, int>> sol;
    vector<double> res;
    int x = -101;
    double tmp2 = cal(x);
    double tmp1;
    for(x = -100; x <= 100; ++x){
    	tmp1 = tmp2;
        tmp2 = cal(x);
        if(fabs(tmp2) < 1e-6){
        	res.push_back(x);
        	continue;
		}
        else if(tmp1*tmp2 < -1e-6)
            sol.push_back(make_pair(x-1,x));
	}
	if(res.size() == 3){
		for(double ele:res){
			cout << fixed <<setprecision(2) << ele << ' ';
		}
	}
	else{
		for(pair<int, int> p : sol){
			double l = p.first;
			double r = p.second;
			while(fabs(r-l)>1e-6){
				double mid = (l + r) / 2;
				double tmpvalue = cal(mid);
				if(tmpvalue*cal(r) > 1e-6)
				    r = mid;
				else
				    l = mid;
			}
			res.push_back(l);
		}
		sort(res.begin(), res.end());
		for(double ele:res){
			cout << fixed <<setprecision(2) << ele << ' ';
		}
	}
    return 0;
}

