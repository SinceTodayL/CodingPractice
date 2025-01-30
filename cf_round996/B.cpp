#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    int nums = 0;
    int max_ele = INT_MIN;
    int min_ele = INT_MAX;
    for(int i = 0; i < n; ++i){
        a[i] -= b[i];
        if(a[i] < 0){
            nums++;
            max_ele = max(max_ele, a[i]);
        }
        else{
            min_ele = min(min_ele, a[i]);
        }
    }
    if(nums > 1){
        cout << "NO" << endl;
    }
    else{
        if(-max_ele > min_ele){
            cout << "No" << endl;
        }
        else{
            cout << "Yes" << endl;
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}