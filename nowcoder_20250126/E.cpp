#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
vector<double> pos;
vector<double> neg;
vector<int> before_neg;

int check(double t){
    int ans = 0;
    for(int i = 0; i < neg.size(); ++i){
        ans += (before_neg[i] - (lower_bound(pos.begin(), pos.end(), neg[i] - 2 * t) - pos.begin()));
    }
    return ans;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    double p, v;
    vector<double> res;
    for(int i = 1; i <= n; ++i){
        cin >> p >> v;
        if(v == 1){
            pos.push_back(p);
        }
        else{
            neg.push_back(p);
        }
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    before_neg.resize(neg.size());
    ll prefix = 0;
    for(int i = 0; i < neg.size(); ++i){
        before_neg[i] = upper_bound(pos.begin(), pos.end(), neg[i]) - pos.begin();
        prefix += before_neg[i];
    }

    if(k > prefix){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;

    double l = 0, r = 1e9, mid;
    while(fabs(l - r) > 1e-7){
        mid = (l + r) / 2;
        if(check(mid) < k){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    
    printf("%.6f\n", l);
    return 0;
}