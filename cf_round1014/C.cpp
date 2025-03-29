#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void solve(){
    int n;
    cin >> n;
    vector<int> odd, even;
    int input;
    for(int i = 0; i < n; ++i){
        cin >> input;
        if(input & 1){
            odd.push_back(input);
        }
        else{
            even.push_back(input);
        }
    }
    int odd_size = odd.size();
    int even_size = even.size();
    ll odd_all = 0, even_all = 0;
    sort(odd.begin(), odd.end(), greater<int>());
    sort(even.begin(), even.end(), greater<int>());
    if(odd_size < even_size){
        if(odd_size != 0){
            for(int num : odd){
                odd_all += num;
            }
            for(int num : even){
                even_all += num;
            }
            cout << odd_all + even_all - (odd_size - 1) << endl;
        }
        else{
            cout << even[0] << endl;
        }
    }
    else if(odd_size > even_size){
        if(even_size == 0){
            cout << odd[0] << endl;
        }
        else{
            for(int num : odd){
                odd_all += num;
            }
            for(int num : even){
                even_all += num;
            }
            cout << odd_all + even_all - (odd_size - 1) << endl;
        }
    }
    else{
        for(int num : odd){
            odd_all += num;
        }
        for(int num : even){
            even_all += num;
        }
        cout << odd_all + even_all - (odd_size - 1) << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}